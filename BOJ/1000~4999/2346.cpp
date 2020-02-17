#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

int N;
vector<int> solution;
deque<pair<int, int> > dq;
vector<int> order;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++ ){
        int a;
        scanf("%d", &a);
        dq.push_back(make_pair(i, a));
    }

    while(!dq.empty()) {
        
        int nowBoomNumber = dq.front().first;
        int nextBoomMoving = dq.front().second;
        dq.pop_front();
        solution.push_back(nowBoomNumber);
        if(dq.empty())
            break;

        if(nextBoomMoving > 0) {
            for(int i = 0 ; i < nextBoomMoving-1 ; i++) {
                pair<int, int> nowPair = dq.front();
                dq.pop_front();
                dq.push_back(nowPair);
            }
        } else {
            nextBoomMoving *= -1;
            for(int i = 0 ; i < nextBoomMoving ; i++) {
                pair<int, int> nowPair = dq.back();
                dq.pop_back();
                dq.push_front(nowPair);
            }
        }
    }

    for(int ans: solution){
        printf("%d ", ans);
    }
}