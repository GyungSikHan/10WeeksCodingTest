//     ==
// double
// a, b
// if(abs(a - b) < 0.003){

// }
// 5.15 -> 515
#include <bits/stdc++.h>

using namespace std;
#define MAX 100
double t1,t2;
bool area[MAX + 1];
double dp[20][20][20];

double go(int idx, int g1, int g2)
{
    if(idx == 18)
    {
        if(area[g1] == false || area[g2] == false)
            return 1; 
        return 0;
    }
    
    //cout<<"Start"<<endl;
    double & ret = dp[idx][g1][g2];
    //cout<<"TT "<<ret<<endl;
    if(ret > -0.5)
    {
        //cout<<"ret != -1: "<<ret<<endl;  
        return ret;
    }
    //cout<<"ret == -1: "<<ret<<endl;
    ret=0;

    //cout<<"END"<<endl;
    double temp = go(idx+1, g1+1, g2+1) * t1 * t2;
    //cout<<"2Gole: "<<temp<<endl;
    ret += temp;
    temp = go(idx+1, g1+1, g2) * t1 * (1 - t2);
    //cout<<"t1 Gole: "<<temp<<endl;
    ret += temp;
    temp = go(idx+1, g1, g2+1) * (1 - t1) * t2;
    //cout<<"t2 Gole: "<<temp<<endl;
    ret += temp;
    temp = go(idx+1, g1, g2) * ((1-t1)* (1-t2));
    //cout<<"NoGole: "<<temp<<endl;
    ret += temp;

    return ret;
}

int main()
{
    cin>>t1>>t2; 

    t1 /= 100;
    t2 /= 100;

    memset(area, false, sizeof(area));
    area[0] = true;
    area[1] = true;

    for(int i = 2; i <= sqrt(MAX);i++)
    {
        if(area[i] == true)
            continue;
        for(int j = i+i; j <= MAX ; j+=i)
        {
            area[j] = true;
        }
    }

    memset(dp, -1.0, sizeof(dp));
    //cout<<dp[0][0][0]<<endl;
    double ret = go(0,0,0); 
    printf("%.6f", ret);
    //cout<< setprecision(6) << ret <<"\n";
}
