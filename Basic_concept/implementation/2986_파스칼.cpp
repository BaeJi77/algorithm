#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX = 1e9;

int N;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);

    int ans = 1;
    for(int i = 2 ; i <= sqrt(N) ; i++){
        if(N % i == 0){
            ans = N/i;
            break;
        }
    }

    printf("%d", N - ans);
}