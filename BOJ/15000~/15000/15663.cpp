#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<int> nums;
set<vector<int> > st;

void solve(vector<int> numbers, int bit) {
    if(numbers.size() == M) {
        st.insert(numbers);
        return;
    }

    for(int i = 0 ; i < N ; ++i) {
        if(bit & 1<<i) continue;
        numbers.push_back(nums[i]);
        solve(numbers, bit | 1<<i);
        numbers.pop_back();
    }
}

// O(?)
// N개의 값을 받고 그것을 나열 + 사용했던 index 사용 X + 입력 값이 중복된 값
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
    solve(temp, 0);
    for(auto numbers : st) {
        for(auto val : numbers) {
            printf("%d ", val);
        }
        puts("");
    }
}