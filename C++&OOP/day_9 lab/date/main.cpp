#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    Date(const Date& D) {
        day = D.day;
        month = D.month;
        year = D.year;
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    int operator-(const Date& D) {
        return (day - D.day) + (month - D.month) * 30 + (year - D.year) * 365;
    }

    Date operator+(int days) const {
        Date temp;
        temp.day = day + days;
        temp.month = month;
        temp.year = year;
        return temp;
    }

    Date& operator++() {
        day++;
        return *this;
    }

    Date operator++(int) {
        Date temp(*this);
        day++;
        return temp;
    }

    void operator=(const Date& D) {
        day = D.day;
        month = D.month;
        year = D.year;
    }

    bool operator==(const Date& D) {
        return day == D.day && month == D.month && year == D.year;
    }

    operator int() {
        return day + month * 30 + year * 365;
    }

    int operator[](char ch) {
        if(ch == 'd' || ch == 'D') return day;
        if(ch == 'm' || ch == 'M') return month;
        if(ch == 'y' || ch == 'Y') return year;
        return 0;
    }
};

int main() {
    Date d1(10, 5, 2025);
    Date d2(15, 5, 2025);

    d1.printDate();
    d2.printDate();
    cout<<"=======================\n";
    int diff = d2 - d1;
    cout << "d2 - d1 = " << diff << " days" << endl;

    Date d3 = d1 + 10;
    cout << "d1 + 10 days = ";
    d3.printDate();


    ++d1;
    cout<<"Prefix d1: ";
    d1.printDate();

    Date d4 = d1++;
    cout << "D4"; d4.printDate();
    cout << "Postfix d1"; d1.printDate();

    Date d5;
    d5 = d2;
    d5.printDate();

    cout <<"d1==d2: " <<(d1 == d2) << endl;

    int days = (int)d1;
    cout << days << endl;

    cout << d1['d'] << "/" << d1['m'] << "/" << d1['y'] << endl;

    return 0;
}
