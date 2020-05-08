#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void solve(vector<int> numbers, int pre) {
    if(numbers.size() == M) {
        for(auto val : numbers)
            printf("%d ", val);
        puts("");
        return;
    }

    for(int i = pre ; i <= N ; ++i) {
        numbers.push_back(i);
        solve(numbers, i);
        numbers.pop_back();
    }
}

// O(?)
// 값 중복허용 + 비내림차순 (역으로 가는 수가 있으면 안됨)
int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    vector<int> temp;
    solve(temp, 1);
}