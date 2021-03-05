#include <iostream>

using namespace std;

void swap_by_value(int x, int y){
    int tg=x;
    x=y;
    y=tg;
    cout << &x << " " << &y << endl;
}

void swap_by_reference(int &x, int &y){
    int tg=x;
    x=y;
    y=tg;
    cout << &x << " " << &y << endl;
}

int main(){
    int a=2;
    int b=3;
    swap_by_value(a,b);
    cout << &a << " " << &b << endl;
    swap_by_reference(a,b);
    cout << &a << " " << &b << endl;
    return 0;
}
