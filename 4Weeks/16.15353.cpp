#include <iostream>
#include <string>

using namespace std;

string a, b;
string ret;

string Solution(string big, string smal)
{
	int next{};
	int size = smal.size();

	int index = big.size() - 1;
	int index2 = smal.size() - 1;
	string temp{};
	while (index2 >= 0)
	{
		int sum = next;
		sum += (big.at(index--)-'0') + (smal.at(index2--) - '0');
		if (sum > 9)
		{
			next = 1;
			temp+=std::to_string((sum % 10));
		}
		else
		{
			next = 0;
			temp += std::to_string(sum);
		}
		
	}
	if (next == 1)
		temp +=std::to_string(next);
	return  temp;
}

int main()
{
	cin >> a >> b;
	int m{};
	bool bo{};
	if (a.size() > b.size())
		ret = Solution(a,b);
	else
		ret = Solution(b,a);

	for (int i = ret.size() - 1; i >= 0; i--)
		cout << ret[i];

}