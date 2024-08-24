#ifndef UNICODE  /* Prevents compiler issues */
#define UNICODE
#endif

#include <stdio.h>
#include <windows.h>  // Windows API


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // Declare function for compiler

// wWinMain is the windows version of the main function
// hInstance is a handle instance
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
    // ---------------------- Set up window class and create a window ----------------------

    // wchar_t is a 2-byte character used by windows, L signifies the string is made from wide characters
    const wchar_t CLASS_NAME[]  = L"PerfView Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;  // WindowProc is a function setting the behaviour of the window
    wc.hInstance     = hInstance;  // hInstance is a handle to the application instance
    wc.lpszClassName = CLASS_NAME;  // lpszClassName is a string which is the name of the class

    RegisterClass(&wc);  // Register wc (window class) with the OS

    // CreateWindowEx returns a handle to a new window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        L"PerfView",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    // Return if CreateWindowEx fails
    if (hwnd == NULL) {
        printf("CreateWindowEx failed!");
        return 0;
    }

    // Make the window visible
    ShowWindow(hwnd, nCmdShow);


    // ---------------------- Set up message loop ----------------------

    // The message loops runs until the WindowProc functions calls quit
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {  // GetMessage pops first message from queue, blocks if the queue is empty
        TranslateMessage(&msg);  // Turns keystrokes into characters
        DispatchMessage(&msg);  // Tells OS to call WindowProc function
    }

    return 0;
}


// WindowProc - Window Procedure
// Called every time the window recevies a message
// uMsg - message code
// wParam and lParam - additional data
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg) {

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:  // Called when new area of screen is shown to user
        {
            PAINTSTRUCT ps;  // Has information of the new area that needs to be painted
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint
            // ps.rcPaint is the rectangle of the area that needs to be painted

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }

    // If the function doesn't respond to a particular message
    // then let windows perform the default response
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
