#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void solve(vector<int> numbers) {
    if(numbers.size() == M) {
        for(auto val : numbers)
            printf("%d ", val);
        puts("");
        return;
    }

    for(int i = 1 ; i <= N ; ++i) {
        numbers.push_back(i);
        solve(numbers);
        numbers.pop_back();
    }
}

// O(N ^ M)
// 값 중복허용
int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    vector<int> temp;
    solve(temp);
}