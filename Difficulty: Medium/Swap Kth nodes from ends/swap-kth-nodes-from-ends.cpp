class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        int len = 0;
        Node* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        
        if (k < 1 || k > len) return head;
        
        int k_from_end = len - k + 1;
        if (k == k_from_end) return head;
        
        // Ensure k is the smaller index to simplify swapping
        if (k > k_from_end) {
            int t = k;
            k = k_from_end;
            k_from_end = t;
        }
        
        Node* prev1 = nullptr;
        Node* curr1 = head;
        for (int i = 1; i < k; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        
        Node* prev2 = nullptr;
        Node* curr2 = head;
        for (int i = 1; i < k_from_end; i++) {
            prev2 = curr2;
            curr2 = curr2->next;
        }
        
        // Swap the nodes
        if (prev1 != nullptr) {
            prev1->next = curr2;
        } else {
            head = curr2;
        }
        
        if (prev2 != nullptr) {
            prev2->next = curr1;
        } else {
            head = curr1;
        }
        
        Node* temp_next = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp_next;
        
        return head;
    }
};