#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    cout << setprecision(2) << fixed;
    int n,m,c;
    cin >> n >> m >> c;
    if(n + m <= c || n + c <= m || m + c <= n) cout << "invalid";
    else {
        double p = (n + m + c)/2;
        cout << sqrt(p*(p-n)*(p-c)*(p-m));
    }
}
