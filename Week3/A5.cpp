#include <iostream>
#include <ctime>

using namespace std;

const int n=30;
int a[n];

int main(){
    srand(time(0));
    for (int i=1; i<=n; i++) a[i]=rand() %1000;
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if (a[i]>a[j]) swap(a[i],a[j]);

    for (int i=1; i<=n; i++) cout << a[i] << " ";
    return 0;
}
