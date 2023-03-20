#pragma once
#pragma once
#include <conio.h> // Just for WaitKey() routine
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


// For use of SetConsoleTextAttribute()
// Color of the console
HANDLE console_color;
void ColoredMenu() {
    int len = 0, x, y = 2; // 240 = white background, black foreground
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    string text1 = " \t\t\t\t\t Zains Last Stand | TASK 1 | \n\n\nSelect an option: \n 1) Search for a number all data structures \n 2) Exit \n Enter in option (1 or 2): ";

    len = text1.length();

  
    cout << endl << endl << endl << ""; // start 3 down, 2 tabs, right
    for (x = 0; x < len; x++)
    {
        SetConsoleTextAttribute(console_color, y); // set color for the next print
       // cout << text1[x];

        cout << text1[x];

        y++; // add 1 to y, for a new color
        if (y > 15) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y = 2; // if y > 254, start colors back at white background, black chars
        Sleep(50); // Pause between letters 
    }


}

void CompletedMenu()
{
    int len = 0, x, y = 2; // 240 = white background, black foreground
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    string text2 = "Search Complete Enter Any Key to Continue: ";

    len = text2.length();
    cout << endl << endl << endl << "";
    for (x = 0; x < len; x++)
    {
        SetConsoleTextAttribute(console_color, y); // set color for the next print
       // cout << text1[x];

        cout << text2[x];

        y++; // add 1 to y, for a new color
        if (y > 15) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y = 2; // if y > 254, start colors back at white background, black chars
        Sleep(50); // Pause between letters 
    }

}

void LoadingMenu()
{

    int len = 0, x, y = 2; // 240 = white background, black foreground
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    string text3 = "Loading.....\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n| \t\t\t\t\t\ |--- SEARCH COMPLETE! ---|";

    len = text3.length();
    cout << endl << endl << endl << "";
    for (x = 0; x < len; x++)
    {
        SetConsoleTextAttribute(console_color, y); // set color for the next print
       // cout << text1[x];

        cout << text3[x];

        y++; // add 1 to y, for a new color
        if (y > 15) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y = 2; // if y > 254, start colors back at white background, black chars
        Sleep(50); // Pause between letters 
    }

    y = 6;
}

void LoadBGColor()
{
    int len = 0, x, y = 15; // 240 = white background, black foreground
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, y);


}
