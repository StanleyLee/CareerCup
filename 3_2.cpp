/*
 * Problem 3_2: implement a stack with pop/push/top/min operation with O(1) complexity 
 * Solution1: for each element, we also store the min value of all the elements in current stack
 * Solution2: (idea from other sources, not implemented) use another stack to keep track of the current min value in the current stack, pay attention of the push/pop operation.
 * Author: Stanley Lee
 * Time: 2013/3/5
 */



#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Node{
public:
  T value;
  T minValue;
  Node(T value, T minValue);
};

template<typename T>
Node<T>::Node(T value, T minValue){
  this->value = value;
  this->minValue = minValue;
}

template<typename T>
class myStack{
private:
  int stackSize;
  stack<Node<T>*> minStack;
public:
  myStack();
  ~myStack();
  void push(T value);
  void pop();
  T top();
  T min();
  int size();
};

template<typename T>
myStack<T>::myStack(){
  stackSize = 0;
}

template<typename T>
myStack<T>::~myStack(){
  if(stackSize==0)
    return;
  else{
    while(stackSize>0){
      Node<T>* curNode = minStack.top();
      minStack.pop();
      delete curNode;
      stackSize--;
    }
  }
}

template<typename T>
void myStack<T>::push(T value){
  Node<T>* curNode = NULL;
  if(stackSize==0){
    curNode = new Node<T>(value,value);
  }
  else{
    Node<T>* tempNode = minStack.top();
    if(tempNode->minValue > value){
      curNode = new Node<T>(value,value);
    }
    else{
      curNode = new Node<T>(value,tempNode->minValue);
    }
  }
  minStack.push(curNode);
  stackSize++;
}

template<typename T>
void myStack<T>::pop(){
  if(stackSize == 0){
    cout<<"Empty stack!"<<endl;
  }
  else{
    Node<T>* curNode = minStack.top();
    minStack.pop();
    delete curNode;
    stackSize--;
  }
}

template<typename T>
T myStack<T>::top(){
  if(stackSize == 0){
    cout<<"Empty Stack!"<<endl;
    return NULL;
  }
  else{
    Node<T>* curNode = minStack.top();
    return curNode->value;
  }
}

template<typename T>
T myStack<T>::min(){
  if(stackSize == 0){
    cout<<"Empty Stack!"<<endl;
    return NULL;
  }
  else{
    Node<T>* curNode = minStack.top();
    return curNode->minValue;
  }
}


int main(){
  myStack<float> testStack;
  float stackMin = 0;
  testStack.push(1.3);
  testStack.push(5.6);
  cout<<"top:"<<testStack.top()<<endl;
  cout<<"min:"<<testStack.min()<<endl;
  testStack.push(0.3);
  testStack.push(10);
  testStack.push(7);
  cout<<"top:"<<testStack.top()<<endl;
  cout<<"min:"<<testStack.min()<<endl;
  testStack.pop();
  cout<<"top:"<<testStack.top()<<endl;
  cout<<"min:"<<testStack.min()<<endl;
  return 0;
}
