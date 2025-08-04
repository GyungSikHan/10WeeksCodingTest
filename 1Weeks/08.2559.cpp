//https://www.acmicpc.net/problem/2559  V
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n{}, m{};
    cin>>n>>m;
    vector<int> v(n,0);
    int ret = -987654321;
    for (int i = 0; i < n; i++) 
        cin>>v[i];
    
    for (int i = 0; i <= n-m; i++) 
    {
        int temp{};
        for (int j = i; j < m+i; j++) 
        {
            temp += v[j];
        }

        ret = max(ret, temp);
    }

    cout<<ret<<"\n";
}

//누적합을 이용하려했지만 그게 아니였음
//첫날 온도를 vector에 저장 m개씩 묶어 더한 뒤 값을 비교하면 되는 문제
//온도를 잰 총 날에서 m일을 뺀뒤 +1을 하면 연속적인 m일동안 온도의 합을 구할 수 있는 갯수가 나옴 -> n=10, m = 5라면 10일동안 5개씩 묶어 더한 결과의 갯수가 5+1 = 6개
//이를 반복문에 적용하고, 이중 for문을 통해 첫번째 더할 날인 i부터 m+i까지 반복을 하면서 임시 변수 temp에 v[j]값을 모두 더함 
// -> i = 0~ i <= n-m으로 위의 결과와 같이 나오는 조건을 가진 첫번째 반복문이 될것임, 두번째 반복문은 더하기 시작할 날짜, 즉 0~m, 1~m+1 이런식으로 조건문이 달성될 것임
//-> 위의 조건대로 반복문을 적용하면 v[0]+v[1]...+v[m]이런식으로 시작 날짜부터 m일이 지난 온도의 합을 구할 수 있음
//이제 이를 ret이라는 변수에 max함수를 사용해 제일 큰 값을 구해 ret에 저장해주면 됨