#include "viewerwindow.h"
#include <windows.h>

bool ViewerWindow::create(HINSTANCE hInst, HWND parent)
{
    const wchar_t CLASS_NAME[] = L"ViewerWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = ViewerWindow::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"Viewer",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          640, 480,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void ViewerWindow::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK ViewerWindow::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
