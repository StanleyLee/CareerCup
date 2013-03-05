/*
 * Problem 2.7: decide if a linked list is a palindrome or not.
 * Solution: first to find the lenght of the linkedlist; then sotre the first half of the linked list in a stack, then compare with the second half of the linked list
 * Time complexity: O(n);  Spcae complexity: O(n)
 * Aurthor: Stanley Lee
 * Date: 2013/3/4
*/


#include <iostream>
#include <stack>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node<T>* next;
};

template<typename T>
class LinkedList{
private:
  Node<T>* head;  // head pointer to the list
  int numNode; // number of nodes in the list
public:
  LinkedList();
  LinkedList(T* intArray, int len);
  ~LinkedList();
  void append(const T data);
  void insertFront(const T data);
  void printList();
  bool isPalindrome();
};

template<typename T>
LinkedList<T>::LinkedList(){
  head = NULL;
  numNode = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T* intArray,int len){
  head = NULL;
  for(int i=len-1;i>=0;--i){
    Node<T>* tempNode = new Node<T>;
    tempNode->data = intArray[i];
    tempNode->next = head;
    head = tempNode;
  }
  numNode = len;
}

template<typename T>
LinkedList<T>::~LinkedList(){
  if(head != NULL){
    Node<T>* curNode = head->next;
    Node<T>* prevNode = head;
    head = NULL;
    while(curNode != NULL){
      delete prevNode;
      prevNode = curNode;
      curNode = curNode->next;
    }
    delete prevNode;
  }
}

template<typename T>
void LinkedList<T>::append(const T data){
  Node<T>* node = new Node<T>;
  node->data = data;
  node->next = NULL;
  if(head==NULL){
    head = node;
  }
  else{
    Node<T>* curNode = head;
    while(curNode->next != NULL){
      curNode = curNode->next;
    }
    curNode->next = node;
  }
  numNode++;
}

template<typename T>
void LinkedList<T>::insertFront(const T data){
  Node<T>* node = new Node<T>;
  node->data = data;
  node->next = head;
  head = node;
  numNode++;
}

template<typename T>
void LinkedList<T>::printList(){
  if(head==NULL){
    cout<<"This is an empty list!"<<endl;
  }
  else{
    Node<T>* curNode = head;
    while(curNode->next!=NULL){
      cout<<curNode->data<<"->";
      curNode = curNode->next;
    }
    cout<<curNode->data<<endl;
  }
}

template<typename T>
bool LinkedList<T>::isPalindrome(){
  if(head==NULL || head->next==NULL)
    return true;
  else{
    int len = 0;
    Node<T>* curNode = head;
    while(curNode != NULL){
      len++;
      curNode = curNode->next;
    }
    stack<T> halfList;
    int halfLen = len/2;
    cout<<"halfLen:"<<halfLen<<endl;
    int count = 0;
    curNode = head;
    while(curNode != NULL){
      count++;
      if(count <= halfLen)
        halfList.push(curNode->data);
      else{
        if(len%2 && count==(halfLen+1))
	  curNode = curNode->next;
	if(curNode->data != halfList.top())
	  return false;
	halfList.pop();
      }
      curNode = curNode->next;
    }
  }
  return true;
}

int main()
{
  char intArray1[7] = {'a','b','c','d','b','b','a'};
  LinkedList<char> list(intArray1, 7);
  cout<<"Original list:";
  list.printList();
  if(list.isPalindrome())
    cout<<"Palindrome"<<endl;
  else
    cout<<"NOT Palindrome"<<endl;
  int a=19/4;
  cout<<a;
  return 0;
//  list.printList();
}
