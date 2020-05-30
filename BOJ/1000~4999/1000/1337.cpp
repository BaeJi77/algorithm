#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);

    int N;
    scanf("%d", &N);
    
    vector<int> numbers;
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        numbers.push_back(k);
    }

    sort(numbers.begin(), numbers.end());

    int ans = 5;

    int left = 0;
    int right = 0;
    while(right < numbers.size()) {
        ans = min(ans, 5 - (right - left));

        if(numbers[right] - numbers[left] >= 5) {
            left++;
        } else {
            right++;
        }
    }
    ans = min(ans, 5 - (right - left));

    printf("%d", ans);
}