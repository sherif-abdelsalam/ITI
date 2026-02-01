#include <iostream>
#include <MyLibrary.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

string SingleLineEditor()
{
    string text = "";
    int cursor = 0;

    while (true)
    {
        int ch = getch();

        if (ch == 13) // Enter
            return text;

        if (ch == 27) // Esc
            return "Exiting without saving ........";

        if (ch == 224 || ch == 0 || ch == -34) // Extended Keys
        {
            ch = getch();

            if (ch == 75 && cursor > 0) // Left
                cursor--;

            else if (ch == 77 && cursor < text.size()) // Right
                cursor++;

            else if (ch == 71) // Home
                cursor = 0;

            else if (ch == 79) // End
                cursor = text.size();

        }
        else if (ch >= 32 && ch <= 126)
        {
               if (cursor == text.size()) // inset at the end
                {
                    text.insert(text.begin() + cursor, ch);
                }
                else
                {
                    text[cursor] = ch; // override
                }

                cursor++;
        }

        system("cls");
        cout << text << endl;

        for(int i=0;i<cursor;i++) cout << " ";
        cout << "^";
    }
}

int main()
{
    cout << "Single Line Editor: ";
    string result = SingleLineEditor();
    cout << "\n" << result;
}
