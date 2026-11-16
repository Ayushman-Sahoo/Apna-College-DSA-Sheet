/*142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next 
pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if
there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};

// Helper to build a linked list with an optional cycle at index `pos`
ListNode* createList(const vector<int>& vals, int pos) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;

    for (int i = 1; i < (int)vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) cycleNode = curr;
    }

    if (pos != -1) {
        curr->next = cycleNode;
    }

    return head;
}

int main() {
    // Example 1: head = [3, 2, 0, -4], pos = 1
    ListNode* head = createList({3, 2, 0, -4}, 1);

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    if (result != nullptr) {
        cout << "Cycle begins at node with value: " << result->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}