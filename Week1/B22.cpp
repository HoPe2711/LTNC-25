#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    cout << setprecision(2) << fixed;
    float n,m;
    cin >> n >> m;
    if(m == 0) cout << "error";
    else cout << 1.f*n/(m * m);
}
