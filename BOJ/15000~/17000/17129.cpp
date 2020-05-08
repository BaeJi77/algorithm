#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 2e5;

int N, Q;
int cow[MAX+1];
int prefixCow[MAX+1];
int prefixSum;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &Q);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &cow[i]);
    }

    for(int i = 0 ; i < N ; i++) {
        int temp = 1;
        for(int j = 0 ; j < 4; j++) {
            temp *= cow[(i + j) % N];
        }
        prefixCow[i] = temp;
        prefixSum += temp;
    }

    for(int i = 0 ; i < Q ; i++) {
        int q;
        scanf("%d", &q);
        q--;
        int preValue = 0;
        int nowValue = 0;
        
        for(int j = 0 ; j < 4; j++) {
            int index = (q - j) < 0 ? q - j + N : q - j;
            preValue += prefixCow[index];
            prefixCow[index] *= (-1);
            nowValue += prefixCow[index];
        }
        prefixSum += nowValue - preValue;
        printf("%d\n", prefixSum);
    }
}