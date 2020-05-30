#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);

    int N;
    while(cin>>N) {
        if(N == 0) break;
        
        vector<pair<string, string>> words;
        for(int i = 0 ; i < N ; i++) {
            string temp, origin;
            cin>>temp;
            origin = temp;
            for(int j = 0 ; j < temp.size() ; j++) {
                if('A' <= temp[j] && temp[j] <= 'Z') temp[j] = temp[j] - 'A' + 'a';
            }
            words.push_back(make_pair(temp, origin));
        }

        sort(words.begin(), words.end());
        cout<<words[0].second<<"\n";
    }
}