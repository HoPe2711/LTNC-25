#include <iostream>

using namespace std;

int main(){
    int b;
    int &a=b;
    // biến tham chiếu và biến chiếu 1 biến trong bộ nhớ
    cout << &a << " " << &b;
    // int &a; invalid
    // int c; int &a=c; invalid
    return 0;
}
