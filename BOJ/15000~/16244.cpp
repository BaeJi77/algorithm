#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e5;

int N, psum, last, lastIndex;
int arr[MAX+1];
vector<int> sol;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N - 1 ; i++) {
        int a;
        scanf("%d", &a);
        psum += a;
        arr[i] = a;
    }
    int a;
    scanf("%d", &a);
    last = a;
    arr[N-1] = a;
    lastIndex = N-1;
    
    int k = 0;
    int nowTargetIndex = N-1;
    while(1) {
        if(psum == last) {
            lastIndex = nowTargetIndex;
            break;
        }
        psum += arr[nowTargetIndex];
        psum -= arr[k];
        nowTargetIndex = k;
        last = arr[k]; 
        k++;
    }

    for(int i = 0 ; i < N ; i++ ) {
        if(i == lastIndex)
            continue;
        sol.push_back(arr[i]);
    }
    sol.push_back(arr[lastIndex]);

    for(int i = 0 ; i < N ; i++)
        printf("%d ", sol[i]);
}