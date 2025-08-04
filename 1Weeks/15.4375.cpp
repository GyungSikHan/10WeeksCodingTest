//https://www.acmicpc.net/problem/4375 V
#include<iostream>
using namespace std;

int n{};
int main()
{
    while (scanf("%d", & n) != EOF) 
    {

        unsigned long long index = 1;
        unsigned long long data = 1;

        while(n != 1)
        {
            if(data == 0)
            {
                cout<<index<<"\n";
                break;
            }
            data = ((10 * data) + 1) % n;
            index++;
        }
        if(n == 1)
            cout<<1<<endl;
    }
}

//모듈러 연산을 이용해서 풀면 된다