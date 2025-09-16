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

//?�린?�롬??만들???�?�의 �?��가 2개이?�이�??????�다
//?��? ?�각?�고 ?�파�??�름차순?�로 string???�뒤???�파벳을 추�??�주�??�다
//?�때 ?�??�?��???�파벳이 ?�나 존재?�다�??�른곳에 ?�?�해?�었?��? 결과값에 string::insert ?�수�??�용??중간???�어주어 출력?�면 ?