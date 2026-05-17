#include<bits/stdc++.h>

using namespace std;

int n, m, ret = 987654321;
vector<int> ju;
int lo, hi, mid;

bool Solution(int num)
{
    //cout<<endl;
    //cout<<num<<endl;
    int cnt{};
    for(auto iter : ju)
    {
        cnt += iter / num;
        if(iter % num != 0)
            cnt += 1;
        //cout<<cnt<<endl;
    }
    if(cnt > n)
        return false;
    return true;
}

int main()
{
    cin>>n>>m;
    ju.resize(m,0);
    for(int i = 0; i < m; i ++)
    {
        cin>>ju[i];
        hi = max(ju[i], hi);
    }
    while(lo <= hi){
        mid = (hi+lo)/2;
        if(Solution(mid)){ 
            //cout<<"RET"<<mid<<endl;

            ret = mid;
            hi = mid - 1;  
        }else{
            lo = mid + 1; 
        }
    }

    cout<<ret;

}