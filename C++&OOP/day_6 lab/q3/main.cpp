#include <iostream>

using namespace std;

int main()
{
   cout << "Enter number of students: ";
    int rows; cin >> rows;

    cout << "Enter number of subjects: ";
    int cols; cin >> cols;

    int **arr = new int*[rows];

    for(int i = 0; i < rows ; i++)
        arr[i] = new int[cols];

    for(int i = 0; i < rows; i++)
    {
        cout << "Enter degrees for student " << i+1 << ": " << endl;

        for(int j = 0; j < cols; j++)
        {
            cout << "  Subject " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }



    for(int i = 0; i < rows; i++){
        int studentDegreesSum = 0;
        for(int j = 0; j < cols; j++){
            studentDegreesSum+= arr[i][j];
        }
        cout << "Sum degrees for student " << i+1 << ": " << studentDegreesSum<< endl;
    }

    for(int i = 0; i < cols; i++){
        int studentDegreesSum = 0;
        for(int j = 0; j < rows; j++){
            studentDegreesSum+= arr[j][i];
        }
        cout << "Average degrees for subject " << i+1 << ": " << (float)studentDegreesSum/rows<< endl;
    }

    return 0;
}
