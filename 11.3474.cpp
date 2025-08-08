//https://www.acmicpc.net/problem/3474 v
#include<iostream>
#include <cmath>
using namespace std;

int t;
long long n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(nullptr);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int temp1{};
		int temp2{};
		for (int j = 2; j <= n; j *= 2)
			temp1 += n / j;
		for (int j = 5; j <= n; j *= 5)
			temp2 += n / j;
		cout << min(temp1, temp2) << "\n";

	}
}

//전형적으로 아이디어 싸움에서 진 문제
//n!에서 뒤에 0이 들어가는 경우는 10이 곱해진 경우밖에 없다
//따라서 10의 공약수인 2와 5개 n 수까지 들어가는 갯수를 비교해 더 작은 값을 출력해주면 된다
//예를들어 n=10일때 2는 2(1개),4(2개),6(1개),8(3개),10 (1개) 8개, 5는 5(1개),10(1개) 2개로 이중 작은 값인 2개가 된다
//이를 i = 1부터 n까지 전부 2,5로 나누면서 나머지가 없는 모든 수를 구하면 시간이 어마무시하게 걸릴 것이다
//그래서 2,5의 제곱근을 이용해 i=1부터 n까지 나눠지는 수를 구해 더한뒤 비교하면 된다
//예를들어 2^x -> x==1 : 2,4,6,8,10   x == 2: 4,8    x == 3 : 8 -> 총 8개로 처음에 무식하게 구한 값과 같다
//마찬가지로 5^x -> x == 1 : 5,10 -> 총 2개가 나온다
//사실 2로 구하는 값이 5보다 항상 많아 5로만 구해도 된다