#include <cstdio>
#include <algorithm>

using namespace std;

int N, ret;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    if(N <= 1)
        ret = 1;
    else {
        int k = 1;
        int tempRet = 1;
        while(1) {
            k *= 10;
            k++;
            if(N >= k)
                tempRet++;
            else
                break;
        }
        ret = tempRet;
    }
    printf("%d", ret);
}