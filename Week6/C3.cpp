#include<iostream>

using namespace std;

int dd[50];
int n,k;
string st;

void tohop(int j, int t){
    if (j == k) {
        cout << st << endl;
        return;
    }

    for (int i=t+1; i<=n; i++)
        if (dd[i]==0){
            st=st+char('a'+i-1);
            dd[i]=1;
            tohop(j+1,i);
            st.erase(j,1);
            dd[i]=0;
        }
}

int main(){
    cin >> n >> k;
    if (n > k) tohop(0,0);
    else cout << "Error";
    return 0;
}
