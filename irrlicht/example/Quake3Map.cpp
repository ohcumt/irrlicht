





#ifndef __quake_3_map__

#include <irrlicht.h>
#include <iostream>

using namespace irr;

int main() 
{
	video::E_DRIVER_TYPE driverType[5];
	driverType[0] = video::EDT_OPENGL;
	driverType[1] = video::EDT_DIRECT3D8;
	driverType[2] = video::EDT_DIRECT3D9;
	driverType[3] = video::EDT_BURNINGSVIDEO;
	driverType[4] = video::EDT_OPENGL;

	video::E_DRIVER_TYPE useDriverType = driverType[2];


	// 创建device,如果失败就退出
	IrrlichtDevice *device = createDevice(useDriverType, core::dimension2d<u32>(640, 480));
	if ( 0 == device) 
	{
		return 0;
	}

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr  = device->getSceneManager();

	// 加载 quake3 map
	device->getFileSystem()->addFileArchive("../media/map-20kdm2.pk3");

	// load mesh 
	scene::IAnimatedMesh* mesh = smgr->getMesh("20kdm2.bsp");
	scene::ISceneNode *node = NULL;
	
	if (mesh) 
	{
		node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
	}

	if (node)
	{
		node->setPosition(core::vector3df(-1300, -144, -1249));
	}

	// add camera to look at the quake 3 map 
	smgr->addCameraSceneNodeFPS();

	// hide the mouse cursor 
	device->getCursorControl()->setVisible(false);


	// draw it 
	int lastFPS = -1;

	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, video::SColor(255, 200, 200, 200));	
			smgr->drawAll();
			driver->endScene();

			int fps = driver->getFPS();

			if (fps!=lastFPS)
			{
				core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
				str += driver->getName();
				str += "] FPS:";
				str += fps;
				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
		}
		else 
		{
			device->yield();
		}
	}

	device->drop();
	return 0;
}






#endif







