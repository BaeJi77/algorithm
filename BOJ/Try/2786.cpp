#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N;
int minValue[500010];
int psum[500010];
vector<pair<int, int> > first;
vector<pair<int, int> > second;
vector<pair<int, int> > diff;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    // b의 전체 합과 a-b가 최소를 합한 결과
    // b-1의 전체 합과 a의 최소를 합한 결과
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        first.push_back(make_pair(a, i));
        second.push_back(make_pair(b, i));
        diff.push_back(make_pair(a - b, i));
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(diff.begin(), diff.end());

    int tempSum = 0;
    for(int i = 0 ; i < N ; i++) {
        tempSum += second[i].first;
        psum[i] = tempSum;
    }

    
    for(int i = 0 ; i < N ; ++i) {
        int candi1 = psum[i] + diff[i].first;
        // int candi2 = psum[i] + 
    }
}