#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 3e5;

int N;
int arr[MAX+10];

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = 0;
    int nowNumber = N;
    for(int i = N-1 ; i >= 0 ; i--) {
        if(nowNumber == arr[i]) nowNumber--;
        else ans++;
    }

    printf("%d", ans);
}