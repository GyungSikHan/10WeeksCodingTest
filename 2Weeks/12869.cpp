#include<bits/stdc++.h>

using namespace std;

int attack[6][3]
{
    {9,3,1}, {9,1,3},
    {3,9,1}, {3,1,9},
    {1,9,3}, {1,3,9}
};

int n;
int scv[3];
int arr[61][61][61];
int ret = 987654321;

void Solution(int a, int b, int c, int count)
{
    if(a == 0 && b == 0 && c == 0)
    {
        ret= min(ret, arr[a][b][c] -1);
        return;
    }

    for(int i = 0; i < 6; i++)
    {
        int temp = a - attack[i][0];
        int temp2 = b - attack[i][1];
        int temp3 = c - attack[i][2];
        if(temp <=0)
            temp = 0;
        if(temp2 <= 0)
            temp2 = 0;
        if(temp3 <= 0)
            temp3 = 0;
        if(arr[temp][temp2][temp3] != 0 && arr[temp][temp2][temp3] < arr[a][b][c] + 1)
            continue;
        arr[temp][temp2][temp3] = arr[a][b][c] + 1;

        //cout<<temp <<" "<<temp2<<" "<<temp3<<endl;
        Solution(temp, temp2, temp3, count+1);
    }
}

int main()
{
    cin>>n;
    for(int i = 0 ;i<n;i++)
    {
        cin>>scv[i];
    }
    
    arr[scv[0]][scv[1]][scv[2]] = 1;
    Solution(scv[0],scv[1],scv[2],1);

    cout<<ret;
}