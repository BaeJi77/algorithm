#include <cstdio>

using namespace std;

int fun(int n){
    if(n==1)
        return 1;
    int ret = n + fun(n-1);
    return ret;
}

int main(){
    int N = 10;
    printf("%d" , fun(N));
}
