#include<iostream>

using namespace std;

int dd[50];
int n,k;
string st;

void hoanvi(int j){
    if (j == k) {
        cout << st << endl;
        return;
    }

    for (int i=1; i<=n; i++)
        if (dd[i]==0){
            st=st+char('a'+i-1);
            dd[i]=1;
            hoanvi(j+1);
            st.erase(j,1);
            dd[i]=0;
        }
}

int main(){
    cin >> n >> k;
    if (n > k) hoanvi(0);
    else cout << "Error";
    return 0;
}
