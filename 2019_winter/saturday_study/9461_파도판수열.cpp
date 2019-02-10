#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dp[110] = {0,1,1,1,2,2}; // 기저사례를 미리 알고있기 때문에 미리 선언해서 사용
// a(n)=a(n-1)+a(n-5)
long long func(int p){
    // if(p == 1 || p == 2 || p == 3){
    //     return 1;
    // }else if(p == 4 || p == 5){
    //     return 2;
    // }
    
    long long &ret = dp[p];
    if(ret != -1)
        return ret;

    return dp[p] = func(p-1) + func(p-5);
}


int main(){
    freopen("input.txt","r",stdin);
    fill(dp, dp+110, -1);
    int T;
    cin>>T;
    
    for(int i = 0 ; i < T ; i++){
        cin>>N;    
        cout<<func(N)<<endl;;
    }
}