//https://www.acmicpc.net/problem/1629 V
#include<iostream>

using namespace std;

long long a{},b{},c{};

long long Solution(long long data, long long data2)
{
    if(data2 == 1)
        return data % c;

    long long temp = Solution(data, data2/2);
    temp = (temp*temp)%c;
    if(data2 %2 == 1)
        temp =  (temp*data) %c;

    return temp;
}

int main()
{
    cin>>a>>b>>c;
    
    cout<<Solution(a, b)<<endl;
}

//수학적으로 접근해서 풀면 되는 문제
//A = 2^4라고 한다면 A*A = 2^4 * 2^4이다
//또한 분배법칙에 의해 (A*A) % C = A%C * A%C가 된다
//이를 이용해 재귀 함수를 이용해 풀면 된다
//몇번 곱할지를 나타내는 b를 2로 나눠가며 함수를 계속 타고 들어가다보면 b가 1이 되는데 이때가 함수 탈출 조건으로 data % c를 통해 나머지 값을 구해 리턴해준다
//탈출 후 temp에 저장한 뒤 temp * temp % c를 통해 A*A % c를 완성해준다
//이를 반복하면 A ^ B % C를 구할 수 있다
// 하지만 이는 짝수만 구할 수 있으므로 홀수일 경우 하나의 경우를 더 해줘야한다
// 예를들어 2^5라 한다면 2^2 * 2^2 * 2로 2^2를 A라 한다면 A*A*2를 해야되는데 이를 temp = temp * data % c를 통해 홀수도 구할 수 있게된다