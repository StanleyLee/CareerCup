/*
 * Problem 2.6: detect whether a circle exists in the linkedlist. if YES, find the begining point of the circle.
 * Solution: use two poninters, speedPtr1 and speedPtr2. In the first round , the speed of speedPtr2 is twice the speed of speedPtr1, move these  two pointers until they meet each other(circle exists), otherwise(no circle); When they meet, restart speedPtr1 from header pointer and speedPtr2 from the next node with the same speed as speedPtr1. move them one node by one node, when they meet again, that's where the circle starts.
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
  void makeCircle();
  Node* detectCircle();
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

Node* LinkedList::detectCircle(){
  if(head==NULL || head->next==NULL){
   cout<<"No Circle Detected!"<<endl;
   return NULL;
  }
  Node* speedPtr1 = head;
  Node* speedPtr2 = head->next;
  while(speedPtr2 != NULL){
    if(speedPtr1 == speedPtr2)
      break;
    else{
      speedPtr1 = speedPtr1->next;
      if(speedPtr2->next != NULL){
        if(speedPtr2->next->next != NULL){
	  speedPtr2 = speedPtr2->next->next;
	}
	else{
          cout<<"No Circle Detected!"<<endl;
	  return NULL;
        }
      }
      else{
        cout<<"No Circle Detected!"<<endl;
	return NULL;
      }
    }
  }
  cout<<"Circle detected: ";
  speedPtr1 = head;
  speedPtr2 = speedPtr2->next;
  while(speedPtr1 != speedPtr2){
    speedPtr1 = speedPtr1->next;
    speedPtr2 = speedPtr2->next;
  }
  cout<<"circle begins at: "<<speedPtr1->data<<endl;
  return speedPtr1;
}

void LinkedList::makeCircle(){
  int index=1;
  Node* indexNode = head;
  Node* curNode = head;
  while(curNode->next!=NULL){
  if(index == 5)
    indexNode = curNode;
  curNode = curNode->next;
  index++;
  }
  curNode->next = indexNode;
}

int main()
{
  int intArray1[10] = {1,2,3,4,5,6,7,8,9,10};
  LinkedList list(intArray1, 10);
  cout<<"Original list:";
  list.printList();
  list.detectCircle();
  cout<<"Making Circle..."<<endl;
  list.makeCircle();
  list.detectCircle();
  cout<<"fn exits"<<endl;
  return 0;
//  list.printList();
}
