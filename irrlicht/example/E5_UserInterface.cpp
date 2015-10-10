



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
		GUI_ID_FILE_OPEN_BUTTON
};




#endif // end _test_E5_userInterface_









