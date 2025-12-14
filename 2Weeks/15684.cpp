#include<bits/stdc++.h>

using namespace std;

int n,m, h, a, b,ret = 987654321;
vector<vector<int>> visited;

bool isControl(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][i])
                start++;
            else if(visited[j][ i - 1])
                start--;
        }
        if(start != i) 
            return false;
        //cout<<start<<endl;
    }
    return true;
}

void Solution( int row, int col,int value)
{ 
    if(value > 3 )
    {
        return;
    }
    if(isControl())
    {
        ret = min(ret, value);
        return;
    }

    //cout<<"test"<<endl;
    //사다리를 놓는 함수호출

    for(int i = row; i <= n; i ++)
    {
        for(int j = col; j <= h; j++)
        {

            if(visited[i][j - 1] || visited[i][j] || visited[i][j + 1])
            {
                //cout<<i<<" "<<j<<endl<<endl;
                continue;
            } 
            cout<<i<<" "<<j<<endl;
            visited[i][j] = 1;
            Solution(i + 1, j, value + 1);
            visited[i][j] = 0;
        }
    }
    
}

int main()
{
    cin>>n>>m>>h;
    visited.resize(h+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        visited[a][b] = 1;
    }  
    Solution(1,1,0);

    if(ret > 3)
        ret = -1;
    cout<<ret;

}