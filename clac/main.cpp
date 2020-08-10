#include <windows.h>

// �������� ������ ����
char className[] = "Calculator";

// ���������, �������� ���������� � ���������
MSG msg;
HINSTANCE hInst;
//������
HWND hbutton, hedit, hres_edit, buttons2[16];

#define ID_EQUAL_BUTTON			3020
#define ID_PLUS_BUTTON			3021
#define ID_MINUS_BUTTON			3022
#define ID_DIVIDE_BUTTON		3023
#define ID_MULTIPLY_BUTTON	    3024
#define ID_ONE	    	    	3001
#define ID_TWO              	3002
#define ID_THREE        	    3003
#define ID_FOUR	                3004
#define ID_FIVE	                3005
#define ID_SIX	                3006
#define ID_SEVEN	            3007
#define ID_EIGHT	            3008
#define ID_NINE	                3009
#define ID_ZERO	                3000
#define ID_TEXTBOX	            3000

// ������� �������
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

        // ���������, � ����������� �������� �������� UI
    case WM_CREATE:
    {
        hbutton = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE,
            10, 70, 50, 50, wnd, (HMENU)ID_ONE, hInst, 0);

        hbutton = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE,
            60, 70, 50, 50, wnd, (HMENU)ID_TWO, hInst, 0);

        hbutton = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE,
            110, 70, 50, 50, wnd, (HMENU)ID_THREE, hInst, 0);

        hbutton = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE,
            10, 120, 50, 50, wnd, (HMENU)ID_FOUR, hInst, 0);

        hbutton = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE,
            60, 120, 50, 50, wnd, (HMENU)ID_FIVE, hInst, 0);

        hbutton = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE,
            110, 120, 50, 50, wnd, (HMENU)ID_SIX, hInst, 0);

        hbutton = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE,
            10, 170, 50, 50, wnd, (HMENU)ID_SEVEN, hInst, 0);

        hbutton = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE,
            60, 170, 50, 50, wnd, (HMENU)ID_EIGHT, hInst, 0);

        hbutton = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE,
            110, 170, 50, 50, wnd, (HMENU)ID_NINE, hInst, 0);

        hbutton = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE,
            160, 170, 50, 50, wnd, (HMENU)ID_ZERO, hInst, 0);

        hbutton = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE,
            210, 170, 50, 50, wnd, (HMENU)ID_EQUAL_BUTTON, hInst, 0);

        hbutton = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE,
            160, 70, 50, 50, wnd, (HMENU)ID_ZERO, hInst, 0);

        hbutton = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE,
            160, 120, 50, 50, wnd, (HMENU)ID_ZERO, hInst, 0);

        hbutton = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE,
            210, 70, 50, 50, wnd, (HMENU)ID_ZERO, hInst, 0);

        hbutton = CreateWindow("button", "/", WS_CHILD | WS_VISIBLE,
            210, 120, 50, 50, wnd, (HMENU)ID_ZERO, hInst, 0);

        hedit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
            10, 10, 250, 50, wnd, (HMENU)ID_TEXTBOX, hInst, 0);

        return 0;
    }

    // ��������� ��������� �������� ���������
    case WM_COMMAND:
    {
        return 0;
    }

    // ������� ����
    case WM_DESTROY:
    {
        // ������� ���������� (�������)
        PostQuitMessage(0);
        return 0;
    }
    }

    // ���������� �������������� ���������
    return DefWindowProc(wnd, msg, wParam, lParam);
}

// ����� ����� � ���������
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR     lpCmdLine, int       nCmdShow)
{
    // ��������� ��� ������ ����
    WNDCLASS wc;

    // ����� ������ ���� (��������� �� ����)
    HWND hwnd;

    // ��������� ������� ����
    wc.hInstance = hInstance;

    // ������ ����
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // ������ ����
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);

    // ������� �������
    wc.lpfnWndProc = WndProc;

    // ����� ������ ����
    wc.lpszMenuName = NULL;

    // ����� ����
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    // ������� ������ ����
    wc.lpszClassName = className;

    // ����� ����
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // ����������� ������ ����
    int k = RegisterClass(&wc);

    // �������� �������� ���� ����������
    hwnd = CreateWindow(className, "Calculator", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        300, 300, 285, 270, NULL, NULL, hInstance, 0);

    // ����� � �������
    if (!hwnd) return false;

    // ���� ��������� ���������
    while (GetMessage(&msg, 0, 0, 0)) {

        TranslateMessage(&msg);
        // ��������� ��������� ����
        DispatchMessage(&msg);
    }

    return 1;
}