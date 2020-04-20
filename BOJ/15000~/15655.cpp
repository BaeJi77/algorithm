#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;

void solve(vector<int> numbers, int bit, int idx) {
    if(numbers.size() == M) {
        for(auto val : numbers)
            printf("%d ", val);
        puts("");
        return;
    }

    for(int i = idx + 1 ; i < N ; ++i) {
        if(bit & 1<<i) continue;
        numbers.push_back(nums[i]);
        solve(numbers, bit | 1<<i, i);
        numbers.pop_back();
    }
}

// O(?)
// N개의 값을 받고 그것을 나열 + 중복 X + 오름차순
int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    vector<int> temp;
    solve(temp, 0, -1);
}