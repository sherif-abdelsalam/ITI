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

        if (ch == 8 and cursor > 0)
        {
            text.erase(cursor-1,1);
            cursor--;
        }

        else if (ch == 224 || ch == 0 || ch == -32) // Extended Keys
        {
            ch = getch();

            switch(ch)
            {
            case 75: /// left
                if(cursor > 0) cursor--;
                break;

            case 77: /// right
                if(cursor < text.size()) cursor++;
                break;

            case 71: /// home
                cursor = 0;
                break;

            case 79: /// end
                cursor = text.size();
                break;

            case 83: /// delete
                if(cursor < text.size())
                    text.erase(cursor,1);
                break;
            }
        }

        else if (ch >= 32 && ch <= 126)
        {
            if (cursor == text.size()) // insert at end
                text.insert(text.begin() + cursor, ch);
            else
                text[cursor] = ch; // overwrite

            cursor++;
        }

        system("cls");
        cout << text << endl;

        gotoxy(cursor, 0);
//        for(int i=0;i<cursor;i++)
//            cout << " ";
//        cout << "^";
    }
}

int main()
{
    cout << "Single Line Editor: ";
    string result = SingleLineEditor();
    cout << "\n" << result;
}
