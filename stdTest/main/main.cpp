


#ifndef __MAIN_TEST_H__


#ifndef __MAIN_H__
#define __MAIN_H__

#include <Windows.h>
#include <iostream>

using namespace std;

// Callback for Windows
/*
CTRL_C_EVENT - ���û�������CTRL+C,������GenerateConsoleCtrlEvent API����. 
CTRL_BREAK_EVENT - �û�����CTRL+BREAK, ������GenerateConsoleCtrlEvent API����.
CTRL_CLOSE_EVENT - ����ͼ�رտ���̨����ϵͳ���͹ر���Ϣ��
CTRL_LOGOFF_EVENT - �û��˳�ʱ�����ǲ��ܾ������ĸ��û�. 
CTRL_SHUTDOWN_EVENT - ��ϵͳ���ر�ʱ. 
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

	// �������false,�����������һ������
	// �������true,���ʾ����Ϣ�������,��ִ����һ������
	return TRUE;
}

int main() 
{
	// ��ȡ��׼������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���ÿ���̨�ı�����
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���ÿ���̨��ɫ, ��ɫ���Ի�ϣ���ѭ��ɫԭ��
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "This text is yellow." << endl;


	COORD ConsoleSize = {640, 20};
	SetConsoleScreenBufferSize(hOut, ConsoleSize);

	// �ڶ�������:BOOL Add // ��ʾ��ӻ���ɾ��
	// ��
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);

	//���ڲ���,��5���ڼ�,�رտ���̨����ConsoleHandler�Ļص�
	Sleep(50000);


	return 0;
}




#endif
#endif




