//
//  LinkedList.cpp
//  
//
//  Created by Pravin Chandru on 4/24/14.
//
//


#include <iostream>
using namespace std;

// Node class
class Node {
    int data;
    Node* next;
    
public:
    Node() {};
    void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int getData() { return data; };
    Node* getNext() { return next; };
};

// List class
class List {
    Node *head;
public:
    List() { head = NULL; };
    void Print();
    void Append(int data);
    void Delete(int data);
    void reverse();
    bool detectLoop();
    void createLoop();
    Node* middleLinkedList();
    Node* reverse(Node* root);
    bool compare(List list1, List list2);
    bool compare(Node* ll1, Node* ll2);
    List copyLinkedList(List list);
    Node* copyLinkedList(Node* node);
    Node* returnNthNode(int n);
};

/**
 * Print the contents of the list
 */
void List::Print() {
    
    // Temp pointer
    Node *tmp = head;
    
    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }
    
    // One node in the list
    if ( tmp->getNext() == NULL ) {
        cout << tmp->getData();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else {
        // Parse and print the list
        do {
            cout << tmp->getData();
            cout << " --> ";
            tmp = tmp->getNext();
        }
        while ( tmp != NULL );
        
        cout << "NULL" << endl;
    }
}

/**
 * Append a node to the linked list
 */
void List::Append(int data) {
    
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);
    
    // Create a temp pointer
    Node *tmp = head;
    
    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->getNext() != NULL ) {
            tmp = tmp->getNext();
        }
        
        // Point the last node to the new node
        tmp->SetNext(newNode);
    }
    else {
        // First node in the list
        head = newNode;
    }
}

/**
 * Delete a node from the list
 */
void List::Delete(int data) {
    
    // Create a temp pointer
    Node *tmp = head;
    
    // No nodes
    if ( tmp == NULL )
    return;
    
    // Last node of the list
    if ( tmp->getData() == data) {
        if (tmp->getNext() == nullptr) {
            head = NULL;
        } else {
            head = tmp->getNext();
        }
        delete tmp;
        return;
        
    } else {
        while (tmp->getNext() != nullptr && tmp->getNext()->getData() != data) {
            tmp = tmp->getNext();
        }
        if (tmp->getNext() == nullptr) {
            cout << "Element to be delted not found " <<endl;
            return;
        } else {
            
            Node *temp;
            temp=tmp->getNext();
            tmp->SetNext(tmp->getNext()->getNext());
            delete temp;
        }
        return;
    }
}


/**
 * create loop in the list
 */
void List::createLoop()
{
    
    head->SetNext(head);
    /*Node* tail=head;
    while (tail->getNext()!= nullptr) {
        tail = tail->getNext();
    }
    tail->SetNext(head);*/
    
}


/**
 * Reverse the list
 */

void List::reverse()
{
    Node* temp;
    temp = reverse(head);
    temp->SetNext(nullptr);
}

Node* List::reverse(Node* root)
{
    if (root->getNext() != nullptr) {
        reverse(root->getNext());
        root->getNext()->SetNext(root);
        return root;
    } else {
        head = root;
    }
}


/**
 * detect loop in the linked list
 */

bool List::detectLoop()
{
    Node* ptr1 = head;
    Node* ptr2 = head;
    
    if (!ptr1) {
        cout << "list empty" << endl;
        return false;
    }
    ptr2 = head->getNext();
    while (ptr2) {
        if (ptr1 == ptr2) {
            cout << "loop found" << endl;
            return true;
        } else {
            ptr1 = ptr1->getNext();
            ptr2= (ptr2->getNext())?ptr2->getNext()->getNext():ptr2->getNext();
        }
    }
    cout << "loop not found" << endl;
    return false;
    
}


/**
 * return middle of the linked list
 */

Node* List::middleLinkedList()
{
    if (head == nullptr) {
        return nullptr;
    }
    
    Node* ptr1 = head;
    Node* ptr2 = head->getNext();
    
    while ( ptr2 ) {
        ptr1 = (ptr1)?ptr1->getNext():nullptr;
        ptr2 = (ptr2)?ptr2->getNext():nullptr;
        ptr2 = (ptr2)?ptr2->getNext():nullptr;
    }
    
    return ptr1;
    
    
}


/**
 * compare 2 linked lists
 */

bool List::compare(List list1, List list2)
{
    return compare(list1.head, list2.head);
    
}

bool List::compare(Node* ll1, Node* ll2)
{
    if (ll1 == nullptr && ll2 == nullptr) {
        return true;
    } else if (ll1 == nullptr || ll2 == nullptr) {
        return false;
    } else if (ll1->getData() != ll2->getData()) {
        return false;
    } else {
        return compare(ll1->getNext(), ll2->getNext());
    }
}



/**
 * copy a linked list
 */

List List::copyLinkedList(List list)
{
    List newList;
    newList.head = copyLinkedList(list.head);
    return newList;
}


Node* List::copyLinkedList(Node* node)
{
    Node* newNode;
    if (node) {
        newNode = new Node();
        newNode->SetData(node->getData());
        newNode->SetNext(copyLinkedList(node->getNext()));
    } else {
        newNode = nullptr;
    }
    return newNode;
    
}



/**
 * return nth node of a linked list
 */


Node* List::returnNthNode(int n)
{
    if (!head) {
        cout<< "List empty" << endl;
        return nullptr;
    }
    
    Node* ptr1=head;
    Node* ptr2=head;
    
    int count=0;
    while (ptr1  && count < n ) {
        ptr1 =ptr1->getNext();
        count++;
    }
    
    //cout << "ptr1 index at:" << ptr1->getData();
    
    if(!ptr1 && count < n){
        cout<< "list not long enough" << endl;
        return nullptr;
    } else if(!ptr1)
        return ptr2;
    
    while (ptr1) {
        ptr1 = ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    return ptr2;
    
}




int main()
{
    // New list
    List list;
    
    // Append nodes to the list
    cout << "List :" << endl;
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(800);
    list.Print();
    list.Append(900);
    list.Print();
    
    
    List list1;
    /*cout << "List 1:" << endl;
    list1.Append(100);
    list1.Print();
    list1.Append(200);
    list1.Print();
    list1.Append(300);
    list1.Print();
    list1.Append(400);
    list1.Print();
    list1.Append(800);
    list1.Print();*/
    
    
    
    
    // Delete nodes from the list
    /*list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(500);
    list.Print();
     
    list.reverse();
    list.Print();
    
    list.createLoop();
    cout << "loop created" <<endl;
    list.detectLoop();
    
    Node* middleNode = list.middleLinkedList();
    if (middleNode) {
        cout <<"middle of linked list is " << middleNode->getData();
    } else {
        cout << "list empty " << endl;
    }
    
    if (list.compare(list, list1)) {
        cout<< "Lists are same " << endl;
    } else {
        cout<< "Lists are different " << endl;
    }
    
    List copiedList = list.copyLinkedList(list1);
    cout << " new list :" << endl;
    copiedList.Print();*/
    
    cout << 4 << " node from the end of the list :" << endl;
    Node* nNode = list.returnNthNode(4);
    if(nNode) {
        cout <<  nNode->getData() << endl;
    }
    
    
    
}