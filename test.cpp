#include<bits/stdc++.h>

using namespace std;

int n;
int arr[104];
float aver;

int main()
{
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        aver += arr[i];
    }
    
    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    aver/=n;
    cout<<fixed<<setprecision(2)<<aver;
}