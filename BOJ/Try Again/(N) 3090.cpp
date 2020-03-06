#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 1e5;
const int MAX = 1e9;

int N, T;
vector<int> vt;

int f (int mid) {
    int tCnt = 0;

    vector<int> temp(vt);
    for(int i = 0 ; i < N-1 ; i++) {
        if(abs(temp[i] - temp[i+1]) > mid){
            tCnt += abs(temp[i] - temp[i+1]) - mid;
            if(temp[i] > temp[i+1]) {
                temp[i] -= abs(temp[i] - temp[i+1]) - mid;
                if(i != 0) {
                    // 백 하면서 다 고쳐줘야지
                    for(int j = i ; j >= 1 ; j--) {
                        if(abs(temp[j - 1] - temp[j]) > mid) {
                            tCnt += abs(temp[j-1] - temp[j]) - mid;
                            if(temp[j-1] > temp[j])
                                temp[j-1] -= abs(temp[j-1]-temp[j]) - mid;
                            else 
                                temp[j] -= abs(temp[j-1]-temp[j]) - mid;
                        } else 
                            break;
                    }
                }
            } else {
                temp[i+1] -= abs(temp[i] - temp[i+1]) - mid;
            }
        }
    }
    return tCnt;
}

int cal() {
    int left = 0;
    int right = MAX;
    while(left <= right) {
        int mid = (left + right) / 2; // 인접 수의 최대 차이
        int F = f(mid);
        printf("%d %d %d %d\n", left, right, mid, F);
        if(F > T) { //변경 횟수가 더 많으면
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N, &T);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
    }

    printf("%d", cal());
}