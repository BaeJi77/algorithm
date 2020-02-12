#include <cstdio>
#include <queue>

using namespace std;

int N,K,num[300004],sum;
priority_queue<int> pq;

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d" , &N,&K);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 1 ; i < N ; i++){
        sum += num[i] - num[i-1];
        pq.push(num[i] - num[i-1]);
    }

    for(int i = 0 ; i < K-1 ; i++) {
        sum -= pq.top();
        pq.pop();
    }

    printf("%d" , sum);
}