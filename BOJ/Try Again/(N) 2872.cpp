#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 3e5;

int N;
int books[MAX+1];
// int temp[MAX+1];
vector<int> vt;
priority_queue<pair<int, int> > pq;

// bool isSorted () {
//     for(int i = 0 ; i < N-1 ; i++) {
//         if(temp[i] > temp[i+1])
//             return false;
//     }
//     return true;
// }

// int findMaxIndex(int startIdx) {
//     int maxIdx = -1;
//     int maxValue = -1;
//     for(int i = startIdx ; i < N ; i++) {
//         if(maxValue < temp[i]) {
//             maxValue = temp[i];
//             maxIdx = i;
//         }
//     }
//     return maxIdx;
// }

// void copyBooks() {
//     for(int i = 0 ; i < N ; i++)
//         temp[i] = books[i];
// }

// void changePos(int i, int j) {
//     int k = temp[i];
//     temp[i] = temp[j];
//     temp[j] = k;
// }

int f (int mid) {
    int changeCnt = 0;
    copyBooks();
    for(int i = 0 ;  i < N ; i++) {
        if(isSorted()) {
            break;
        }
        int nowMaxValueIdx = findMaxIndex(i);
        changePos(nowMaxValueIdx, i);
        changeCnt++;
        // if(mid == 3)
        //     printf("for: %d %d %d %d %d\n", i, nowMaxValueIdx,temp[i], temp[nowMaxValueIdx], changeCnt);
    }
    puts("");

    if(changeCnt > mid) return false;
    return true;
}

int ff (int mid) {
    int changeCnt = 0;
    bool visited[MAX+1] = {0,};
    vector<int> temp(vt);

    for(int i = 0 ; i < mid ; i++) {
        int nowMaxValue = pq.top().first;
        int nowMaxIdx = pq.top().second;
        pq.pop();
        visited[nowMaxIdx] = true;
        temp.push_back(nowMaxValue);
        if(i != vt.size() - i - 1) changeCnt++;
    }
    


}

int cal() {
    int left = 0;
    int right = MAX;

    while(left <= right) {
        int mid = (left + right) / 2; // 책 움직이기 가능한 숫자
        int F = f(mid);
        printf("%d %d %d %d\n", left, right, mid, F);
        if(F) { // 가능
            right = right - 1;
        } else {
            left = left + 1;
        }
    }
    return left;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &books[i]);
        vt.push_back(books[i]);
        pq.push(make_pair(books[i], i));
    }

    printf("%d", cal());
}