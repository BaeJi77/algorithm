#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[30001];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    int nowIndex = 0;
    int nowTopHeight = 0;
    int killCnt = 0;
    int ret = 0;
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
        if(nowTopHeight < arr[i]) {
            nowIndex = i;
            nowTopHeight = arr[i];
            ret = max(ret, killCnt);
            killCnt = 0;
        }
        if(nowTopHeight > arr[i]) {
            killCnt++;
        }
    }

    ret = max(ret, killCnt);

    printf("%d", ret);
}