#include <cstdio>

using namespace std;

int N;


//1~9 :9
//10~99: 90
//100~999: 900
//1000~9999: 9000
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    int cnt = 0;
    int temp = 0;
    for(int i = 1 ; i <= N ; i *= 10){
        int check = 0;
        temp = i;
        while(1){
            temp /= 10;
            check++;
            if(temp == 0)
                break;
        }
        printf("%d %d\n", i, check);
        cnt += check * i * 9;
    }
    printf("%d\n", cnt);
}