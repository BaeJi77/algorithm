#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int maxIdx = -1;
    int maxValue = -1;
    for(int i = 0 ; i < 9 ; i++) {
        int k;
        scanf("%d", &k);
        if(maxValue < k) {
            maxIdx = i;
            maxValue = k;
        }
    }
    printf("%d\n%d", maxValue, maxIdx + 1);
}
