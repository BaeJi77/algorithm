#include <cstdio>

using namespace std;

int N,S,num[24];

int func(int i, int sum,int cnt){
    //1. 기저 사례 확인
    if(i == N ){
        return sum == S && cnt != 0 ? 1:0; // 왜냐하면 경우의 수 이기때문에 마지막 하나의 경우의 수를 말함
    }
        
    //2. 재귀 호출
    int ret = func(i+1, sum, cnt) + func(i+1, sum+num[i], cnt+1);

    //3. 반환
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &N,&S);
    for(int i = 0 ; i  < N ; i++){
        scanf("%d" , &num[i]);
    }

    int cnt = func(0,0,0);
    
    
    printf("%d" , cnt);
}
