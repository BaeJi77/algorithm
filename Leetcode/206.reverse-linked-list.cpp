/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *pre = NULL;
        ListNode *newHead = head;

        // while (head->next != NULL)
        // {
        //     printf("%d\n", head->val);
        //     newHead = head;
        //     head = head->next;

        //     newHead->next = pre;
        //     pre = head;
        // }
        // newHead = head;
        // newHead->next = pre;

        newHead->next = pre;

        printf("%d\n", newHead->val);
        if (newHead->next == NULL)
        {
            printf("null\n");
        }

        printf("%d\n", head->val);
        printf("%d\n", head->next->val);

        return newHead;
    }
};
// @lc code=end
