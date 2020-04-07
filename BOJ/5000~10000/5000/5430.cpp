#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1e5;

char p[MAX+4];
int N;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", p);
        scanf("%d", &N);
        vector<int> vt;
        getchar();
        for(int i = 0 ; i < N ; i++) {
            getchar();
            int k;
            scanf("%d", &k);
            vt.push_back(k);
        }
        getchar();
        if(N==0) getchar();

        bool isError = false;
        string str(p);

        int deleteCnt = 0;
        for(int i = 0 ; i < str.size() ; i++) 
            if(str[i] == 'D') deleteCnt++;
        
        if(deleteCnt > vt.size()) {
            printf("error\n");
            continue;
        }

        int direction = 0; //0은 앞쪽 라인. 1은 뒤쪽 라인 보는 중
        int frontCnt = 0;
        int backCnt = 0;

        for(int i = 0 ; i < str.size() ; i++) {
            if(str[i] == 'D') {
                direction == 0 ? frontCnt++ : backCnt++;
            } else if (str[i] == 'R')
                direction = (direction + 1) % 2;
        }

        if(frontCnt)
            vt.erase(vt.begin(), vt.begin() + frontCnt);
        if(backCnt)
            vt.erase(vt.end() - backCnt, vt.end());

        if(direction)
            reverse(vt.begin(), vt.end());

        printf("[");
        for(int i = 0 ; i < vt.size(); i++) {
            printf("%d", vt[i]);
            if(i != vt.size() - 1) printf(",");
        }
        printf("]\n");
            
    }
}