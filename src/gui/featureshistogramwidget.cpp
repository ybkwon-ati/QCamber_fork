/**
 * @file   featureshistogramwidget.cpp
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2012 - 2014 Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "featureshistogramwidget.h"
#include <windows.h>

bool FeaturesHistogramWidget::create(HINSTANCE hInst, HWND parent)
{
  const wchar_t CLASS_NAME[] = L"FeaturesHistogramWidget";
  WNDCLASS wc = {};
  wc.lpfnWndProc = FeaturesHistogramWidget::WndProc;
  wc.hInstance = hInst;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);

  hwnd = CreateWindowEx(0, CLASS_NAME, L"Histogram",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        300, 200,
                        parent, NULL, hInst, NULL);
  return hwnd != NULL;
}

void FeaturesHistogramWidget::show()
{
  ShowWindow(hwnd, SW_SHOW);
}

LRESULT CALLBACK FeaturesHistogramWidget::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
  switch(m) {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }
  return DefWindowProc(h, m, w, l);
}
