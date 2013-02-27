/*
 * Problem 2.2: find the kth to the last element in a singly linkedlist
 * Solution1: use two pointers front and back, the distance betwen these two pointers is K. so when the front pointer reaches the end, the back pointer is exactly at the location of kth to the last element.
 Time complexity: O(n)
 * Aurthor: Stanley Lee
 * Date: 2013/2/27
*/


#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* kthToLast(Node* head, int k){
  if(head==NULL)
    return head;
  else{
    Node* front = head;
    Node* back = NULL;
    int count = 1;
    if(count==k){
      back = head;
    }
    while(front->next!=NULL){
      front = front->next;
      count++;
      if(count==k){
        back = head;
      }
      else if(count>k){
        back = back->next;
      }
    }
    return back;
  }
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
  cout<<"Please input the number of k:";
  cin>>k;
  Node* kNode = kthToLast(head,k);
  if(kNode==NULL){
    cout<<"There are less than "<<k<<" nodes!"<<endl;
  }
  else
    cout<<"Node "<<k<<" is:"<<kNode->data<<endl;
}
