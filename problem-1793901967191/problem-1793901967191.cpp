// Last updated: 11/5/2026, 11:36:07 PM
1class Solution {
2private:
3    ListNode* reverse(ListNode* head) {
4        ListNode* prev = nullptr;
5        ListNode* current = head;
6        
7        while (current != nullptr) {
8            ListNode* nextTemp = current->next;
9            current->next = prev;
10            prev = current;
11            current = nextTemp;
12        }
13        return prev;
14    }
15
16public:
17    void reorderList(ListNode* head) {
18        if (!head || !head->next) return;
19
20        // 1. Find middle of the list
21        ListNode* slow = head;
22        ListNode* fast = head;
23        while (fast->next && fast->next->next) {
24            slow = slow->next;
25            fast = fast->next->next;
26        }
27
28        // 2. Split and reverse second half
29        ListNode* rev = reverse(slow->next);
30        slow->next = nullptr; // Disconnect first half from second half
31
32        // 3. Interleave first half (temp) and reversed second half (rev)
33        ListNode* temp = head;
34        while (temp != nullptr && rev != nullptr) {
35            ListNode* tempNext = temp->next;
36            ListNode* revNext = rev->next;
37
38            temp->next = rev;
39            if (tempNext == nullptr) break;
40            rev->next = tempNext;
41
42            temp = tempNext;
43            rev = revNext;
44        }
45    }
46};