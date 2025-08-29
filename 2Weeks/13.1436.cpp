//https://www.acmicpc.net/problem/1436 v
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n{};
int number = 666;

void Solution()
{
	number++;

	if (std::to_string(number).find("666") == string::npos)
		Solution();
}

int main()
{
	cin >> n;
	if (n != 1)
		while (n != 1)
		{
			Solution();
			n--;
		}

	cout<<number<<endl;
}