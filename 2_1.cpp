/*
 * Problem 2.1: remove the duplicate Node from an unsorted linkedlist
 * Solution1: double loop to compare each element with time complexity: O(n^2)
 * Solution2: use a set to decide whether a Node is duplicate or not with time complexity: O(n)
 * Aurtho: Stanley Lee
 * Data: 2013/2/27
*/


#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void removeDuplicate1(Node* head)
{
  if(head==NULL || head->next==NULL)
    return;
  else
  {
    Node* first = head->next;
    Node* firstPrev = head;   // store the previous pointer in case of deletion
    Node* second = head;
    while(second->next!=NULL)  // outler loop
    {
      while(first!=NULL)   // inner loop
      {
        if(first->data == second->data)
	{
	  firstPrev->next = first->next;
	  free(first);
	  first = firstPrev->next;
	}
	else
	{
	  firstPrev = first;
	  first = first->next;
	}
      }
      second = second->next;
      first = second->next;
      firstPrev = second;
    }
  }
}

void removeDuplicate2(Node* head)  // with extra buffer, use a set
{
  if(head==NULL || head->next==NULL)
    return;
  else
  {
    set<int> nodeSet;
    pair<set<int>::iterator, bool> insertResult;
    Node* curNode = head->next;
    Node* prevNode = head;
    nodeSet.insert(head->data);
    
    while(curNode!=NULL)
    {
      insertResult = nodeSet.insert(curNode->data);
      if(insertResult.second == false)
      {
        prevNode->next = curNode->next;
	free(curNode);
	curNode = prevNode->next;
      }
      else
      {
        prevNode = curNode;
	curNode = curNode->next;
      }

    }
  }
}

void printList(Node* head)
{
  if(head==NULL)
    cout<<"Empty List!"<<endl;
  else
  {
    Node* curNode = head;
    while(curNode->next!=NULL)
    {
      cout<<curNode->data<<"->";
      curNode = curNode->next;    
    }
    cout<<curNode->data<<endl;
  }
}

Node* constructList(int* intArray,int len)
{
  Node* head = NULL;
  for(int i=0;i<len;++i)
  {
    Node* tempNode = (Node*) malloc(sizeof(Node));
    tempNode->data = intArray[i];
    tempNode->next = head;
    head = tempNode;
  }
  return head;
}

int main()
{
  int intArray[15] = {1,2,3,4,5,5,6,7,8,8,9,10,1,1,1};
  Node* head = constructList(intArray,15);
  cout<<"Original List:"<<endl;
  printList(head);
  removeDuplicate2(head);
  cout<<"After removal:"<<endl;
  printList(head);
}
