#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
   int n,sum=0,maxx=0,minn=1000000,x;
   cin >> n;
   for (int i=1; i<=n; i++){
		cin >> x;
		maxx=max(maxx,x);
		minn=min(minn,x);
		sum+=x;
   }
   cout << "Mean: " << setprecision(2) << fixed << (double) sum/n << endl ;
   cout << "Max: " << maxx << endl ;
   cout << "Min: " << minn;
   return 0;
}

