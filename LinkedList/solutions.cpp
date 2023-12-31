/**
 * Design a Singly Linked List
*/
class MyLinkedList { 
    
    class ListNode {
    public: 
        int val;
        ListNode* next;
        
        ListNode() {
            this->val = 0;
            this->next = nullptr;
        }
        
        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
        
    };
        
public:    
    ListNode* head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /**
     * Get the value of the node at the given index in the linked list. 
     * If the index is invalid, return -1.
     * */ 
    int get(int index) {
        if(index >= size || index < 0) {
            return -1;
        }
        ListNode* nodeAtIndex = head;
        for(int i = 0; i < index;i++) {
            nodeAtIndex = nodeAtIndex->next;
        }
        return nodeAtIndex->val;
    }
    
    /**
     * Add a node of value val before the first element of the linked list. 
     * After the insertion, the new node will be the first node of the linked list.
    */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    

    /**
     * Append a node of value val as the last element of the linked list.
    */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    /**
     * Add a node of value val before the node on index:index in the linked list. 
     * If index equals the length of the linked list, the node will be appended to the end of the linked list. 
     * If index is greater than the length, the node will not be inserted.
    */
    void addAtIndex(int index, int val) {
        // Check for out of bounds:
        if(index > size || index < 0) {
            return;
        } 
        
        ListNode* current = head;
        ListNode* newNode = new ListNode(val);
        
        // Check for edge cases:
        if (index == 0) {
            newNode->next = current;
            head = newNode;
        } else {
            for(int i = 0; i < index-1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;        
    }
    
    /**
     * Delete the node on index: index in the linked list, if the index is valid.
    */
    void deleteAtIndex(int index) {
        // Check for out of bounds:
        if(index >= size || index < 0) {
            return;
        } 
        // Check for edge cases:
        if (index == 0) {
            ListNode* nextNode = head->next;
            delete head;
            head = nextNode;
            size--;
            return;
        } 
        
        ListNode* node = head;
        for(int i = 0; i < index-1; i++) {
            node = node->next;
        }
        
        ListNode* nextNode = node->next->next;
        delete node->next;
        node->next = nextNode;
        size--;
    }
    
    // Destructor
    ~MyLinkedList() {
        ListNode *p = head;
        // Delete node at head while head is not null
        while (head != nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
    
};

/**
 * Design a Doubly Linked List
 */
class MyDoublyLinkedList {
    
private: 
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        
        ListNode() {
            this->val = 0;
            this->next = nullptr;
            this->prev = nullptr;
        }
        
        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    
    ListNode* head;
    ListNode* tail;
    int size;
        
public:    
    MyDoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    // Get the value of the node at the given index in the linked list. If the index is invalid, return -1.
    int get(int index) {
        if(index >= size || index < 0) {
            return -1;
        }
        ListNode* nodeAtIndex = getNodeAtIndex(index);
        return nodeAtIndex->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if(size==0) {
            addAtHead(val);
        } else {
            ListNode* newNode = new ListNode(val);
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
            size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        // Check for out of bounds:
        if(index > size || index < 0) {
            return;
        } 
        // Check for edge cases: 
        if (index == 0) {
            addAtHead(val);
            return;
        } 
        if (index == size) {
            addAtTail(val);
            return;
        } 
        
        ListNode* newNode = new ListNode(val);
        
        ListNode* current = getNodeAtIndex(index);
        ListNode* prevNode = current->prev;

        newNode->next = current;
        newNode->prev = prevNode;
        
        current->prev = newNode;
        prevNode->next = newNode;
        size++;        
    }
    
    void deleteAtIndex(int index) {
        // Check for out of bounds:
        if(index >= size || index < 0) {
            return;
        } 
        
        ListNode* current = getNodeAtIndex(index);
        ListNode* prevNode = current -> prev;
        ListNode* nextNode = current -> next;
        if (prevNode == NULL) {
            head = nextNode;
        } else {
            prevNode->next = nextNode;
        }
        if(nextNode == NULL) {
            tail = prevNode;
        } else {
            nextNode->prev = prevNode;
        }
        delete current;
        size--;
    }
    
    // Destructor
    ~MyLinkedList() {
        ListNode *p = head;
        // Delete node at head while head is not null
        while (head != nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
    
private:
    ListNode* getNodeAtIndex(int index){
        ListNode* current;
        if(index < size/2) {
            current = head;
            for(int i = 0; i < index; i++) {
                current = current->next;
            }
            return current;
        } else {
            current = tail;
            for(int i = size-1; i > index; i--) {
                current = current->prev;
            }
            return current;
        }
    }
    
};

class Solution {
public:
    /**
    * Linked List Cycle I & II
    * */    
    ListNode *detectCycle(ListNode *head) {
        using namespace std;
        
        // Using the fast and slow pointers technique
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
        
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {        
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return findEntry(entry, slow);
            }
        }
        return NULL;
    }
    
    ListNode *findEntry(ListNode *entry, ListNode *slow) {
        while(slow != entry){
            slow = slow->next;
            entry = entry->next;
        }
        return entry;
    }

    /**
     * Intersection of Two Linked Lists
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        using namespace std;
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        
        int remainingA = 0;
        int remainingB = 0;
        
        // Calculate the size of the lists
        while(currentA->next != NULL) {
            currentA = currentA->next;
            remainingA++;
        }
        while(currentB->next != NULL) {
            currentB = currentB->next;
            remainingB++;
        }
        
        // Check if the lists do not intersect, in that case return NULL 
        if (currentA != currentB) {
            return NULL;
        } 

        // Otherwise, start searching for the intersection
        // Restart the pointers.
        currentA = headA;
        currentB = headB;
        
        // Start traversing in the larger list until they are of the same remaining size
        while(remainingA > remainingB) {
            currentA = currentA->next;
            remainingA--;
        }
        while(remainingB > remainingA) {
            currentB = currentB->next;
            remainingB--;
        }
        
        // Now the lists have equal remaining size, the pointers will match once the list íntersect.
        while(currentA != currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return currentA;
    }

    /**
     * Remove Nth Node From End of List
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        using namespace std;
        // Check for the edgecase of a list with size 1
        if (head->next == NULL) {
            delete head;
            return nullptr;
        }
        
        ListNode* temp = new ListNode();
        temp->next = head;
        
        ListNode* first = temp;
        ListNode* second = temp;
        
        // Let the first pointer start n+1 steps ahead of the second
        for(int i = 0; i < n; i++) {
            first = first->next;
        }
        
        // Now we let the pointers traverse the list until first one reaches the end
        while(first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the next element after second, this is the one which is the n-th last element.
        ListNode* nextNode = second->next;
        second->next = second->next->next;
        delete nextNode;
        
        return temp->next;
    }

    /**
     * Reverse Linked List
    */
    ListNode* reverseList(ListNode* head) {
        using namespace std;
        ListNode* node = head;
        ListNode* temp;
        
        while(node != NULL && node->next != NULL) {
            // Remove the next element from the list
            temp = node->next;
            node->next = node->next->next;
            
            // Add the removed element as head
            temp->next = head;
            head = temp;
        }
        return head;
    }

    /**
     * Remove Linked List Elements
    */
    ListNode* removeElements(ListNode* head, int val) {
        using namespace std;
        ListNode* deleted; 
        
        while(head != NULL && head->val == val) {
            deleted = head;
            head = head->next;    
            delete deleted;
        }
        
        ListNode* node = head;
        while(node != NULL && node->next !=NULL) {
            if(node->next->val == val) {
                ListNode* deleted = node->next;
                node->next = node->next->next;
                delete deleted;
            } else {
                node = node->next;
            }
            
        }
        return head;
    }

    /**
     * Odd Even Linked List
    */
    ListNode* oddEvenList(ListNode* head) {
        using namespace std;
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* lastEven = head;
        ListNode* current = head->next;
        ListNode* moved;
        ListNode* temp;
        
        // Move every other node into the growing front part of the list.
        while(current != NULL && current->next != NULL) {
            
            moved = current->next;
            current->next = current->next->next;
            
            temp = lastEven->next;
            lastEven->next = moved;
            moved->next = temp;
            lastEven = moved;
            
            current = current->next;
        }
        return head;
    }

    /**
     * Palindrome Linked List
    */
    bool isPalindrome(ListNode* head) {
        using namespace std;
        if (head == NULL) {
            return true;            
        }
        
        // First, lets find the middle of the linked list with slow and fast pointers:
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If the list is odd in length, we can ignore the middle element: 
        if(fast != NULL) {
            slow = slow->next;
        }
        
        // Now we reverse the second half of the list, in order to check for palindrome: 
        ListNode* secondHead = reverseList(slow);
        
        // Now traverse the list and check for palindrome pattern: 
        while(secondHead != NULL) {
            if(secondHead->val != head->val){
                return false;
            }
            head = head->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }

    /**
     * Merge Two Sorted Lists
    */
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        using namespace std;
        if(list1 == NULL) {
            return list2;
        }
        if(list2 == NULL) {
            return list1;
        }

        ListNode* newHead;
        if(list1->val < list2->val) {
            newHead = list1;
            list1 = list1->next;
        } else {
            newHead = list2;
            list2 = list2->next;
        }
        ListNode* current = newHead;
        
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;    
        }
        while(list1 != NULL) {
            current->next = list1;
            current = current->next;
            list1 = list1->next;
        }
        while(list2 != NULL) {
            current->next = list2;
            current = current->next;
            list2 = list2->next;
        }
        
        
        return newHead;
    }

    /**
     * Add Two Numbers Linked List
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        using namespace std;
        // Catching the edge cases:
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        
        ListNode* newHead = l1;
        ListNode* newNode = l1;
        ListNode* lastNode = l1;
        int overflow = 0;
        int sum;
        
        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + overflow;
            l1 = l1->next;
            l2 = l2->next;
            
            if (sum > 9) {
                sum = sum - 10;
                overflow = 1;
            } else {
                overflow = 0;
            }            
            newNode->val = sum;
            lastNode = newNode;
            newNode = newNode->next;
        }      
        while(l1 != NULL) {
            sum = l1->val + overflow;
            l1 = l1->next;
            if (sum > 9) {
                sum = sum - 10;
                overflow = 1;
            } else {
                overflow = 0;
            }            
            newNode->val = sum;
            lastNode = newNode;
            newNode = newNode->next;
        }
        while(l2 != NULL) {
            sum = l2->val + overflow;
            l2 = l2->next;
            if (sum > 9) {
                sum = sum - 10;
                overflow = 1;
            } else {
                overflow = 0;
            }            
            newNode = new ListNode(sum);
            lastNode->next = newNode;
            lastNode = newNode;
        }
        if (overflow != 0) {
            newNode = new ListNode(overflow);
            lastNode->next = newNode;
        }
        return newHead;
    }

    /**
     * Flatten a Multilevel Doubly Linked List
    */
    Node* flatten(Node* head) {
        using namespace std;
        Node* current = head;
        
        while(current != NULL) {
            if(current->child != NULL) {
                Node* nextNode = current->next;
                Node* childFlat = flatten(current->child);
                Node* lastChild = getLastElement(childFlat);
                
                childFlat->prev = current;
                current->next = childFlat;
                current->child = nullptr;
                
                if (nextNode != NULL) {
                    lastChild->next = nextNode;
                    nextNode->prev = lastChild;
                }
            }            
            current = current ->next;
        }
        return head;
    }
    
    Node* getLastElement(Node* head) {
        using namespace std;
        Node* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        return current;
    }

    /**
     * Copy List with Random Pointer
    */
    Node* copyRandomList(Node* head) {
        using namespace std;
        if(head == NULL) {
            return NULL;
        }
        
        // Create a map of all of the nodes, mapping the original nodes to the copy nodes:
        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        while(current != NULL) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // Now we can connect the copy nodes together using the map:
        current = head;
        while(current != NULL) {
            Node* copy = nodeMap[current];
            copy->next = nodeMap[current->next];
            copy->random = nodeMap[current->random];
            current = current->next;
        }
        Node* copyHead = nodeMap[head];
        return copyHead;
    }

    /**
     * Rotate List
    */
    ListNode* rotateRight(ListNode* head, int k) {
        using namespace std;
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Calculate the size of the list:
        ListNode* current = head;
        int listSize = 0;
        while (current != NULL) {
            listSize++;
            current = current->next;
        }
        // A listsize amount of rotations equal 0 rotations.
        if(k == listSize) { 
            return head;
        }
        if(k > listSize) {
            k = k % listSize;
        }
        
        // Find the k+1:th node from the back if possible, using slow-fast pointer technique:
        ListNode* fast = head;
        for(int i = 0; i < k; i++) {
            fast = fast->next;
        }
        ListNode* beforeNewHead = head;        
        while(fast->next != NULL) {
            beforeNewHead = beforeNewHead->next;
            fast = fast->next;
        }
        
        // Make the list cyclic: 
        fast->next = head;
        
        // Break the cycle in the correct spot, and assign a new head:
        ListNode* newHead = beforeNewHead->next;
        beforeNewHead->next = nullptr;
        return newHead;        
    }

};



