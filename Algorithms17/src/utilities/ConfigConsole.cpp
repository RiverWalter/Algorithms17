#include <windows.h>
void ConfigConsole()
{
    //set forecolor to moderate White,
    //and background color to green.
    //system("color 27");
    system("color 2F");

    //set fontsize
    HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font = { 0 };
    font.cbSize = sizeof(font);
    bool b = GetCurrentConsoleFontEx(outcon, false, &font);
    //printf("b=%d, font.nFont=%d\n", b, font.nFont);
    //font.dwFontSize.X = 10;
    font.dwFontSize.Y = 24;
    //font.FontWeight = 100;
    SetCurrentConsoleFontEx(outcon, false, &font);

    //set the window size
    SMALL_RECT con_rect;
    con_rect.Left = 0;
    con_rect.Top = 0;
    con_rect.Right = 80;
    con_rect.Bottom = 18;
    SetConsoleWindowInfo(outcon, TRUE, &con_rect);
}