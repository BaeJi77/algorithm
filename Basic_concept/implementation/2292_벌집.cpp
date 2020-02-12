#include <cstdio>

using namespace std;

int N;

//6의 배수씩 숫자는 커짐
/*
1 :    1   1
2~7 :  2   6
8~19 : 3   12

*/

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    int cnt = 0;
    if(N == 1){
        cnt++;
    } else {
        cnt++;
        N -= 1;
        int product = 6;
        while(N > 0){
            // printf("%d %d\n", N, product);
            cnt++;
            N -= product;
            product += 6;
        }
    }

    printf("%d", cnt);
}