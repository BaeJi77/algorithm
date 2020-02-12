#include <cstdio>

using namespace std;

int N;

int gcd(int a,int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int func(int a,int b){
    if(b == 0)
        return a;
    return func(b, a%b);
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        int a,b;
        scanf("%d %d" , &a,&b);
        printf("%d\n" , a*b/func(a,b));
    }
}