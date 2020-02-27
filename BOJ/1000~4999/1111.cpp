#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N;
int map[51];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &map[i]);
    }

    if(N == 1) {
        printf("A");
        return 0;
    } 
    if(N == 2) {
        if(map[0] == map[1])
            printf("%d", map[0]);
        else
            printf("A");

        return 0;
    }
    
    int x = map[1] - map[0];
    int y = map[2] - map[1];
    int a = x == 0 ? 0 : y / x;
    int b = map[1] - map[0] * a;

    bool checkNoAns = false;
    for(int i = 0 ; i < N - 1 ; i++) {
        if(map[i+1] != map[i] * a + b) {
            printf("B");
            return 0;
        }
    }
    printf("%d", map[N-1] * a + b);
}