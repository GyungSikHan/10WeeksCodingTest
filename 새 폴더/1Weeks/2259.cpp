//V 문제 잘읽기!!
#include<bits/stdc++.h>

using namespace std;

int n,k,ret = -987654321;
int arr[100001];

int solve(int data)
{
    int temp{};
    for(int i = data; i < data+k; i++)
    {
        temp+=arr[i];
    }

    return temp;
}

int main()
{
    cin>>n>>k;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int i =0; i <= n-k; i++)
    {
        int temp = solve(i);
        cout<<"ret "<<ret<<" temp "<<temp<<endl;
        ret = max(ret,temp);
    }

    cout<<ret;

}
