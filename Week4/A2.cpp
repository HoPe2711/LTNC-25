#include <iostream>

using namespace std;

// Địa chỉ của x cùng giảm đều theo x
// Frame stack = n+1
long long factorial(int x){
    cout << "x= " << x << " at " << &x << endl;
    if (x==0) return 1;
    return factorial(x-1)*x;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
