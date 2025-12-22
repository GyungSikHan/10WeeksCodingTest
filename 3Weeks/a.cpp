
#include<bits/stdc++.h>

using namespace std;

int n, ret = 987654321;
int mp,mf,ms,mv;
int arr[15][5];
vector<int> temp; 
vector<vector<int>> vi;

void Solve(int x, int p, int f, int s, int v, int price)
{
	if(price > ret)
		return;
    if(x == n + 1){
		if(p >= mp && f >= mf && s >= ms && v >= mv)
		{ 
			if(price < ret)
			{
				ret = price;
				vi.erase(vi.begin());
				vi.push_back(temp);
			}
			else if(price == ret)
			{
				vi.push_back(temp);
			}
			return;
		}
		return;
	} 

    temp.push_back(x);
    Solve(x+1, p+arr[x][0], arr[x][1]+f, arr[x][2] + s, arr[x][3] + v, price + arr[x][4]);
    temp.pop_back();
    Solve(x+1,p,f,s,v,price);
}

int main()
{   
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
    }


    Solve(1,0,0,0,0,0);
    if(ret == 987654321)
        cout<<-1<<"\n";
    else
    {
        sort(vi.begin(), vi.end());
        cout<<ret<<"\n";
		for(int i = 0; i < vi[0].size(); i++)
		{
			cout<<vi[0][i]<<" ";
		} 
    }
   
}   