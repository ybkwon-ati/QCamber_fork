#include "jobmatrix.h"
#include <windows.h>

bool JobMatrix::create(HINSTANCE hInst, const wchar_t* title, HWND parent)
{
    WNDCLASS wc = {};
    wc.lpfnWndProc = JobMatrix::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = title;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, title, title,
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          500, 300,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void JobMatrix::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK JobMatrix::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
