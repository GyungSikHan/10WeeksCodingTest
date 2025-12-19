#include<bits/stdc++.h>

using namespace std;

int n,m, h, a, b,ret = 987654321;
vector<vector<int>> visited;

bool isControl(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start])
                start++;
            else if(visited[j][start - 1])
                start--;
        }
        if(start != i) return false;
    }
    return true;
}

void Solution(int row, int col,int value)
{ 
	//cout << row << " : " << col << '\n';
    if(value > 3 )
    {
        return;
    }
    if(isControl())
    {
        ret = min(ret, value);
        return;
    } 
    for(int i = row; i <= h; i ++)
    {
        for(int j = 1; j < n; j++)
        {
            if(visited[i][j - 1] || visited[i][j] || visited[i][j + 1])continue; 
            //cout<<i<<" "<<j<<endl;
            visited[i][j] = 1;
            Solution(i + 1, j, value + 1);
            visited[i][j] = 0;
        }
    }
    
}

int main()
{
    cin>>n>>m>>h;
    visited.resize(h + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        visited[a][b] = 1;
    }  
    Solution(1,0,0); 
    if(ret > 3)
        ret = -1;
    cout<<ret;

}