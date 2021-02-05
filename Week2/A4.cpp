#include <iostream>

using namespace std;
int dayOrigin, monthOrigin, yearOrigin, value;

void readDay(){
    char ch;
    cin >> dayOrigin;
    cin >> ch;
    cin >> monthOrigin;
    cin >> ch;
    cin >> yearOrigin;
}

void writeResult(int day, int month, int year){
    if (day<10) cout << "0" << day;
    else cout << day;
    cout << "-";
    if (month<10) cout << "0" << month;
    else cout << month;
    cout << "-";
    cout << year;
    cout << endl;
}


bool isLeap(int year){
    if (year % 100 !=0 && year %4==0 || year % 400==0) return true;
    return false;
}

int getNumDay(int day, int month, int year){
    int countDay = day;
    switch (month-1)
    {
    case 11:
        countDay +=30;
    case 10:
        countDay +=31;
    case 9:
        countDay +=30;
    case 8:
        countDay +=31;
    case 7:
        countDay +=31;
    case 6:
        countDay +=30;
    case 5:
        countDay +=31;
    case 4:
        countDay +=30;
    case 3:
        countDay +=31;
    case 2:
        countDay +=28;
    case 1:
        countDay +=31;
    }
    if (isLeap(year) && month>2) countDay++;
    return countDay;
}

void getDayResult(int numDay, int year){
    int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeap(year)) monthDay[2]++;
    int day,month,sumDay = 0;
    for (int i=1; i<=12; i++){
        if (numDay <= sumDay+monthDay[i]) {
            month=i;
            break;
        }
        sumDay+=monthDay[i];
    }
    day = numDay-sumDay;
    writeResult(day,month,year);
}


void addDay(int day, int month, int year){
    int numDay = getNumDay(day,month,year);
    int remainDay = isLeap(year)?(366-numDay):(365-numDay);
    if (remainDay>=value) numDay += value;
    else {
        value -= remainDay;
        year++;
        int yearDay = isLeap(year)?366:365;
        while (value > yearDay){
            value-=yearDay;
            year++;
            yearDay = isLeap(year)?366:365;
        }
        numDay = value;
    }
    getDayResult(numDay, year);
}

void substractDay(int day, int month, int year){
    int numDay = getNumDay(day,month,year);
    value = abs(value);
    if (value < numDay) numDay -= value;
    else {
        value -= numDay;
        year--;
        int yearDay = isLeap(year)?366:365;
        while (value >= yearDay){
            value -= yearDay;
            year --;
            yearDay = isLeap(year)?366:365;
        }
        numDay = yearDay-value;
    }
    getDayResult(numDay, year);
}

void solve(){
    if (value>=0) addDay(dayOrigin,monthOrigin,yearOrigin);
    else substractDay(dayOrigin,monthOrigin,yearOrigin);
}


int main(){
    readDay();
    while (cin >> value){
        if (value==0) break;
        solve();
    }
    return 0;
}
