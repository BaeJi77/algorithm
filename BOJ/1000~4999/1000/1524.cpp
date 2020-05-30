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

bool comp(int x, int y) {
    return x > y;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    

    while(tc--) {
        int N, M;
        scanf("%d %d", &N, &M);

        vector<int> vn;
        vector<int> vm;
        for(int i = 0 ; i < N ; i++) {
            int a;
            scanf("%d", &a);
            vn.push_back(a);
        }

        for(int i = 0 ; i < M ; i++) {
            int a;
            scanf("%d", &a);
            vm.push_back(a);
        }

        sort(vn.begin(), vn.end(), comp);
        sort(vm.begin(), vm.end(), comp);

        while(1) {
            if(vn.size() == 0 || vm.size() == 0) break;
            
            if(vn[vn.size() - 1] == vm[vm.size() - 1] || vn[vn.size() - 1] > vm[vm.size() - 1]) {
                vm.pop_back();
            }
            else if(vn[vn.size() - 1] < vm[vm.size() - 1]) {
                vn.pop_back();
            }
        }

        if(vn.empty()) printf("B\n");
        if(vm.empty()) printf("S\n");
    }
}