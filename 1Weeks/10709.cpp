#include <bits/stdc++.h>

using namespace std;

int h, w;
char c[104][104];
int a[104][104];

int main()
{
    cin>>h>>w;
    memset(a,-1,sizeof(a));
    for(int i = 1; i<= h;i++)
    {
        for(int j =1;j<= w;j++)
        {
            cin>>c[i][j];
        }
    }

    for(int i = 1; i <= h;i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(c[i][j] == 'c')
                a[i][j] = 0;
            else if(c[i][j] == '.')
            {
                if(a[i][j - 1] == -1)
                    continue;
                else
                    a[i][j] = a[i][j-1]+1;
            }
        }
    }

    for(int i = 1; i<= h;i++)
    {
        for(int j =1;j<= w;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }


}