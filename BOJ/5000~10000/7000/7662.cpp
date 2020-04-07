#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int N;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        map<int, int> mp;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int> > rpq;
        scanf("%d", &N);
        for(int i = 0 ;i < N ; i++){
            getchar();
            char a;
            int b;
            scanf("%c %d", &a, &b);
            if(a == 'I'){
                pq.push(b);
                rpq.push(b);
                mp[b]++;
            }else{
                if(b == 1) {
                    if(pq.size() == 0 ) continue;
                    int top = pq.top();
                    pq.pop();
                    mp[top]--;  
                } else {
                    if(rpq.size() == 0 ) continue;
                    int top = rpq.top();
                    rpq.pop();
                    mp[top]--;  
                }
                while(!pq.empty() && mp[pq.top()] == 0)
                    pq.pop();
                
                while(!rpq.empty() && mp[rpq.top()] == 0)
                    rpq.pop();
            }

        }

        if(pq.empty()) printf("EMPTY\n");
        else printf("%d %d\n", pq.top(), rpq.top());
    }
}