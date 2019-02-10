#include <iostream>

using namespace std;

const int INF = 1000000;
int n, k, coins[10004];

int func(int money){
    if(money == 0){
        return 0;
    }

    int ret = INF;
    //가장 중요한 것은 for을 통해서 함수를 재귀적으로 호출. 혹은 if문을 통한 체크가 중요하다.
    for(int i = 0 ; i < n ; i++){
        const int coin = coins[i];

        //F(n) => n원을 만드는데 사용한 최소 동전의 수
        //F(n - coin) => n - coin원을 만드는데 사용한 최소 동전 수
        //F(n) = F(n - coin) +1 => 
        //왜 +1이 되느냐? 함수의 정의 자체가 동전의 수 이기때문에 coin을 빼주는데 사용하는데 동전 1개를 더 사용했다고 생각했기 때문에
        //F(n) = min(F(n - coin) + 1, F(n)) => 동전의 수가 많기 때문에 모든 경우를 다 생각해서 F(n)의 값을 지정하겠다.
        if(money >= coin){
            ret = min(ret,func(money - coin)+1);
        }
    }

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i];
    }   

}