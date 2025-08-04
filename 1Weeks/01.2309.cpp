//https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> arr2;
bool b{};

void Solution(int sum, int index, int count)
{
    if(sum > 100 || count > 7)
        return;
    if(sum == 100 && count == 7)
    {
        for(int i : arr2)
            cout<<i<<endl;
        b = true;
        return;
    }
    else if(sum < 100 && count < 7)
    {
        for(int i = index; i < 9; i++)
        {
            arr2.push_back(arr[i]);
            Solution(sum+arr[i], i+1, count+1);
            if(b == true)
                return;
            arr2.pop_back();
        }

    }
}

int main()
{
    arr.resize(9,0);
    for (int i =0; i < 9; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    Solution(0, 0, 0);
}