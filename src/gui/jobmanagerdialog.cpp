#include "jobmanagerdialog.h"
#include <windows.h>

bool JobManagerDialog::create(HINSTANCE hInst, HWND parent)
{
    const wchar_t CLASS_NAME[] = L"JobManagerDialog";
    WNDCLASS wc = {};
    wc.lpfnWndProc = JobManagerDialog::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, CLASS_NAME, L"Job Manager",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          600, 400,
                          parent, NULL, hInst, NULL);
    return hwnd != NULL;
}

void JobManagerDialog::show()
{
    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK JobManagerDialog::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    switch(m) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(h, m, w, l);
}
