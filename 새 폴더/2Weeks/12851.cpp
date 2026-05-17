//x 범위 잘 생각해서 풀기
#include <bits/stdc++.h>

using namespace std;
#define LAST 200010
int n, k;
vector<int> arr;
int cnt, ret = 987654321;

void BFS()
{
    queue<int> qu;
    qu.push(n);
    arr[n] = 1;

    while(qu.empty() == false)
    {
        int curr = qu.front();
        qu.pop();

        if(curr == k)
        {
                //cout<<"curr "<<curr<<endl;
            if(arr[curr] < ret)
            {
                //cout<<"<"<<endl;
                ret = arr[curr];
                cnt = 1;
            }
            else if(arr[curr] == ret)
            {
                //cout<<"=="<<endl;
                cnt++;
            }
            //cout<<endl;

            continue;
        }

        for(int next : {curr -1, curr + 1, curr*2})
        {
            if(next < 0 || LAST <= next)
                continue;
            if(arr[next] != 0 && arr[next] < arr[curr] + 1)
                continue;
            //cout<<"for "<<next<<endl; 
            qu.push(next);
            arr[next] = arr[curr] + 1;
        }
        //cout<<endl;
    }
}


int main()
{
    cin >> n >> k;
    arr.resize(LAST, 0);
    arr[n] = 1;

    BFS();
    cout << ret - 1 << "\n";
    cout << cnt << "\n";
}