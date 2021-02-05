#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if (n<0) cout << "error";
    else for (int i=0; i<=n; i+=2) cout << i << " ";
    cout << endl;
}

int main(){
    int test;
    for (cin >> test; test>0; test--) solve();
    return 0;
}
