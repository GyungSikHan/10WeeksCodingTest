#include<bits/stdc++.h>
using namespace std;

const long long MAX = 4000000;
bool che[MAX+1];
long long n;

vector<long long> era(long long mx_n)
{
    vector<long long> v;
    for(long long i = 2; i <= mx_n; i++)
    {
        if(che[i] == 1)
            continue;
        for(long long j = 2*i; j <= mx_n; j+=i)
        {
            che[j] = 1;
        }
    }

    for(long long i = 2; i <= mx_n; i++)
    {
        if(che[i] == 0)
            v.push_back(i);
    }   

    return v;
}

int main()
{
    cin>>n;
    vector<long long> a = era(n);
    // for(auto iter : a)
    //     cout<<iter<<endl;
    long long cnt{};
    long long s = 0; 
    long long e = 0;
    long long sum = 0;
    //s, e
    while(true){
        //cout<<"sum "<<sum<<" s "<< s<<" e "<< e<<endl;
        if(sum >= n){
            if(sum == n)cnt++;
            sum -= a[s];
            s++;
        }else{  
            if(e == a.size())break;
            sum+=a[e];
            e++; 
        } 
    } 
    cout<<cnt;
}