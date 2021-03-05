#include <iostream>

using namespace std;

// Địa chỉ của các phần tử mảng a cách nhau 4 do để kiểu int
// Địa chỉ của các phần tử mảng b cách nhau 1 do để kiểu char

int main(){
    int a[3]={0,1,2};
    char b[3]={'a','b','c'};
    for (int i=0; i<=2; i++) cout << &a[i] << " ";
    cout << endl;
    for (int i=0; i<=2; i++) cout << (void *)&b[i] << " ";
    return 0;
}
