/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }

        if (list2 == NULL)
        {
            return list1;
        }

        ListNode *result;
        if (list1->val < list2->val)
        {
            result = list1;
            list1 = list1->next;
        }
        else
        {
            result = list2;
            list2 = list2->next;
        }

        ListNode *first = result;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                result->next = list1;
                list1 = list1->next;
            }
            else
            {
                result->next = list2;
                list2 = list2->next;
            }

            result = result->next;
        }

        while (list1 != NULL)
        {
            result->next = list1;
            list1 = list1->next;
            result = result->next;
        }

        while (list2 != NULL)
        {
            result->next = list2;
            list2 = list2->next;
            result = result->next;
        }

        return first;
    }
};
// @lc code=end
