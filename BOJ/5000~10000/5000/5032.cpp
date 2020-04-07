#include <cstdio>
#include <algorithm>

using namespace std;

int e, f, c;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d", &e, &f, &c);
    int nowEmpty = e + f;
    int ans = 0;
    while(1) {
        // printf("%d\n", nowEmpty);
        if(nowEmpty < c)
            break;
        int newDrink = nowEmpty / c;
        ans += newDrink;
        nowEmpty %= c;
        nowEmpty += newDrink;
        
    }
    printf("%d", ans);
}