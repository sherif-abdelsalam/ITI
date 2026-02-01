#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <MyLibrary.h>
using namespace std;


vector<string> MultiLineEditor(){
    vector<string> lines(1, "");
    int row = 0;
    int col = 0;

    while (true){
        int ch = getch();
        if (ch == 13) {   /// Enter
            string rest = lines[row].substr(col);
            lines[row] = lines[row].substr(0, col);
            lines.insert(lines.begin() + row + 1, rest);
            row++;
            col = 0;
        }
        else if (ch == 27) /// Esc
            return lines;

        else if (ch == 8) { /// Backspace
            if (col > 0){
                lines[row].erase(col - 1, 1);
                col--;
            }
            else if (row > 0){
                col = lines[row - 1].size();
                lines[row - 1] += lines[row];
                lines.erase(lines.begin() + row);
                row--;
            }
        }

        /// Extended keys
        else if (ch == 224 || ch == 0 || ch == -34)
        {
            ch = getch();
            switch (ch)
            {
            case 75: /// left
                if (col > 0) col--;
                else if (row > 0){
                    row--;
                    col = lines[row].size();
                }
                break;

            case 77: /// right
                if (col < lines[row].size()) col++;
                else if (row < (int)lines.size() - 1){
                    row++;
                    col = 0;
                }
                break;

            case 72: /// up
                if (row > 0){
                    row--;
                    if (col > lines[row].size())
                        col = lines[row].size();
                }
                break;

            case 80: /// down
                if (row < (int)lines.size() - 1){
                    row++;
                    if (col > lines[row].size())
                        col = lines[row].size();
                }
                break;

            case 71: /// home
                col = 0;
                row = 0;
                break;

            case 79: /// end
                col = lines[row].size();
                row = (int)lines.size() - 1;
                break;

            case 83: /// delete
                if (col < lines[row].size()){
                    lines[row].erase(col, 1);
                }
                else if (row < (int)lines.size() - 1){
                    lines[row] += lines[row + 1];
                    lines.erase(lines.begin() + row + 1);
                }
                break;
            }
        }

        else if (ch >= 32 && ch <= 126){
//            lines[row].insert(lines[row].begin() + col, ch);
//            col++;
            if(col == lines[row].size()) lines[row].insert(lines[row].begin() + col, ch);
            else lines[row][col] = ch;
            col++;
        }


        clrscr();
        for (int i = 0; i < lines.size(); i++)
            cout << lines[i] << endl;

        gotoxy(col, row); /// Set cursor
    }
}

int main()
{
    vector<string> lines = MultiLineEditor();
    cout << "\n\n\n";
    for(int i = 0; i < lines.size(); i++)
        cout<<lines[i]<<endl;
}
