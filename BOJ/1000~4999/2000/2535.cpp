#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);

    int N;
    scanf("%d", &N);

    vector<pair<int, pair<int, int>>> students;
    for(int i = 0 ; i < N ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        students.push_back({c, {a, b}});
    }

    sort(students.begin(), students.end(), [](pair<int, pair<int ,int>> x, pair<int, pair<int, int>> y) -> bool {
        return x.first > y.first;
    });

    unordered_map<int, int> countryCnt;

    vector<pair<int, int>> ans;
    for(auto& p : students) {
        if(countryCnt[p.second.first] >= 2) continue;
        if(ans.size() == 3) break;
        countryCnt[p.second.first]++;
        ans.push_back(make_pair(p.second.first, p.second.second));
    }

    for(auto val : ans)
        cout<<val.first<<" "<<val.second<<"\n";
}