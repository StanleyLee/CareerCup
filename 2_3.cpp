/*
 * Problem 2.3: implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node
 * Solution: copy the next node information to the given node and delete the next node.
 * Time complexity: O(1)
 * BUG Known: this method cannot delete the last node, I think this is the limiation of this algorithm, since you can never get the pointer to the previous node. Anyone has better ideas?
 * Aurthor: Stanley Lee
 * Date: 2013/2/27
*/


#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void deleteNode(Node* curNode){
  if(curNode->next == NULL){
    cout<<"This is the last node of the linked list, cannot be deleted!"<<endl;
    cout<<"No deletion is taken!"<<endl;
    return;
  }
  curNode->data = curNode->next->data;
  Node* nextNode = curNode->next;
  curNode->next = curNode->next->next;
  delete nextNode;
}


Node* constructList(int* intArray,int len){
  Node* head = NULL;
  for(int i=0;i<len;++i){
    Node* tempNode = new Node;
    tempNode->data = intArray[i];
    tempNode->next = head;
    head = tempNode;
  }
  return head;
}

Node* getKthNode(Node* head,int k){
  if(head==NULL){
    return NULL;
  }
  int count = 0;
  Node* curNode = head;
  while(curNode!=NULL){
    count++;
    if(count==k)
      return curNode;
    else{
      curNode = curNode->next;
    }
  }
  return NULL;
}


void printList(Node* head){
  if(head==NULL){
    cout<<"This is an empty list!"<<endl;
  }
  else{
    Node* curNode = head;
    while(curNode->next!=NULL){
      cout<<curNode->data<<"->";
      curNode = curNode->next;
    }
    cout<<curNode->data<<endl;
  }
}

int main()
{
  int intArray[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  Node* head = constructList(intArray,15);
  cout<<"Original List:"<<endl;
  printList(head);
  int k=0;
  cout<<"Please input which number of the position you want to delete:";
  cin>>k;
  Node* kNode = getKthNode(head,k);
  if(kNode==NULL){
    cout<<"There are less than "<<k<<" nodes!"<<endl;
  }
  else{
    deleteNode(kNode);
    cout<<"After deletion:"<<endl;
    printList(head);
  }
  return 0;
}
