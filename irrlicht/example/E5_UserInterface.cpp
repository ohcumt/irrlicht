



//#define _test_E5_userInterface_
#ifndef _test_E5_userInterface_

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


// hold some context for the event 
// so that we can process it in onEvent() method
struct SAppContext
{
	IrrlichtDevice *device;
	s32             connter;
	IGUIListBox    *listBox;
};


enum 
{
		GUI_ID_QUIT_BUTTON = 101,
		GUI_ID_NEW_WINDOW_BUTTON,
		GUI_ID_FILE_OPEN_BUTTON,
		GUI_ID_TRANSPARENCY_SCROLL_BAR
};


// set the skin transparency by change the alpha values 
void setSkinTransparency(s32 alpha, irr::gui::IGUISkin *skin) 
{
	for (s32 i=0; i<irr::gui::EGDC_COUNT; ++i) 
	{
		video::SColor col = skin->getColor((EGUI_DEFAULT_COLOR)i);
		col.setAlpha(alpha);
		skin->setColor((EGUI_DEFAULT_COLOR)i, col);
	}
}


#endif // end _test_E5_userInterface_









