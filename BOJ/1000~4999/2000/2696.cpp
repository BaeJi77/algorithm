#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <deque>

using namespace std;

int N;
vector<int> vt;

int findIndexUsingBinarySearch(int val) {
    int left = 0;
    int right = vt.size();
    while(left <= right) {
        int mid = (left + right) / 2;
        if(vt[mid] > val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return (left + right) / 2;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        vt.clear();
        vector<int> ans;
        scanf("%d", &N);
        printf("%d\n", (N + 1) / 2);
        for(int i = 0 ; i < N ; ++i) {
            int a;
            scanf("%d", &a);
            if(i == 0) vt.push_back(a);
            else {
                int targetIdx = findIndexUsingBinarySearch(a);
                if(targetIdx != vt.size() && vt[targetIdx] < a) targetIdx++;
                auto it = vt.begin() + targetIdx;
                vt.insert(it, a);
            }

            if(vt.size() % 2) ans.push_back(vt[vt.size() / 2]);
        }
        for(int i = 0 ; i < ans.size() ; ++i) {
            if(i != 0 && (i % 10) == 0) puts("");
            printf("%d ", ans[i]);
        }
        puts("");
    }
}