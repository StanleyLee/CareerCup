/*
 * Problem 2.5: add two numbers in the list
 * Solution: add it up one digit by digit, indicate the carry digit, if one list is ended, fill 0; insert the sum to the tail of the list
 * Follow up: use stacks to store the list, and then same strategy as above, only thing to pay attention is this time, the sum result should be insert from the head of the list.
 * Time complexity: O(n);
 * Aurthor: Stanley Lee
 * Date: 2013/2/28
*/


#include <iostream>
#include <stack>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class LinkedList{
private:
  Node* head;  // head pointer to the list
  int numNode; // number of nodes in the list
public:
  LinkedList();
  LinkedList(int* intArray, int len);
  ~LinkedList();
  void append(const int data);
  void insertFront(const int data);
  void printList();
  void summation1(LinkedList& list1, LinkedList& list2);
  void summation2(LinkedList& list1, LinkedList& list2);
};

LinkedList::LinkedList(){
  head = NULL;
  numNode = 0;
}

LinkedList::LinkedList(int* intArray,int len){
  head = NULL;
  for(int i=len-1;i>=0;--i){
    Node* tempNode = new Node;
    tempNode->data = intArray[i];
    tempNode->next = head;
    head = tempNode;
  }
  numNode = len;
}
LinkedList::~LinkedList(){
  if(head != NULL){
    Node* curNode = head->next;
    Node* prevNode = head;
    head = NULL;
    while(curNode != NULL){
      delete prevNode;
      prevNode = curNode;
      curNode = curNode->next;
    }
    delete prevNode;
  }
}

void LinkedList::append(const int data){
  Node* node = new Node;
  node->data = data;
  node->next = NULL;
  if(head==NULL){
    head = node;
  }
  else{
    Node* curNode = head;
    while(curNode->next != NULL){
      curNode = curNode->next;
    }
    curNode->next = node;
  }
  numNode++;
}

void LinkedList::insertFront(const int data){
  Node* node = new Node;
  node->data = data;
  node->next = head;
  head = node;
  numNode++;
}


void LinkedList::printList(){
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

void LinkedList::summation1(LinkedList& list1, LinkedList& list2){
  int sum = 0;
  int a=0,b=0,c=0;
  Node* curNode1 = list1.head;
  Node* curNode2 = list2.head;
  while(curNode1!=NULL || curNode2!=NULL){
    if(curNode1 != NULL){
      a = curNode1->data;
      curNode1 = curNode1->next;
    }
    else
      a = 0;
    if(curNode2 != NULL){
      b = curNode2->data;
      curNode2 = curNode2->next;
    }
    else
      b = 0;

    sum = a+b+c;
    c = sum/10;
    append(sum%10);
  }
  if(c!=0)
    append(c);

}

void LinkedList::summation2(LinkedList& list1, LinkedList& list2){
  Node* curNode1 = list1.head;
  Node* curNode2 = list2.head;
  stack<int> stack1;
  stack<int> stack2;
  while(curNode1 != NULL){
    stack1.push(curNode1->data);
    curNode1 = curNode1->next;
  }
  while(curNode2 != NULL){
    stack2.push(curNode2->data);
    curNode2 = curNode2->next;
  }
  int a=0,b=0,c=0;
  int sum=0;
  while(!stack1.empty() || !stack2.empty()){
    if(!stack1.empty()){
      a = stack1.top();
      stack1.pop();
    }
    else
      a = 0;
    if(!stack2.empty()){
      b = stack2.top();
      stack2.pop();
    }
    else
      b = 0;
    sum = a+b+c;
    c = sum/10;
    insertFront(sum%10);
  }
  if(c!=0)
    insertFront(c);
}
int main()
{
  int intArray1[4] = {7,1,6,9};
  int intArray2[3] = {5,9,5};
  LinkedList list1(intArray1, 4);
  cout<<"list1:";
  list1.printList();
  LinkedList list2(intArray2,3);
  cout<<"list2:";
  list2.printList();
  LinkedList result1, result2;
  result1.summation1(list1,list2);
  cout<<"summation1:";
  result1.printList();
  result2.summation2(list1,list2);
  cout<<"summation2:";
  result2.printList();
  return 0;
}
