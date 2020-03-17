#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    vector<int> vt;
    while(1) {
        int kk;
        scanf("%d", &kk);
        if(kk == -1) break;
        int cnt = 0;
        if(kk != 0) vt.push_back(kk);
        else {
            for(int i = 0 ; i < vt.size();  i++) {
                for(int j = 0 ; j < vt.size() ; j++) {
                    // printf("%d %d\n", vt[i], vt[j]);
                    if(vt[i] * 2 == vt[j]) cnt++;
                }
            }
            printf("%d\n", cnt);
            vt.clear();
        } 
    }
}