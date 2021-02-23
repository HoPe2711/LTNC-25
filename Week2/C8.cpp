#include <iostream>

using namespace std;

long long f1,f2;
int num;
char pre,predif,ch;

void solve(){
    ch=getchar();
    num=1;
    pre=ch;
    while (ch!=EOF){
        ch=getchar();
        if (ch != pre) {
            f2=f1+f2;
            f1++;
            if (num>=2) f2++;
            if (num==1 && ch==predif) f2--;
            predif=pre;
            num=1;
        }
        else num++;
        pre=ch;
    }
    cout << f2;
}

int main(){
    freopen("test.txt","r",stdin);
    solve();
    return 0;
}
