#include<iostream>

using namespace std;

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

char * Reverse(const char *a)
{
    int len = str_len(a);
    char * blank = new char[len];

    for(int i = len-1; i >= 0; i--) blank[i] = a[len-i-1];

    return blank;
}

char * delete_char(const char * a,const char * c)
{
    int len = str_len(a);
    char * blank = new char[len];

    int j=0;
    for(int i = 0; i <= len-1; i++)
        if (a[i]!=c[0])
        {
            blank[j] = a[i];
            j ++ ;
        }

    return blank;
}

char * pad_right(const char * a,const int n)
{
    int len = str_len(a);
    char * blank = new char[max(n,len)];
    for (int i=0; i<len; i++) blank[i]=a[i];
    if(len < n)
    {
        for(int i = len; i < n; i++)
        {
            blank[i] = '_';
        }
    }

    return blank;
}

char * pad_left(const char *a,const int n)
{
    int len = str_len(a);
    char * blank = new char[max(n,len)];
    if(len < n)
    {
        for (int i=0; i<n-len; i++) blank[i]='_';
        for (int i=n-len; i<n; i++) blank[i]=a[i-n+len];
    }
    else
        for (int i=0; i<len; i++) blank[i]=a[i];
    return blank;
}

char * truncate(const char *a,const int n)
{
    int len = str_len(a);
    char * blank = new char[min(n,len)];
    if(len > n)
        for (int i=0; i<min(len,n); i++) blank[i]=a[i];
    else for (int i=0; i<len; i++) blank[i]=a[i];
    return blank;
}

bool is_palindrome(const char * a)
{
    int n = str_len(a);
    for(int i = 0; i < n/2; i++)
    {
        if(a[i] != a[n-i-1])
            return false;
    }
    return true;
}

char * trim_left(const char *a)
{
    int len = str_len(a);
    int j=0;
    for (int i=0; i<len; i++)
        if (a[i]!=' ')
        {
            j=i;
            break;
        }
    char * blank = new char[len-j];
    for(int i=j; i<len; i++) blank[i-j] = a[i];
    return blank;
}

char * trim_right(const char *a)
{
    int len = str_len(a);
    int j=len-1;
    for (int i=len-1; i>=0; i--)
        if (a[i]!=' ')
        {
            j=i;
            break;
        }
    char * blank = new char[j+1];
    for(int i=0; i<=j; i++) blank[i] = a[i];
    return blank;
}


int main()
{
    char s[] = "nguyenthaibinh";
    char ss[] = "       hihi";
    char sss[] = "hihi    ";
    char binh[] = "binhhnib";
    //cout << Reverse(s);
    //cout << delete_char(s, "i");
    //cout << pad_right(s, 20);
    //cout << pad_left(s, 20);
    //cout << truncate(s, 6);
    //cout << is_palindrome(binh);
    //cout  << trim_left(ss);
    cout << trim_right(sss);
    return 0;
}
