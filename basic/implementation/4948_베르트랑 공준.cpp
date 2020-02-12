#include <cstdio>

using namespace std;

const int MAX = 123456;

int N, era[2*MAX+1];



void init(){
    for(int i = 2 ; i <= MAX*2 ; i++){
        if(era[i] == 1)
            continue;
        for(int j = i+i ; j <= MAX*2 ; j += i){
            era[j] = 1;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    init();
    while(scanf("%d", &N)){
        if(N == 0)
            break;
        int cnt = 0;
        for(int i = N+1; i <= 2*N; i++){
            cnt += era[i] == 0 ? 1 : 0;
        }
        printf("%d\n", cnt);
    }
}