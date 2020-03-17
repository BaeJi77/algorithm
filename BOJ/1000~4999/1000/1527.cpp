#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
vector<int> vt;

const int number[] = {4, 7};

void sol(int preNumber, int digit) {
    preNumber *= 10;
    if(digit == 1) {
        for(int i = 0 ; i < 2; i++) {
            vt.push_back(preNumber + number[i]);
        }
    } else {
        for(int i = 0 ; i < 2 ; i++) {
            sol(preNumber + number[i], digit - 1);
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &A, &B);

    vt.push_back(4);
    vt.push_back(7);
    int digit = 2;
    while(1) {
        if(digit == 10)
            break;
        for(int i = 0 ; i < 2 ; i++) {
            sol(number[i], digit - 1);
        }
        
        digit++;
    }

    int ans = 0;
    for(int i = 0 ; i < vt.size() ; i++) {
        if(A <= vt[i] && vt[i] <= B) {
            ans++;
        }
    }
    printf("%d\n", ans);
}