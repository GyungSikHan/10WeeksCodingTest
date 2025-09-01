#include <iostream>
#include <vector>

using namespace std;

int n, a;
vector<int> arr;

int Check(int data)
{
	if (data <= 1)
		return 0;
	else if (data == 2)
		return 1;
	else if (data % 2 == 0)
		return 0;

	//소수를 구할 때 data와 i*i를 비교하는 이유는 data의 공약수들을 보면 된다
	//예를 들어 36이라는 수를 보자
	//공약수들은 1,2,3,4,6,9,12,18,36이 있다
	//이들을 약수의 쌍으로 묶어보면 (1,36) (2,18) (3,12) (4,9) (6,6)이다
	//i를 모두 비교하는 것이 아닌 약수의 쌍중 작은 값과 큰 값의 결과는 같으므로 작은 값들만 비교하면
	//연산량을 크게 줄일 수 있다
	for (int i = 3; i * i <= data; i++)
		if (data % i == 0)
			return 0;

	return 1;
}

int Solution(int index, int sum)
{
	if (count == n)
		return Check(sum);

	return Solution(index + 1, sum + arr[index]) + Solution(index + 1, sum);
}

int main()
{
	cin >> n;
	arr.assign(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		
		arr[i] = a;
	}

	int num{};
	Solution(0,0);

	cout << num << endl;
}