#include <iostream>

using namespace std;

long long f[3][1000001];
char character[1000001];
int cnt[1000001];
string st;
int n;

void rebuildstring(){
    int num=1;
    cnt[num]=1;
    character[num]=st[0];
    for (int i=1; i<n; i++){
        if (st[i]!=st[i-1]) {
            ++num;
            character[num]=st[i];
            cnt[num]=1;
        }
        else ++cnt[num];
    }
    n=num;
}

void solve(){
    for (int i=1; i<=n; i++){
        f[1][i]=f[1][i-1]+1;
        f[2][i]+=(f[2][i-1]+f[1][i-1]);
        if (cnt[i]>=2) f[2][i]++;
        if (cnt[i]==1 && character[i+1]==character[i-1]) f[2][i+1]--;
    }
    cout << f[2][n];
}

int main(){
    cin >> st;
    n=st.size();
    rebuildstring();
    solve();
    return 0;
}
