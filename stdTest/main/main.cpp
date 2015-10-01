


#ifndef __MAIN_TEST_H__


#ifndef __MAIN_H__
#define __MAIN_H__

#include <Windows.h>
#include <iostream>

using namespace std;

// Callback for Windows
/*
CTRL_C_EVENT - 当用户按下了CTRL+C,或者由GenerateConsoleCtrlEvent API发出. 
CTRL_BREAK_EVENT - 用户按下CTRL+BREAK, 或者由GenerateConsoleCtrlEvent API发出.
CTRL_CLOSE_EVENT - 当试图关闭控制台程序，系统发送关闭消息。
CTRL_LOGOFF_EVENT - 用户退出时，但是不能决定是哪个用户. 
CTRL_SHUTDOWN_EVENT - 当系统被关闭时. 
*/
BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
	switch(CEvent)
	{
	case CTRL_C_EVENT:
		cout << "Closing console device,CTRL+C." << endl;
		break;
	case CTRL_BREAK_EVENT:
		cout << "Closing console device,CTRL+Break." << endl;
		break;
	case CTRL_CLOSE_EVENT:
		cout << "Closing console device,User closed console." << endl;
		break;
	case CTRL_LOGOFF_EVENT:
		cout << "Closing console device,User is logging off." << endl;
		break;
	case CTRL_SHUTDOWN_EVENT:
		cout << "Closing console device,Computer shutting down." << endl;
		break;
	}

	// 如果返回false,则继续处理下一个钩子
	// 如果返回true,则表示该消息处理完毕,不执行下一个钩子
	return TRUE;
}

int main() 
{
	// 获取标准输出句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// 设置控制台文本属性
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// 设置控制台颜色, 颜色可以混合，遵循配色原理
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "This text is yellow." << endl;


	COORD ConsoleSize = {640, 20};
	SetConsoleScreenBufferSize(hOut, ConsoleSize);

	// 第二个参数:BOOL Add // 表示添加还是删除
	// 个
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);

	//用于测试,在5秒期间,关闭控制台会有ConsoleHandler的回调
	Sleep(50000);


	return 0;
}




#endif
#endif




