/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;

        if (root != NULL)
        {
            q.push(root);
            makeNextRight(q);
        }

        return root;
    }

private:
    void makeNextRight(queue<Node *> q)
    {
        while (int size = q.size())
        {
            while (size--)
            {
                Node *node = q.front();
                q.pop();
                if (size != 0)
                {
                    node->next = q.front();
                }

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }
        }
    }
};
// @lc code=end
