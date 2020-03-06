#include <cstdio>

using namespace std;

int arr[1001];
int preSum[1001];
int N, M;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    int index = 0;
    int step = 1;
    int tempSum = 0;
    
    while(1) {
        if(index == 1001)
            break;
        
        for(int i = 0 ; i < step ; i++){
            index++;
            if(index == 1001)
                break;
            arr[index] = step;
        }
        step++;
    }

    for(int i = 0 ; i <= 1000; i++) {
        tempSum += arr[i];
        preSum[i] = tempSum;
    }

    printf("%d", preSum[M] - preSum[N-1]);
}