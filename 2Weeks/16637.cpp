#include<bits/stdc++.h>

using namespace std;

int n;
char oper[20];
int arr[20];
int index1, index2;
int ret;

int Col(int a, int b, char c)
{
    if(c == '+')
        return a+b;
    if(c == '-')
        return a-b;
    if(c == '*')
        return a*b;

    return a/b;
}

void Solution(int temp)
{
    ret = arr[0];
    for(int i = 1; i < index1; i++)
    {
        ret = Col(ret, arr[i], oper[i-1]);
        cout<<ret<<endl;
    }
}


int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        char a;
        cin>>a;

        if(a == '+'||a == '-' || a == '/' || a == '*')
            oper[index2++] = a;
        else   
            arr[index1++] = (a-'0');
    }

    

    cout<<ret;
}