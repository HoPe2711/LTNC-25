#include <iostream>

using namespace std;

struct String
{
    int n;
    char *str ;

    int str_len(const char *a)
    {
        int len = 0;
        while(*a != '\0')
        {
            len++;
            a++;
        }
        return len;
    }

    String(const char * a)
    {
        n = str_len(a);
        str = new char[n];
        for (int i=0; i<n; i++) str[i] = a[i];
    }

    ~String(){
        delete [] str;
    }

    void print(){
        cout << str << endl;
    }

    void append(const char * a){
        int len = str_len(a) + n;
        char * temp = new char[len];
        for (int i=0; i<n; i++) temp[i] = str[i];
        for (int i=n; i<len; i++) temp[i] = a[i-n];
        n = len;
        str =new char[n];
        for (int i=0; i<n; i++) str[i] = temp[i];
        delete [] temp;
    }
};

int main()
{
    //String s("Hello");
    //s.print();
    //String* p = new String("abc");
    //p->print();
    //delete p;
    //p->print();
    String s("Hi");
    s.append(" there,");
    s.append(" binh dep zai");
    s.print();
    return 0;
}
