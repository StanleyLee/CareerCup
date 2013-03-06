/*
 * Problem 3_6: use two stacks to implent a queue
 * Author: Stanley Lee
 * Date: 2013/3/5
 */

 #include <iostream>
 #include <stack>
 using namespace std;

 template<typename T>
 class myQueue{
 private:
   stack<T> stack1;
   stack<T> stack2;
   int queueSize;
 public:
   myQueue() {queueSize=0;}
   void push(T value);
   void pop();
   T front();
   int size();
   bool empty();
 };

 template<typename T>
 void myQueue<T>::push(T value){
   stack1.push(value);
   queueSize++;
 }

 template<typename T>
 void myQueue<T>::pop(){
   if(queueSize>0){
     if(!stack2.empty()){
       stack2.pop();
     }
     else{
       while(!stack1.empty()){
         stack2.push(stack1.top());
         stack1.pop();
       }
     }
     queueSize--;
  }
  else
    cout<<"Empty Queue! No POP operation"<<endl;
 }

 template<typename T>
 T myQueue<T>::front(){
   if(queueSize>0){
     if(!stack2.empty()){
       return stack2.top();
     }
     else{
       while(!stack1.empty()){
         stack2.push(stack1.top());
	 stack1.pop();
       }
       return stack2.top();
     }
   }
   else{
     cout<<"Empty Queue! No FRONT operation"<<endl;
   }
 }

 template<typename T>
 int myQueue<T>::size(){
   return queueSize;
 }

 template<typename T>
 bool myQueue<T>::empty(){
   return queueSize<=0 ? true:false;
 }

 int main(){
   myQueue<int> queue1;
   cout<<"Queue size:"<<queue1.size()<<endl;
   cout<<"Queue empty:"<<queue1.empty()<<endl;
   queue1.push(1);
   queue1.push(2);
   queue1.push(3);
   queue1.push(4);
   cout<<"Queue size:"<<queue1.size()<<endl;
   cout<<"Queue empty:"<<queue1.empty()<<endl;
   while(queue1.size()>0){
     cout<<"Queue elements:"<<queue1.front()<<" ";
     queue1.pop();
   }
   cout<<endl;
   queue1.push(1);
   queue1.push(2);
   queue1.push(3);
   queue1.push(4);
   cout<<"Queue top:"<<queue1.front()<<endl;
   queue1.push(5);
   queue1.push(6);
   queue1.pop();
   queue1.pop();
   cout<<"queue top:"<<queue1.front()<<endl;
   return 0;
 }
