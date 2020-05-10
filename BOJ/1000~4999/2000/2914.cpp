#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>M;
    if(N == 1) cout<<M;
    else if(M == 1) cout<<N;
    else cout<<(N * (M - 1) + 1);
}