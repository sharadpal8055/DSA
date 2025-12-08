class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* start = head;
        ListNode* end = head;

        // Find last node initially
        while (end->next != NULL) {
            end = end->next;
        }

        // Now compare from both ends until they meet
        while (start != end && start->next != end) {

            // Compare the two ends
            if (start->val != end->val)
                return false;

            // Move start forward
            start = start->next;

            // Move end backward by finding previous node
            ListNode* temp = head;
            while (temp->next != end) {
                temp = temp->next;
            }
            end = temp;
        }

        // Final comparison for the middle pair
        if (start->val != end->val)
            return false;

        return true;
    }
};
