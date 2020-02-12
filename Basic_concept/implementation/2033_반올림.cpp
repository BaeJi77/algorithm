#include <cstdio>

using namespace std;

int N;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    
    int i = 10;
    while(N > i){
        int line = i/2;
        int temp = N % i;
        if(temp >= line){
            N -= temp;
            N += i;
        } 
        else {
            N -= temp;
        }
        i *= 10;
    }
    printf("%d", N);
}