#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int N;
// 나이 순, 가입한 순
priority_queue<pair<int, pair<int, string> > > pq;


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i < N ; i++) {
        int year;
        string name;
        cin>>year>>name;
        pq.push(make_pair(-year, make_pair(-i, name)));
    }

    for(int i = 0 ; i < N ; i++) {
        cout<<-pq.top().first<<" "<<pq.top().second.second<<"\n";
        pq.pop();
    }
}