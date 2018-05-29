#include <cstdio>
#include <iostream>
using namespace std;

int n, k, temp;
int cnt;
int main() {
    scanf("%d %d", &n, &k);
    while (k--) {
        scanf("%d", &temp);
        if (temp == 4 || temp == 3) cnt += 2;
        if (temp == 6 || temp == 5) cnt += 3;
        if (temp == 8 || temp == 7) cnt += 4;
    }
    if (n < cnt) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
