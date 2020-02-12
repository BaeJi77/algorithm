#include <cstdio>
#include <cmath>

using namespace std;

int N;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    int number = pow(2, N) + 1;
    printf("%d", number*number);
}