
#include <iostream>
using namespace std;

int main() {

//    char ch;
//    int cntChars = 0;
//    int cntWords = 1;
//    while( cin.get(ch) && ch != '\n') {
//        cntChars++;
//        if(ch == ' ') cntWords++;
//    }
//    cout<<"Number of words: " << cntWords<<endl;
//    cout<<"Number of Character: " << cntChars<<endl;

    string str;
    cout<<"Enter sentence: ";
    getline(cin, str);
    int cntWords = 1;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' ') cntWords++;

    }
    cout<<"Number of words: " << cntWords<<endl;


    return 0;
}

