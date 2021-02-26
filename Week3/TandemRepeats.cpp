#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

int n,m;
string st;
const int base = 31;
const ll mod = 1000000007;
const int maxn = 100001;
ll hashst[maxn];
ll poww[maxn];
int f[maxn][320];

ll gethash(int i, int j){
    return (hashst[j]-hashst[i-1]*poww[j-i+1]+mod*mod)%mod;
}

void sethash(){
    poww[0]=1;
    for (int i=1; i<=n; i++) poww[i]=(poww[i-1] * base) % mod;
    for (int i=1; i<=n; i++) hashst[i]=(hashst[i-1]*base+st[i-1]-'a'+1)%mod;
}

void build(){
    for (int l=1; l<=sqrt(n); l++)
        for (int i=1; i<=n-l+1; i++) f[i][l]=1;

    for (int i=n; i>0; i--)
        for (int l=1; l<=sqrt(n); l++)
            if (i+l-1<=n && i-l>0 && gethash(i,i+l-1)==gethash(i-l,i-1)) f[i-l][l]=f[i][l]+1;
}

void solve(){
    int fi,la,len,res=1;
    cin >> fi >> la;
    len=la-fi+1;
    if (len<=sqrt(n)) res=f[fi][len];
    else {
        while (fi+2*len-1<=n){
            if (gethash(fi,fi+len-1) == gethash(fi+len,fi+len*2-1)) ++res;
            else break;
            fi+=len;
        }
    }
    cout << res << endl;
}

int main(){
    cin >> n >> m;
    cin >> st;
    sethash();
    build();
    for (int i=1; i<=m; i++) solve();
    return 0;
}
