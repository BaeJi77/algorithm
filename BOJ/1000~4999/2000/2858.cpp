#include <cstdio>
#include <algorithm>

using namespace std;

int R,B;

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d %d", &R, &B);
    int sum = R + B;
    // sqrt(sum);
    
    for(int i = 1 ; i <= sum ; i++) {
        if(sum % i == 0) {
            int l = i;
            int w = sum / i;
            int newRed = i * 2 + (w - 2) * 2;
            int newBrown = sum - newRed;
            if(newRed == R && newBrown == B) {
                printf("%d %d", l > w ? l, w : w, l);
                break;
            }
        }
    }
}