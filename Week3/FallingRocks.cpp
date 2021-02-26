#include <iostream>

using namespace std;

const int maxm=1001, maxn=1001;
int d[maxm][maxn],rock[maxm][maxn];
int q[maxm*maxn],q1[maxm*maxn];
string st;
int m,n,rootx,rooty,u,v,res,f,r;

void build(){
    for (int i=1; i<=m; i++){
        cin >> st;
        for (int j=0; j<n; j++){
            if (st[j]=='Y'){
                rootx=i;
                rooty=j+1;
            }
            if (st[j]=='R') rock[i][j+1]=1;
        }
    }
}

void push(int x, int y){
    r++;
    q[r]=x;
    q1[r]=y;
}

void pop(){
    u=q[f];
    v=q1[f];
    ++f;
}

void add(int s, int t){
    if (s>m) return;
    if (t>n || t<1) return;
    if (d[s][t]==1 || rock[s][t]==1) return;
    d[s][t]=1;
    push(s,t);
}

void solve(){
    f=1; r=0;
    d[rootx][rooty]=1;
    push(rootx,rooty);
    while (f<=r){
        pop();
        if (u==m){
            res=1;
            break;
        }
        add(u+1,v);
        if (rock[u][v-1]==0) add(u+1,v-1);
        if (rock[u][v+1]==0) add(u+1,v+1);
    }
    if (res==1) cout << "YES";
    else cout << "NO";
}

int main(){
    cin >> n >> m;
    build();
    solve();
    return 0;
}
