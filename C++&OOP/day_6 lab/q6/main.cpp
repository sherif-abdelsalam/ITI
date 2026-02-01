#include <iostream>

using namespace std;

int main()
{
   cout << "Enter number of students: ";
    int rows; cin >> rows;
    int maxSubjectNumbers = 0;

    int **arr = new int*[rows];
    int *studentSubjectsNumbers = new int[rows]();

    for(int i = 0; i < rows ; i++){
        cout<<"Enter number of subjects for student"<< i+1 << ": ";
        cin>>studentSubjectsNumbers[i];
        if(studentSubjectsNumbers[i] > maxSubjectNumbers) maxSubjectNumbers = studentSubjectsNumbers[i];
        arr[i] = new int[studentSubjectsNumbers[i]]();
    }

    for(int i = 0; i < rows; i++)
    {
        cout << "Enter degrees for student " << i+1 << ": " << endl;
        for(int j = 0; j < studentSubjectsNumbers[i]; j++)
        {
            cout << "  Subject " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }



    for(int i = 0; i < rows; i++){
        int studentDegreesSum = 0;
        for(int j = 0; j < studentSubjectsNumbers[i]; j++){
            studentDegreesSum+= arr[i][j];
        }
        cout << "Sum degrees for student " << i+1 << ": " << studentDegreesSum<< endl;
    }

    for(int subject = 0; subject < maxSubjectNumbers; subject++){
        int studentDegreesSum = 0;
        int cnt = 0;
        for(int studnet = 0; studnet < rows; studnet++){
            if(subject < studentSubjectsNumbers[studnet]){
                studentDegreesSum+= arr[studnet][subject];
                cnt++;
            }
        }
        cout << "Average degrees for subject " << subject+1 << ": " << (float)studentDegreesSum/cnt<< endl;
    }

    return 0;
}
