#include<bits/stdc++.h>

using namespace std;
#define MAX 200000
int n,k, ret = 987654321;
int arr[MAX];
int visited[MAX];
int temp[MAX];

int main()
{
    cin>>n>>k;
    arr.resize(k*2, 0);
    visited.resize(k*2, 0);
    temp.resize(k*2,0);
    arr[n] = 1;
    temp.push_back(n);

}