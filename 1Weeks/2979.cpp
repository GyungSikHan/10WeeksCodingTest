#include<bits/stdc++.h>

using namespace std;

int a, b,c, ret;
int te, te2, t;
int arr[101];
int main()
{
    cin>>a>>b>>c;

    for(int i = 0; i < 3; i++)
    {
        cin>>te>>te2;
        t = max(te2, t);
        for(int j = te; j < te2; j++)
            arr[j]+=1;
    }

    for(int i = 0; i < t; i++)
    {
        if(arr[i] == 1)
        {
            ret+=a;
        }
        else if(arr[i] == 2)
        {
            ret+=b*2;
        }
        else if(arr[i] == 3)
        {
            ret+=c*3;
        }
    }

    cout<<ret;
}