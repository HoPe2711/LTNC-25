#include <iostream>

using namespace std;

//same

int main () {
    string s;
    for (int i=0; i<s.size(); i++) cout << s[i];
    cout << endl;
    cout << s;

    s="abcd";
    for (int i=0; i<s.size(); i++) cout << s[i];
    cout << endl;
    cout << s;
    return 0;
}
