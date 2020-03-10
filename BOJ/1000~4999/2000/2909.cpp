#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    int modNumber = 1;
    for(int i = 0 ; i < K ; i++)
        modNumber *= 10;

    int halfNumber = modNumber / 2;
    
    int tempN = N + halfNumber;
    printf("%d", (tempN / modNumber) * modNumber);
}