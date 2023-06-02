/*
* бмхлюмхе!!!
* дюммне опнцпюллмне наеяоевемхе
* яндепфхр б яеае бпеднмнямши тсмйжхнмюк
* х опедмюгмювемн хяйкчвхрекэмн б свеамшу жекъу.
* бмхлюмхе!!!
*/
#include <Windows.h>
#include <iostream>
#pragma comment(lib,"Ws2_32.lib")
#include <winsock.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

WNDCLASSW CreateNewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASSW NewWindow = { 0 };
	NewWindow.hCursor = Cursor;
	NewWindow.hIcon = Icon;
	NewWindow.hInstance = hInst;
	NewWindow.lpszClassName = Name;
	NewWindow.hbrBackground = BGColor;
	NewWindow.lpfnWndProc = Procedure;
	return NewWindow;
}


int main() {
	setlocale(LC_ALL, "RUS");

	//оЕПЕДЕКШБЮЕЛ ЙНМЯНКЭ
	HWND hCMD = FindWindowA("ConsoleWindowClass", nullptr);
	SetWindowPos(hCMD, HWND_TOPMOST, 500, 100, 800, 400, NULL);
	//

	//нРЙПШБЮЕЛ ЯНЙЕРШ
	WSADATA ws;
	WSAStartup(MAKEWORD(2, 2), &ws);

	SOCKET sckt;
	sckt = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN scktin;
	memset(&scktin, 0, sizeof(scktin));
	scktin.sin_family = AF_INET;
	scktin.sin_port = htons(7777);

	bind(sckt, (sockaddr*)&scktin, sizeof(scktin));
	listen(sckt, 1);

	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;
	int clientAddrSize = sizeof(clientAddr);
	char buf[255];


	while (clientSocket = accept(sckt, (sockaddr*)&clientAddr, &clientAddrSize)) {
		std::cout << std::endl << "________________Connected________________" << std::endl;

		while (recv(clientSocket, (char*)&buf, sizeof(buf), 0) > 0) {
			std::cout << buf;
		}

		std::cout << std::endl << "________________Disconnected________________" << std::endl;
	}

	return 0;
}