#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to add two numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ✨ Write your logic here ✨
        return nullptr; // placeholder
    }

    // Utility: Build linked list from vector
    ListNode* buildList(const vector<int>& nums) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int n : nums) {
            curr->next = new ListNode(n);
            curr = curr->next;
        }
        return dummy->next;
    }

    // Utility: Print linked list
    void printList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> v1 = {2, 4, 3}; // represents 342
    vector<int> v2 = {5, 6, 4}; // represents 465

    ListNode* l1 = sol.buildList(v1);
    ListNode* l2 = sol.buildList(v2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    sol.printList(result);

    return 0;
}
