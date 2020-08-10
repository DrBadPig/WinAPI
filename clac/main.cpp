#include <windows.h>

// название класса окна
char className[] = "Calculator";

// структура, хран€ща€ информацию о сообщении
MSG msg;
//кнопки
HWND hbutton, hedit, hres_edit, buttons2[16];

// оконна€ функци€
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

        // зарытие окна
    case WM_DESTROY:
    {
        // закрыть приложение (процесс)
        PostQuitMessage(0);
        return 0;
    }
    }

    // утилизаци€ необработанных сообщений
    return DefWindowProc(wnd, msg, wParam, lParam);
}

// точка входа в программу
int APIENTRY WinMain(HINSTANCE hInstance,   // адрес экземпл€ра приложени€
    HINSTANCE hPrevInstance,                // адрес экземпл€ра приложени€, запустившего текущее
    LPSTR     lpCmdLine,                    // комендна€ строка
    int       nCmdShow)                     // флаги запуска окна
{
    // структура дл€ класса окна
    WNDCLASS wc;

    // адрес одного окна (указатель на окно)
    HWND hwnd;

    // занесение свойств окна
    wc.hInstance = hInstance;

    // значок окна
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // курсор окна
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);

    // оконна€ функци€
    wc.lpfnWndProc = WndProc;

    // адрес строки меню
    wc.lpszMenuName = NULL;

    // кисть окна
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    // назвние класса окна
    wc.lpszClassName = className;

    // стили окна
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // регистраци€ класса окна
    int k = RegisterClass(&wc);

    // создание главного окна приложени€
    hwnd = CreateWindow(className, "Calculator", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        300, 300, 600, 400, NULL, NULL, hInstance, 0);

    // выйти с ошибкой
    if (!hwnd) return false;

    // цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0)) {

        // обработка сообщений окну
        DispatchMessage(&msg);
    }

    return 1;
}