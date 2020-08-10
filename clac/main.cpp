#include <windows.h>

// �������� ������ ����
char className[] = "Calculator";

// ���������, �������� ���������� � ���������
MSG msg;
//������
HWND hbutton, hedit, hres_edit, buttons2[16];

// ������� �������
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

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
int APIENTRY WinMain(HINSTANCE hInstance,   // ����� ���������� ����������
    HINSTANCE hPrevInstance,                // ����� ���������� ����������, ������������ �������
    LPSTR     lpCmdLine,                    // ��������� ������
    int       nCmdShow)                     // ����� ������� ����
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
        300, 300, 600, 400, NULL, NULL, hInstance, 0);

    // ����� � �������
    if (!hwnd) return false;

    // ���� ��������� ���������
    while (GetMessage(&msg, 0, 0, 0)) {

        // ��������� ��������� ����
        DispatchMessage(&msg);
    }

    return 1;
}