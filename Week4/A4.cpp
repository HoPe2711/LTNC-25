#include <iostream>

using namespace std;

//pass by value
int get(int x[]){
    cout << &x << " ";
}

int getstring(string st){
    cout << &st << " ";
}

//pass by reference
int getstring1(string &st){
    cout << &st << " ";
}

int main(){
    int a[3]={1,2,3};
    get(a);
    cout << &a << endl;
    string st="binh";
    getstring(st);
    cout << &st << endl;
    getstring1(st);
    cout << &st << endl;
    return 0;
}
