#include<iostream>
using namespace std;

class Node{

    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }

};

class DoublyLinkedList{

    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    //add a node at the start

    void display(){

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtStart(int val){

        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    //add a node at the end

    void insertAtEnd(int val){
     
        Node* new_node = new Node(val);
        if(tail==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    //add a node in an arbitrary position

    void insertAtPosition(int val, int k){

        //assuming k is less or equal to length of doubly linked list
        Node* temp = head;
        int count = 1;
        while(count<(k-1)){
            temp=temp->next;
            count++;
        }

        //temp will be pointing to the node at (k-1)th position
        Node* new_node = new Node(val);
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;

    }

    //delete a node at start

    void deleteAtStart(){

        if(head==NULL){
        return;
    }
    
    Node* temp = head;
    head = head->next;
    if(head==NULL){ // if doubly linked list had only 1 node

       tail = NULL;
    }else{
        head->prev = NULL;
    }
    free(temp);
    return;
}

//delete a node at end

void deleteAtEnd(){

    if(head==NULL){
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    if(tail==NULL){
        head=NULL;
    }else{
        tail->next=NULL;
    }

    free(temp);
    return;
}

//delete a node at arbitrary position

void deleteAtPosition(int k){

    //assuming l is less than or equal to length of dll
    Node* temp = head;
    int counter = 1;
    while(counter < k){
        temp=temp->next;
        counter++;

    }

    //now temp is pointing to node at kth position
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;

}

};

void deleteSameNeighbourNode(Node* &head, Node* &tail){

    Node* currNode = tail->prev; //second last node
    while(currNode!=head){
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        if(prevNode->val==nextNode->val){
            //I need to delete the curr node
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
}

 /*bool isPalindromeDLL(Node* head, Node* tail){

    while(head!=tail && tail!=head->prev){
        if(head->val!=tail->val){
            return false;
        }
        head=head->next;
        tail=tail->prev;
    }
    return true;
}


void reverseDll(Node* &head, Node* &tail){

    Node* currPtr = head;
    while(currPtr){
        Node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        currPtr = nextPtr;
    }
    
    //swapping head and tail pointers
    Node* newHead = tail;
    tail = head;
    head = newHead;
}*/

int main(){

   // Node* new_node = new Node(3);
    
    DoublyLinkedList dll;
   // dll.head = new_node;
   // dll.tail = new_node;
   // cout<<dll.head->val<<endl;

    // dll.insertAtStart(1);
    // dll.insertAtStart(2);
    // dll.insertAtStart(3);
    // dll.display();

    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    deleteSameNeighbourNode(dll.head, dll.tail);
    dll.display();
   // cout<<isPalindromeDLL(dll.head, dll.tail)<<endl;

   // reverseDll(dll.head, dll.tail);
   // dll.display();

    // dll.insertAtPosition(4,3);
   // dll.display();
   // dll.deleteAtStart();
   // dll.display();
   // dll.deleteAtEnd();
   // dll.display();

  // dll.deleteAtPosition(3);
  // dll.display();

    return 0;
}