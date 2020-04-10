#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int left;
    int right;
} ;

int N, root;
node tree[30];
int height[30];

void go(int now, int nowHeight) {
    height[now] = nowHeight;
    if(tree[now].left != -1) 
        go(tree[now].left, nowHeight + 1);
    if(tree[now].right != -1)
        go(tree[now].right, nowHeight + 1);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) {
        node defaultNode = {-1, -1};
        tree[i] = defaultNode;
    }

    for(int i = 1 ; i <= N ; i++) {
        int k;
        scanf("%d", &k);
        if(k == -1) {
            root = i;
        } else {
            if(tree[k].left == -1) {
                tree[k].left = i;
            } else {
                tree[k].right = i;
            }
        }
    }

    go(root, 0);
    for(int i = 1; i <= N ; i++)
        printf("%d\n", height[i]);
}