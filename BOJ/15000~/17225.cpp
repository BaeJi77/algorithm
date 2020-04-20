#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int A, B, N;
vector<pair<int, char> > map;
queue<int> hoon;
queue<int> soo;
vector<int> hoonAns;
vector<int> sooAns;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>A>>B>>N;
    int hoonEnd = 0;
    int sooEnd = 0;
    for(int i = 0 ; i < N ; ++i) {
        int t, m;
        char color;
        cin>>t>>color>>m;
        if(color == 'B' && hoonEnd > t) t = hoonEnd;
        else if(color == 'R' && sooEnd > t ) t = sooEnd;

        for(int j = 0 ; j < m ; ++j) {
            if(color == 'B') {
                map.push_back(make_pair(t + j * A, color));
            }
            else {
                map.push_back(make_pair(t + j * B, color));
            }
        }

        if(color == 'B') hoonEnd = t + m * A;
        else sooEnd = t + m * B;
    }

    sort(map.begin(), map.end());
    int k = 1;
    for(auto now : map) {
        if(now.second == 'B') hoonAns.push_back(k);
        else sooAns.push_back(k);
        k++;
    }
    
    cout<<hoonAns.size()<<"\n";
    for(auto number : hoonAns)
        cout<<number<<" ";
    cout<<"\n";
    cout<<sooAns.size()<<"\n";
    for(auto number : sooAns)
        cout<<number<<" ";
    cout<<"\n";
}