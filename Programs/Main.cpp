#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    Node* head;
    Node* tail;
    public:
        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
        
        void insert(int data) {
            Node* node = new Node(data);
            if(!head) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        
        void display() {
            Node* temp = head;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        
        Node* reverse(Node* node) {
            Node* prev = nullptr;
            Node* next = nullptr;
            Node* curr = node;
            
            while(curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        
        void rearrange() {
            Node* oddHead = nullptr;
            Node* evenHead = nullptr;
            Node* oddTail = nullptr;
            Node* evenTail = nullptr;
            
            Node*temp = head;
            
            while(temp) {
                int curr = temp->data;
                if(curr %2 == 0) {
                    if (!evenHead) {
                        evenHead = temp;
                        evenTail = temp;
                    }
                    else {
                        evenTail->next = temp;
                        evenTail = temp;
                    }
                }
                else {
                    if (!oddHead) {
                        oddHead = temp;
                        oddTail = temp;
                    }
                    else {
                        oddTail->next = temp;
                        oddTail = temp;
                    }
                }
                temp = temp->next;
            }
            
            if (evenHead) evenTail->next = nullptr;
            if (oddHead) oddTail->next = nullptr;
            
            evenHead = reverse(evenHead);
            oddHead = reverse(oddHead);
            
            if (!evenHead) {
                head = oddHead;
            }
            else {
                head = evenHead;
                Node* t = evenHead;
                while(t->next) {
                    t = t->next;
                }
                t->next = oddHead;
            }
        }
        
        void removeTargets(int val) {
            Node* dummy = new Node(0);
            dummy->next = head;
            Node* curr = dummy;
            
            while(curr->next) {
                if(curr->next->data == val) {
                    Node* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }
                else {
                    curr = curr->next;
                }
            }
            
            Node* newHead = dummy->next;
            delete dummy;
            head = newHead;
        }
        
        bool isPalindrome() {
            Node* slow = head;
            Node* fast = head;
            while(slow && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            Node* curr = slow;
            Node* prev = nullptr;
            Node* next = nullptr;
            
            while(curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            Node* first = head;
            Node* second = prev;
            
            while(second) {
                if (first->data != second->data) return false;
                first = first->next;
                second = second->next;
            }
            
            return true;
        }
};

int main() {
    int n;
    cin >> n;
    
    int num;
    SinglyLinkedList* sll = new SinglyLinkedList();
    for (int i=0; i<n; i++) {
        cin >> num;
        sll->insert(num);
    }
    // int target;
    // cin >> target;
    // sll->removeTargets(target);
    //sll->rearrange();
    cout << sll->isPalindrome() << "\n";
    sll->display();
    
}