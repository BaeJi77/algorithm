#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
vector<int> vt;

int binarySearch(int x) {
    int left = 0;
    int right = vt.size();
    while(left <= right) {
        int mid = (left + right) / 2;
        if(vt[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    int ret = (left + right) / 2;
    if(ret < vt.size() && vt[ret] < x) ret++;
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        if(i == 0) vt.push_back(a);
        else {
            int targetIdx = binarySearch(a);
            auto it = vt.begin() + targetIdx;
            vt.insert(it, a);
        }
        if(vt.size() % 2) printf("%d\n", vt[vt.size() / 2]);
        else printf("%d\n", vt[vt.size() / 2 - 1]);
    }
}