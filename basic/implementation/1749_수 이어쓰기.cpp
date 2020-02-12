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
    int pre = 1;
    int next = 10;
    int digit = 1;
    bool end = 0;
    while(1){
        for(int i = pre ; i < next ; i++){
            // printf("%d %d %d\n", i, digit, cnt);
            if(i > N){
                end = 1;
                break;
            }
            cnt += digit;
        }

        if(end)
            break;
        pre *= 10;
        next *= 10;
        digit++;
    }
    printf("%d\n", cnt);
}