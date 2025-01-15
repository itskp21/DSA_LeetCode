/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* current = head;

        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node* dummy = new Node(0);
        Node* copy = dummy;
        current = head;

        while (current) {
            copy->next = current->next;
            current->next = current->next->next;
            current = current->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};