#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void solve(vector<int> numbers, int pre ,int bit) {
    if(numbers.size() == M) {
        for(auto val : numbers)
            printf("%d ", val);
        puts("");
        return;
    }

    for(int i = pre + 1 ; i <= N ; ++i) {
        if(bit & 1<<i) continue;
        numbers.push_back(i);
        solve(numbers, i ,bit | 1<<i);
        numbers.pop_back();
    }
}

// O(?)
int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    vector<int> temp;
    solve(temp, 0, 0);
}