#include <queue>
#include <cstdio>

using namespace std;

class node {
    public: 
    int value;
    int left;
    int right;

    node(int value, int left, int right) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

node tree[101];

int findMinValuvePathRootToFloor (node root) {
    int ans = 987654321;
    queue<node> qu;
    qu.push(root);
    while(!qu.empty()) {
        int nowValue = root.value;
        int nowLeft = root.left;
        int nowRight = root.right;

        if(nowLeft == -1 && nowRight == -1)
            ans = min(ans, nowValue);
        
        if(nowLeft != -1) 
            qu.push(tree[nowLeft]);
        
        if(nowRight != -1)
            qu.push(tree[nowRight]);
    }

    return ans;
}

int main() {
    node root(1, 2, 3);
    printf("%d\n", findMinValuvePathRootToFloor(root));
}