// Last updated: 11/5/2026, 11:44:29 PM
1class Solution {
2private:
3    ListNode* reverse(ListNode* head) {
4        ListNode* prev = nullptr;
5        ListNode* current = head;
6        
7        while (current != nullptr) {
8            ListNode* temp = current->next;
9            current->next = prev;
10            prev = current;
11            current = temp;
12        }
13        return prev;
14    }
15
16public:
17    void reorderList(ListNode* head) {
18        if (!head || !head->next) return;
19
20        ListNode* slow = head;
21        ListNode* fast = head;
22        while (fast->next && fast->next->next) {
23            slow = slow->next;
24            fast = fast->next->next;
25        }
26
27        ListNode* rev = reverse(slow->next);
28        slow->next = nullptr; 
29
30        ListNode* temp = head;
31        while (temp != nullptr && rev != nullptr) {
32            ListNode* tempNext = temp->next;
33            ListNode* revNext = rev->next;
34
35            temp->next = rev;
36            rev->next = tempNext;
37
38            temp = tempNext;
39            rev = revNext;
40        }
41    }
42};