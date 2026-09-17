class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            Node* copyNode = new Node(temp->val);

            temp->next = copyNode;
            copyNode->next = nextNode;
            temp = nextNode;
        }

        temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            copyNode->random = temp->random ? temp->random->next : nullptr;
            temp = copyNode->next;
        }

        Node dummy(-1);
        Node* copyTail = &dummy;
        temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;

            temp->next = copyNode->next; 
            copyTail->next = copyNode;   
            copyTail = copyNode;

            temp = temp->next;
        }

        return dummy.next;
    }
};