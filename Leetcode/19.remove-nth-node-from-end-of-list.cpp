/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *node = head;
        int nodeCnt = 1;
        while (node->next != NULL)
        {
            nodeCnt++;
            node = node->next;
        }

        if (nodeCnt == 1)
        {
            head = NULL;
            return head;
        }

        node = head;
        int targetIndex = nodeCnt - n;
        for (int i = 0; i < nodeCnt; i++)
        {
            cout << i << " " << node->val << endl;
            if (i == targetIndex - 1)
            {
                node->next = node->next->next;
                break;
            }
            else if (i == 0 && targetIndex == 0)
            {
                head = head->next;
                break;
            }

            node = node->next;
        }

        return head;
    }
};
// @lc code=end
