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

    vector<int> nums;
    for(int i = 0 ; i < N ; i++) {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    
    sort(nums.begin(), nums.end());

    for(int p : nums)
        printf("%d ", p);
    
}