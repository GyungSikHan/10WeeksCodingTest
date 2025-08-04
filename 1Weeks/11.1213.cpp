// https://www.acmicpc.net/problem/1213 V
#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s{};
    cin>>s;
    int arr[26]{};
    for (int i = 0; i < s.size(); i++) 
        arr[s.at(i) - 'A']++;

    string ret{};
    int flag{};
    char mid{};
    bool b{};
    for (int i = 25; i >= 0; i--) 
    {
        if(arr[i] == 0)
            continue;

        if(arr[i] % 2 == 1)
        {
            mid = i + 'A';
            arr[i]--;
            flag++;
        }
        else if(flag >= 2)
        {
            b = true;
            break;
        }
        
        if(arr[i] != 0)
        {
            while (arr[i] != 0) 
            {
                int temp = i + 'A';
                ret += (char)temp;
                ret = (char)temp + ret;
                arr[i] -= 2;
            }
        }
    }

    if(flag >= 2)
        cout<<"I'm Sorry Hansoo"<<endl;
    else
    {
        if(flag == 1)
            ret.insert(ret.begin()+ ret.size()/2 , mid);

        cout<<ret<<endl;
    }
}

//펠린드롬을 만들땐 홀수의 갯수가 2개이상이면 될 수 없다
//이를 생각하고 알파벳 오름차순으로 string의 앞뒤에 알파벳을 추가해주면 된다
//이때 홀수 갯수의 알파벳이 하나 존재한다면 다른곳에 저장해두었다가 결과값에 string::insert 함수를 이용해 중간에 넣어주어 출력하면 다