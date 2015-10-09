

//#define __test_movement__
#ifndef __test_movement__

#include <irrlicht.h>
#include "../src/os.h"

using namespace irr;

class CEventReceive : public IEventReceiver 
{	
public:
	
	// this event we have to implement 
	virtual bool OnEvent(const SEvent& event)
	{
		// remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT) 
		{
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		}

		return false;
	}

	void reset() 
	{
		for (u32 i=0; i<=KEY_KEY_CODES_COUNT; ++i)
		{
			KeyIsDown[i] = false;
		}
	}



	// this is used to check whether a key is being held down 
	virtual bool IsKeyDown( EKEY_CODE keyCode ) const 
	{
		return KeyIsDown[keyCode];
	}

	CEventReceive() 
	{
		for (u32 i=0; i<=KEY_KEY_CODES_COUNT; ++i)
		{
			KeyIsDown[i] = false;
		}
	}

private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


int main() 
{
	// ask for driver 
	video::E_DRIVER_TYPE driverType = video::EDT_DIRECT3D9;

	// create device 
	CEventReceive receiver;

	IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

	if ( device==0 )
	{
		return 1;
	}

	video::IVideoDriver *driver = device->getVideoDriver();
	scene::ISceneManager *smgr  = device->getSceneManager();

	// 在场景中增加一个球形结点
	scene::ISceneNode *sphereNode = smgr->addSphereSceneNode();
	if (sphereNode)
	{
		sphereNode->setPosition(core::vector3df(0, 0, 30));
		sphereNode->setMaterialTexture(0, driver->getTexture("../media/wall.bmp"));
		sphereNode->setMaterialFlag(video::EMF_LIGHTING, false);
	}

	// 在场景中增加一个立方体结点
	scene::ISceneNode *cubeNode = smgr->addCubeSceneNode();
	if (cubeNode)
	{
		cubeNode->setPosition(core::vector3df(10, 0, 30));
		cubeNode->setMaterialTexture(0, driver->getTexture("../media/t351sml.jpg"));
		cubeNode->setMaterialFlag(video::EMF_LIGHTING, false);

		/**
		scene::ISceneNodeAnimator *anim = smgr->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
		if (anim)
		{
			cubeNode->addAnimator(anim);
			anim->drop();
		} **/
	}

	scene::IAnimatedMeshSceneNode *anms = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../media/ninja.b3d"));
	if (anms)
	{
		scene::ISceneNodeAnimator *anim = smgr->createFlyStraightAnimator(core::vector3df(100,0,60),  core::vector3df(-100,0,60), 3500, true);
		if (anim)
		{
			anms->addAnimator(anim);
			anim->drop();
		}
		anms->setMaterialFlag(video::EMF_LIGHTING, false);
		anms->setFrameLoop(0, 13);
		anms->setAnimationSpeed(15);
		anms->setScale(core::vector3df(2.f, 2.f, 2.f));
		anms->setRotation(core::vector3df(0, -90, 0));
	}

	smgr->addCameraSceneNodeFPS();
	device->getCursorControl()->setVisible(true);

	device->getGUIEnvironment()->addImage( driver->getTexture("../media/irrlichtlogoalpha2.tga"), core::position2d<s32>(10,20));

	gui::IGUIStaticText* diagnostics = device->getGUIEnvironment()->addStaticText(L"", core::rect<s32>(10, 10, 400, 20));
	diagnostics->setOverrideColor(video::SColor(255, 255, 255, 0));

	// draw it 
	int lastFPS = -1;
	u32 then = device->getTimer()->getTime();

	// move speed in units per second
	const f32 move_spead = 5.f;

	while (device->run())
	{
		const u32 now = device->getTimer()->getTime();

		c8 text1[1024] = {0};
		c8 text2[1024] = {0};

		sprintf(text1, "frameDeltaTime time is %d", now);
		os::Printer::print(text1);

		sprintf(text2, "then time is %d", then);
		os::Printer::print(text2);


		const f32 frameDeltaTime = ((f32)(now - then))/1000;
		then = now;



		core::vector3df nodePosition = sphereNode->getPosition();

		c8 text[1024] = {0};
		
		

		if (receiver.IsKeyDown(irr::KEY_KEY_W))
		{
			sprintf(text, "%s, %d", "w key is down", frameDeltaTime);
			os::Printer::print(text);
			nodePosition.Y += move_spead*frameDeltaTime;
		}
		else if (receiver.IsKeyDown(irr::KEY_KEY_S)) 
		{
			sprintf(text, "%s, %d", "s key is down", frameDeltaTime);
			os::Printer::print(text);
			nodePosition.Y -= move_spead*frameDeltaTime;
		}

		if (receiver.IsKeyDown(irr::KEY_KEY_A)) 
		{
			sprintf(text, "%s, %d", "a key is down", frameDeltaTime);
			os::Printer::print(text);
			nodePosition.X -= move_spead*frameDeltaTime;
		}
		else if (receiver.IsKeyDown(irr::KEY_KEY_D)) 
		{
			sprintf(text, "%s, %d", "d key is down", frameDeltaTime);
			os::Printer::print(text);
			nodePosition.X += move_spead*frameDeltaTime;
		}

		sphereNode->setPosition(nodePosition);

		driver->beginScene(true, true, video::SColor(255,113,113,133));


		smgr->drawAll();

		device->getGUIEnvironment()->drawAll();
		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS!=fps) 
		{
			core::stringw tmp(L"Movement Example - Irrlicht Engine [");
			tmp += driver->getName();
			tmp += L"] fps: ";
			tmp += fps;

			device->setWindowCaption(tmp.c_str());
			lastFPS = fps;
		}

	}

	device->drop();

	return 0;

	 
}





#endif // end __test_movement__




