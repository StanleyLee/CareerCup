/*
 * Problem 3_2: implement a stack with pop/push/top/min operation with O(1) complexity 
 * Solution1: for each element, we also store the min value of all the elements in current stack
 * Solution2: (idea from other sources, implemented in this file) use another stack to keep track of the current min value in the current stack, pay attention of the push/pop operation.
 * Author: Stanley Lee
 * Time: 2013/3/5
 */



#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class myStack{
private:
  stack<T> valueStack;
  stack<T> minStack;
public:
  myStack();
  ~myStack() {};
  void push(T value);
  void pop();
  T top();
  T min();
  int size();
};

template<typename T>
myStack<T>::myStack(){
}

template<typename T>
void myStack<T>::push(T value){ 
  valueStack.push(value);
  if(minStack.size() == 0)
    minStack.push(value);
  else{
    if(minStack.top() > value)
      minStack.push(value);
  }
}

template<typename T>
void myStack<T>::pop(){
  if(valueStack.size() == 0){
    cout<<"Empty Stack!"<<endl;
    return;
  }
  else{
    T tempValue = valueStack.top();
    valueStack.pop();
    if(tempValue == minStack.top())
      minStack.pop();
  }
}

template<typename T>
T myStack<T>::top(){
  if(valueStack.size() == 0){
    cout<<"Empty Stack (TOP)!"<<endl;
    return NULL;
  }
  else{
    return valueStack.top();
  }
}

template<typename T>
T myStack<T>::min(){
  if(valueStack.size() == 0){
    cout<<"Empty Stack!"<<endl;
    return NULL;
  }
  else{
    return minStack.top();
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
  testStack.pop();
  
  testStack.pop();
  testStack.pop();
  testStack.pop();
  testStack.pop();
  cout<<"NOW top:"<<testStack.top()<<endl;;
  return 0;
}
