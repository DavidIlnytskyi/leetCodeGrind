/*
 https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=daily-question&envId=2024-03-03
 */

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for(int idx = 0; idx < n; ++idx)
            fast = fast->next;
        if(!fast){
            return head->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        slow -> next = slow -> next -> next;

        return head;
    }
};

/*
 Main idea:

 If we have array
 1, 2, 3, 4, 5, n = 2
 We will have to delete 4
 In other words, we have to change next value of
 our node if over n values next value is nullptr

 To implement that, we will launch fast pointer,
 that will be n positions faster than our slow
 pointer. After move fast and slow pointer one
 by one. Result of that will be, if our fast
 pointer next value if nullptr, we have to re-
 connect our slow pointer next value.

 If out fast pointer does not exist after moving
 it n-positions, it means we have to move from
 node before our head, node -> head -> next node
 so now our head becomes head -> next.
 */