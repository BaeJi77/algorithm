#include <cstdio>
#include <queue>

using namespace std;

int N,W,L;
int car[1001];
queue<pair<int, int> > qu;
queue<pair<int, int> > timeQ;


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &N, &W, &L);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &car[i]);
    }

    int idx = 1;
    int cnt = 1;
    int nowWeigh = car[0];
    timeQ.push(make_pair(W, car[0]));
    while(!timeQ.empty()){
        if(idx == N){
            cnt += W;
            break;
        }
        cnt++;
        
        while(!timeQ.empty()){
            int remainTime = timeQ.front().first;
            int w = timeQ.front().second;
            
            if(remainTime == 1)
                nowWeigh -= w;
            else{
                remainTime--;
                qu.push(make_pair(remainTime, w));
            }
            
            timeQ.pop();
        }
        
        if(nowWeigh + car[idx] <= L){
            timeQ.push(make_pair(W, car[idx]));
            nowWeigh += car[idx];
            idx++;
        }
        while(!qu.empty()){
            timeQ.push(make_pair(qu.front().first, qu.front().second));
            qu.pop();
        }
    }
    printf("%d\n", cnt);
}