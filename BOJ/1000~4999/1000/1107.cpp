#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> vt;

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 0 ; i < M ; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
    }

    if(N == 100) {
        printf("0");
        return 0;
    }

    int ans = 0;
    int minValue = -1;
    int minDiff = 5000000;
    for(int i = 0 ; i <= 1000000; i++) {
        bool isPoss = true;
        string temp = to_string(i);
        for(int j = 0 ; j < temp.size() ; j++) {
            for(int  k = 0 ; k < vt.size(); k++) {
                if(temp[j] - '0' == vt[k]) {
                    isPoss = false;
                    break;
                }
            }
            if(!isPoss) break;
        }
        // 가능한 숫자다
        if(isPoss) {
            // minValue = i;
            if(N < i) {
                minDiff = min(minDiff, i - N + (int)temp.size());
            } else if(N > i) {
                minDiff = min(minDiff, N - i + (int)temp.size());
            } else if (N == i){ 
                minDiff = min(minDiff, i - N + (int)temp.size());
            }
        }
    }

    // 그냥 버튼으로 간거랑 숫자로 눌러서 간거랑 비교해야겠네
    int normalButton = 0;
    if(N > 100) normalButton = N - 100;
    else normalButton = 100 - N;

    printf("%d", min(minDiff, normalButton));
}