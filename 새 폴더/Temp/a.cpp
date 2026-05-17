#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> se;

    string temp{};
    int idx{};
    int idx2{};
    int cnt{};
    for(auto iter : words)
    {
        if(se.find(iter) != se.end())
        {
            break;
        }
        else if(iter.back() != temp.front())
        {
            break;
        }
        temp = iter;
        se.insert(iter);
        idx++;
        idx = idx % n;
        idx2++;
        if(idx2 > 3)
        {
            cnt++;
            idx2 = 0;
        }
    }

    answer.push_back(idx);
    answer.push_back(cnt);
    return answer;
}

int main()
{
    int n{};
    vector<string> worlds {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    cin>>n;

    solution(n,worlds);
}