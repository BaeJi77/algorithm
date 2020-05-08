#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M, now;
int word[10001];

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i = 0 ; i < N ; ++i) {
        string temp;
        cin>>temp;
        int bit = 0;
        for(int j = 0 ; j < temp.size() ; ++j) {
            bit |= 1<<(temp[j] - 'a');
        }
        word[i] = bit;
    }

    now = (1<<26) - 1;
    for(int i = 0 ; i < M ; ++i) {
        int q;
        char alphabet;
        cin>>q>>alphabet;
        if(q == 1) {
            now &= ~(1<<(alphabet - 'a'));
        }
        if(q == 2) {
            now |= 1<<(alphabet - 'a');
        }

        int cnt = 0;
        for(int j = 0 ; j < N ; ++j) {
            if((word[j] & now) == word[j]) cnt++;
        }

        cout<<cnt<<"\n";
    }
}