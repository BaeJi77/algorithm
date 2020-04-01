#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int nmap[150];
int mmap[150];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    int nowDist = 0;
    for(int i = 0 ; i < N ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        for(int j = nowDist; j < nowDist + a ; j++) {
            nmap[j] = b;
        }
        nowDist += a;
    }

    nowDist = 0;
    for(int i = 0 ; i < M ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        for(int j = nowDist; j < nowDist + a ; j++) {
            mmap[j] = b;
        }
        nowDist += a;
    }
    
    int ret = 0;
    for(int i = 0 ; i < 100 ; i++) {
        ret = max(ret, mmap[i] - nmap[i]);
    }
    
    printf("%d", ret);
}