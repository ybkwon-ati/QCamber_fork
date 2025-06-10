#include "settingsdialog.h"
#include <windows.h>

bool SettingsDialog::create(HINSTANCE hInst, HWND parent)
{
    const wchar_t CLASS_NAME[] = L"SettingsDialog";
    WNDCLASS wc = {};
    wc.lpfnWndProc = SettingsDialog::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"Settings",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          400, 300,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void SettingsDialog::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK SettingsDialog::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
