/*
 * Problem 2.4: Write code to partition a  linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x
 * Solution: Use the idea of qsort, two pointers, to traverse the list: the first pointer stops once a value if found to be greater than x, then the other pointer starts from the node right after the first pointer and then traverse the following node. if value less than x is found, then swap the two nodes' value information
 * Time complexity: O(n); Space complexity: O(1)
 * Aurthor: Stanley Lee
 * Date: 2013/2/27
*/


#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void partition(Node* head, int x){
  if(head==NULL || head->next==NULL){// deal with empty list or one data list
    return;
  }
  else{
    Node* lessX = head;
    while(lessX->data<x && lessX!=NULL){
      lessX = lessX->next;
    }
    if(lessX == NULL){// all elements are less than x, no need to partition
      return;
    }
    else{
      Node* greaterX = lessX->next;
      while(greaterX != NULL){
        if(greaterX->data < x){
	  int temp = greaterX->data;
	  greaterX->data = lessX->data;
	  lessX->data = temp;
	  lessX = lessX->next;
	}
	greaterX = greaterX->next;
      }
    }
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
  int intArray[15] = {1,9,3,8,5,12,7,8,9,2,11,6,4,14,15};
  Node* head = constructList(intArray,15);
  cout<<"Original List:"<<endl;
  printList(head);
  int k=0;
  cout<<"Please input the pivot x:";
  cin>>k;
  partition(head,k);
  cout<<"After partition:"<<endl;
  printList(head);
  return 0;
}
