#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int miner[50][50];
int status[50][50];
int m,n,k;
int directionx[8]={0,-1,1,0,1,-1,-1,1};
int directiony[8]={-1,0,0,1,1,-1,1,-1};

void setBoard();
void buildBoard();
void printBoard();
void implementGame();
void getResult(string st);
void printMiner();
void bfs(int x, int y, int &checkedNum);

int main(){
    srand(time(0));
    setBoard();
    buildBoard();
    printBoard();
    implementGame();
    return 0;
}

void setBoard(){
    cout << "Size Board: ";
    cin >> m >> n;
    while (m <=0 || n<=0){
        cout << "Bad Size Board!" << endl;
        cout << "Size Board: ";
        cin >> m >> n;
    }
    cout << "Number Miner: ";
    cin >> k;
    while (k > m*n || k<0){
        cout << "Bad Number Miner!" << endl;
        cout << "Number Miner: ";
        cin >> k;
    }
}

void buildBoard(){
    int numMiner = 0,x,y;
    while (numMiner<k){
        int pos = rand() % (m*n-1);
        x = pos / m + 1;
        y = pos % m + 1;
        if (miner[x][y]==0){
            ++ numMiner;
            miner[x][y]=9;
        }
    }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (miner[i][j]==9)
            for (int k=0; k<8; k++){
                    int u = i + directionx[k];
                    int v = j + directiony[k];
                    if (u<=m && v<=n && u>0 && v>0 && miner[u][v]!=9) ++miner[u][v];
                }
}

void getResult(string st){
    system("cls");
    cout << endl << st << endl;
    cout << endl;
    printMiner();
}

void bfs(int x,int y, int &checkedNum){
    int f=1,r=0,u,v,u1,v1;
    int queu[5000],queu1[5000];
    for (int i=0; i<=5000; i++) {
        queu[i]=0; queu1[i]=0;
    }
    ++r;
    queu[r]=x;
    queu1[r]=y;
    while (f<=r){
        u=queu[f];
        v=queu1[f];
        ++f;
        for (int i=0; i<4; i++){
            u1=u+directionx[i];
            v1=v+directiony[i];
            if (u1>0 && v1>0 && u1<=m && v1<=n)
                if (miner[u1][v1]==0 && status[u1][v1]==0){
                    ++r;
                    queu[r]=u1;
                    queu1[r]=v1;
                    status[u1][v1]=1;
                    ++checkedNum;
                }
                else if (miner[u1][v1]!=0 && status[u1][v1]==0){
                    status[u1][v1]=1;
                    ++checkedNum;
                }
        }
    }
}

void implementGame(){
    int x,y,checkedNum=0;
    while (true){
        if (checkedNum == m*n-k) {
            getResult("YOU WIN!");
            break;
        }
        cout << endl << "Check: ";
        cin >> x >> y;
        if (x>m || x<1 || y>n || y<1 || status[x][y]==1) {
            cout << "Invalid!" << endl;
            continue;
        }
        if (miner[x][y]==9) {
            getResult("YOU'RE DEAD!");
            break;
        }
        status[x][y]=1;
        ++checkedNum;
        if (miner[x][y]==0) bfs(x,y,checkedNum);
        printBoard();
    }
}

void printBoard(){
    system("cls");
    cout << endl << "x ";
    for (int i=1; i<=n; i++) cout << i;
    cout << endl;
    cout << endl;
    for (int i=1; i<=m; i++){
        cout << i << " ";
        for (int j=1; j<=n; j++)
            if (status[i][j]==0) cout << ".";
            else if (miner[i][j]>0) cout << miner[i][j];
            else cout << "_";
        cout << endl;
    }
}

void printMiner(){
    cout << "x ";
    for (int i=1; i<=n; i++) cout << i;
    cout << endl;
    cout << endl;
    for (int i=1; i<=m; i++){
        cout << i << " ";
        for (int j=1; j<=n; j++)
            if (miner[i][j]==9) cout << "*";
            else if (miner[i][j]>0) cout << miner[i][j];
            else cout << "_";
        cout << endl;
    }
}
