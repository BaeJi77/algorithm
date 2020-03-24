#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, Q;
int arr[500010];

int main() {
    scanf("%d %d", &N, &Q);
    int pre = 0;
    for(int i = 2 ; i <= N; i++) {
        int k;
        scanf("%d", &k);
        pre ^= k;
        arr[i] = pre;
        // printf("%d ", arr[i]);
    }
    // puts("");
    // Q 0 => prefix sum으로 하면 됨. XOR 연산 특징으로 가능
    // Q 1 => prefix sum과 같이 활용하면 식이 단축되서 간단하게 가능 할 듯
    for(int i = 0 ; i  < Q ; i++) {
        int q,x,y,d;
        scanf("%d", &q);
        scanf("%d %d", &x, &y);
        if(q == 0) {
            printf("%d\n", arr[y] ^ arr[x]);
        } else {
            scanf("%d", &d);
            printf("%d\n", arr[y] ^ arr[x] ^ d);
        }
        // printf("%d %d %d\n", q, x, y);
    }
}