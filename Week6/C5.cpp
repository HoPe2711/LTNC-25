#include<iostream>

using namespace std;

int n,dem;
int a[50];

void cal(int j,int k){
    if (j == 0) {
        for (int i=1; i<=dem; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i=min(j,k); i>=1; i--){
            dem++;
            a[dem]=i;
            cal(j-i,i);
            a[dem]=0;
            dem--;
        }
}

int main(){
    cin >> n;
    cal(n,n);
    return 0;
}
