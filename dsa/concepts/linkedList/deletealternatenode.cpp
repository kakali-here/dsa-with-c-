//Given the head of a linked list, delete every alternate element from the list starting from the second element.
 #include<iostream>
 using namespace std;

 class Node{
    public:
    int val;
    Node* next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
 };

 class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insertAtTail(int value){
        
        Node* new_node = new Node(value);
        if(head==NULL){ //linkedlist is empty
            head = new_node;
            return;

        }

        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = new_node;
    }

    void display(){

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
 };

 void reversePrint(Node* head){

    //base case
    if(head==NULL){
        return;
    }

    //recursive case
    reversePrint(head->next);
    cout<<head->val<<" ";
 }

 void deleteAlternateNodes(Node* &head){

    Node* curr_node = head;
    while(curr_node!=NULL && curr_node->next!=NULL){
        Node* temp = curr_node->next; //this is the node to be deleted
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
 };

 void deleteDuplicateNodes(Node* &head){
    
    Node* curr_node = head;
    while(curr_node){
        while(curr_node->next && curr_node->val==curr_node->next->val){
            //delete curr->next
            Node* temp = curr_node->next; //node to be deleted
            curr_node->next = curr_node->next->next;
            free(temp);
        }
        //this loop ends when current node and next node values are different
        //or linkedlist ends
        curr_node = curr_node->next;
    }
 };

 Node* reverseLL(Node* &head){

    Node* prevptr = NULL;
    Node* currptr = head;

    //currptr->next = prevptr;
    //move all 3 ptrs by one step ahead
    while(currptr!=NULL){
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    //When this loop ends, prevptr pointing to my last node which is new head
    Node* new_head = prevptr;
    return new_head;

 }

 Node* reverseLLRecursion(Node* &head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;

    }
    //recursive case
    Node* new_head = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL; //head is now pointing to last node in reversed ll
    return new_head;
 };

 Node* reversekLL(Node* &head, int k){

    Node* prevptr = NULL;
    Node* currptr = head;

    int counter = 0; //for counting first k nodes
    while(currptr!=NULL && counter<k){ //reversing first k nodes
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }
     
    //currptr will give us (k+1)th node 
    if(currptr!=NULL){
    Node* new_head = reversekLL(currptr,k); //recursive call
    head->next = new_head;
 }

 return prevptr; //prevptr will give the new_head of connected linkedlist

  int main(){

      LinkedList ll;
      ll.insertAtTail(1);
      ll.insertAtTail(2);
      ll.insertAtTail(3);
      ll.insertAtTail(4);
      ll.insertAtTail(5);
     // ll.insertAtTail(3);
     // ll.display();
     // deleteDuplicateNodes(ll.head);
      ll.display();
      ll.head = reverseLL(ll.head, 2);
      ll.display();

    return 0;
  }