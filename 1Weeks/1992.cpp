#include<bits/stdc++.h>
#include <type_traits>

using namespace std;

int n;
string s;

char arr[65][65];

string DFS(int y, int x, int ysize,int xsize)
{
    string steamp;
    char temp{};
    bool b{};
    //cout<<y<<" "<<x<<" "<<ysize<<" "<<xsize<<endl;
    for(int i = 0; i < ysize; i++)
    {
        for(int j = 0; j <xsize;j++)
        {
            if(temp == '\0')
            {
                temp = arr[i+y][j+x];
            }
            else
            {
                if(temp != arr[i+y][j+x])
                {
                    b= true;
                    break;
                }
            }
        }
        if(b == true)
            break;
    }

    if(b == true)
    {
        //cout<<"분할"<<endl;
        steamp += '(';
        steamp += DFS(y,x,ysize/2, xsize/2);
        steamp += DFS(y,x+xsize/2, ysize/2, xsize/2);
        steamp += DFS(y+ysize/2, x,ysize/2, xsize/2);
        steamp += DFS(y+ysize/2, x+xsize/2,ysize/2, xsize/2);
        steamp += ')';
    }
    else 
    {
        steamp+= temp;
    };

    //cout<<steamp<<endl;
    return steamp ;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        for(int j = 0; j  < s.size(); j++)
        {
            arr[i][j] = s[j];
        }
    }

    cout<<DFS(0,0, n,n);
}