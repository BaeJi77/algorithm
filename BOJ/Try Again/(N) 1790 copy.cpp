#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

// N은 1억, K는 10억
ll N, K; 
// ll left, right, product;
ll kNumber[20];
ll digitNumber[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    ll left, right, product;
    left = 1;
    right = 10;
    product = 10;
    ll digit = 2;
    while(1) {
        printf("%d %d %d %d\n", left, right, product, digit);
        if(left <= K && K < right) {
            // 범위 안에 있습니다.
            

            // N보다 큰 경우 생각
        }
        
        left = right;
        right += 9 * product * digitNumber[digit++];
        product *= 10;
    }
}