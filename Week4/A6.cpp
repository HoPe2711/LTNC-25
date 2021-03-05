#include<iostream>

using namespace std;

//dequy
int bs(int key, int a[], int low, int high) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] > key)
    return bs(key, a, low, mid-1);
    return bs(key, a, mid+1, high);
}


//vonglap
int bs1(int key, int a[], int low, int high) {
    while (low<=high){
        int mid = (low+high)/2;
        if (a[mid]==key) return mid;
        if (a[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int key[4]={1,10,11,4};
    int n=10;
    cout << "de quy" << endl;
    for (int i=0; i<=3; i++){
        int vt = bs(key[i],a,0,9);
        cout << key[i] << " " ;
        if (vt!=-1) cout << vt << endl;
        else cout << "Not exist!" << endl;
    }
    cout << endl;
    cout << endl;
    cout << "vong lap" << endl;
    for (int i=0; i<=3; i++){
        int vt = bs1(key[i],a,0,9);
        cout << key[i] << " " ;
        if (vt!=-1) cout << vt << endl;
        else cout << "Not exist!" << endl;
    }
    return 0;
}
