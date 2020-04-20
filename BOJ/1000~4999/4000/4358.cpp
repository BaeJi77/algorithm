#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int totalTree;
map<string, int> trees;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    string input;
    while(getline(cin, input)) {
        totalTree++;
        trees[input]++;
    }

    cout<<fixed;
    cout.precision(4);

    for(auto tree: trees) {
        cout<<tree.first<<" "<<((double)tree.second / totalTree) * 100<<"\n";
    }
}