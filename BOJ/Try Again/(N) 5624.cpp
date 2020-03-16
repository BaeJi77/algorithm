#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[5010];

int cal(int index, int nowValue) {
    if(index - 1 == 0) {
        return arr[index - 1] * 3 == nowValue;
    } else if (index - 2 == 0) {
        int a = (arr[index - 1] * 3) == nowValue;
        int b = (arr[index - 2] * 3) == nowValue;
        int c = (arr[index - 1] * 2 + arr[index - 2] * 1) == nowValue;
        int d = (arr[index - 1] * 1 + arr[index - 2] * 2) == nowValue;
        
        if(a+b+c+d) return true;
        else return false;
    } else {
        int ret = 0;
        for(int i = index - 1 ; i >= index - 3; i--) {
            for(int j = index - 1 ; j >= index - 3; j--) {
                for(int k = index - 1 ; k >= index - 3; k--) {
                    ret += arr[i] + arr[j] + arr[k];
                }
            }
        }

        if(ret) return true;
        else return false;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = 0;
    for(int i = 1 ; i < N ; i++) {
        ans += cal(i, arr[i]);
    }

    printf("%d", ans);
}