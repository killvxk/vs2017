// EventDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <windows.h>

/*
ResetEvent:重置事件。将事件重置为非激活状态。所以，调用此接口后，WaitForSingleObject会一直等待。
SetEvent：设置事件，将事件设置为激活状态。所以，调用此接口后，WaitForSingleObject会直接运行。
WaitForSingleObject：等待对象处于激活状态。
*/

using namespace std;

HANDLE		g_hEvent1;
HANDLE		g_hEvent2;

void proc1()
{
	for (int i = 0; i < 100; i++)
	{
		WaitForSingleObject(g_hEvent1, 1000);
		ResetEvent(g_hEvent1);
		cout << "proc1--------------1\n";
		cout << "proc1--------------2\n";
		cout << "proc1--------------3\n";
		cout << "proc1--------------4\n";
		cout << "proc1--------------5\n";
		ResetEvent(g_hEvent1);
		SetEvent(g_hEvent2);
	}
}

void proc2()
{
	for (int i = 0; i < 100; i++)
	{
		WaitForSingleObject(g_hEvent2, INFINITE);
		ResetEvent(g_hEvent1);
		cout << "proc2+++++1\n";
		cout << "proc2+++++2\n";
		cout << "proc2+++++3\n";
		cout << "proc2+++++4\n";
		cout << "proc2+++++5\n";
		ResetEvent(g_hEvent2);
		SetEvent(g_hEvent1);
	}
}

int main() 
{
	thread *th1;
	thread *th2;

	g_hEvent1 = CreateEvent(NULL, TRUE, FALSE, L"EventDemo----1");
	g_hEvent2 = CreateEvent(NULL, TRUE, FALSE, L"EventDemo----2");
	if ( NULL == g_hEvent1 || NULL == g_hEvent2 )
	{
		return GetLastError();
	}
	SetEvent(g_hEvent1);

	th1 = new thread(proc1);
	th2 = new thread(proc2);

	th1->join(); // 等待线程结束，detech要慎用。
	th2->join();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
