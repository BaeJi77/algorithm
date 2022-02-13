/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *first = head;
        int nodeCnt = 0;
        while (first->next != NULL)
        {
            nodeCnt++;
            first = first->next;
        }

        bool odd = nodeCnt % 2;
        int mid = nodeCnt / 2;
        if (odd)
        {
            mid++;
        }

        first = head;

        for (int i = 0; i < mid; i++)
        {
            first = first->next;
        }

        return first;
    }
};
// @lc code=end
