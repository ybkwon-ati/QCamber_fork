#include "layerinfobox.h"
#include <windows.h>

bool LayerInfoBox::create(HINSTANCE hInst, HWND parent)
{
    const wchar_t CLASS_NAME[] = L"LayerInfoBox";
    WNDCLASS wc = {};
    wc.lpfnWndProc = LayerInfoBox::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"LayerInfo",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          300, 200,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void LayerInfoBox::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK LayerInfoBox::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
