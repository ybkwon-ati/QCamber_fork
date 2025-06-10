#include "symbolcount.h"
#include <windows.h>

bool symbolcount::create(HINSTANCE hInst, HWND parent)
{
    const wchar_t CLASS_NAME[] = L"SymbolCount";
    WNDCLASS wc = {};
    wc.lpfnWndProc = symbolcount::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"Symbol Count",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          400, 300,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void symbolcount::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK symbolcount::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
