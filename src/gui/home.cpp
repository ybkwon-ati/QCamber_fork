#include "home.h"
#include <windows.h>

bool Home::create(HINSTANCE hInst)
{
    const wchar_t CLASS_NAME[] = L"HomeWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = Home::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"Home",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          640, 480,
                          NULL, NULL, hInst, NULL);
    return hwnd != NULL;
}

void Home::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK Home::WndProc(HWND h, UINT msg, WPARAM w, LPARAM l)
{
    switch(msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, msg, w, l);
}
