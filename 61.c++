
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length of the linked list
        int len = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;

        if (k == 0) {
            return head;
        }

        // Connect the tail to the head (make a circle)
        tail->next = head;

        // Find the new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
