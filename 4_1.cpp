/*
 * Problem 4_1: decide if a binary is balanced or not
 * Solution 4_1: find the (maxDepth-minDepth) larger than 1 or not
 * Problem 4_3: given sorted array, construct binary search tree with minimum height
 * Solution 4_3: recursively insert the middle value of the array
 * Problem 4_5: decide if a binary is BST
 * Solution 4_5: recursively inorder traverse to see if left<middle<right holds for each node
 * Author: Stanley Lee
 * Date: 2013/3/6
 */


#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Tree;
class Node{
private:
  int data;
  Node* lchild;
  Node* rchild;
public:
  Node();
  Node(int value);
  friend class Tree; // friend class, so in class Tree, can get access to private data in Node class
};

Node::Node():data(0),lchild(NULL),rchild(NULL){}
Node::Node(int value):data(value),lchild(NULL),rchild(NULL){}


class Tree{
private:
  Node* root;
public:
  Tree():root(NULL){}
  ~Tree();  // use post order traverse to delete tree, hence use to call other recursive functions
  Node*& getRoot(){return this->root;}   // return reference of NODE pointer, since you are going to change the value of root pointer in the following operations
  void deleteTree(Node* root);
  void createBST(Node** root,int intArray[],int lIndex,int rIndex); //4_3 rememeber here to user ** so as to change the value (pass by pointer)
  void insert(Node** rootT,int value); // pass by pointer to change the root value
  int maxNum(int a, int b){return a>b?a:b;}
  int minNum(int a, int b){return a>b?b:a;}
  int maxDepth(Node* rootT);
  int minDepth(Node* rootT);
  bool isBalance();  //4_1
  bool isBST(Node* rootT);  // 4_5: check is binary search tree or not
};

Tree::~Tree(){
  deleteTree(this->root);
}

void Tree::deleteTree(Node* root){
 if(root == NULL)
   return;
 deleteTree(root->lchild);
 deleteTree(root->rchild);
 delete root;
}

void Tree::insert(Node** rootT, int value){
  if(*rootT == NULL){
    *rootT = new Node(value);
    return;
  }
  if((*rootT)->data > value)
    insert(&((*rootT)->lchild),value);
  else
    insert(&((*rootT)->rchild),value);
}

void Tree::createBST(Node** rootT,int intArray[],int lIndex,int rIndex){
  if(lIndex <= rIndex){
    int mid = (lIndex+rIndex)/2;
    if((*rootT) == NULL)
      (*rootT) = new Node(*(intArray+mid));
    createBST(&((*rootT)->lchild),intArray,lIndex,mid-1);
    createBST(&((*rootT)->rchild),intArray,mid+1,rIndex);
  }
}


int Tree::maxDepth(Node* rootT){
  if(rootT == NULL)
    return 0;
  else{
    int leftDepth = maxDepth(rootT->lchild);
    int rightDepth = minDepth(rootT->rchild);
    return maxNum(leftDepth,rightDepth)+1;
  }
}

int Tree::minDepth(Node* rootT){
  if(rootT == NULL)
    return 0;
  else{
    int leftDepth = minDepth(rootT->lchild);
    int rightDepth = minDepth(rootT->rchild);
    return minNum(leftDepth,rightDepth)+1;
  }
}

bool Tree::isBalance(){
  return maxDepth(this->root)-minDepth(this->root)>1?false:true;
}

bool Tree::isBST(Node* rootT){
  if(rootT==NULL)
    return true;
  else{
    int leftData, rightData;
    int midData = rootT->data;
    if(rootT->lchild==NULL)
      leftData = INT_MIN;
    else
      leftData = rootT->lchild->data;
    if(rootT->rchild==NULL)
      rightData = INT_MAX;
    else
      rightData = rootT->rchild->data;
    if(leftData<=midData && rightData>=midData)
      return(isBST(rootT->lchild) && isBST(rootT->rchild));
    else
      return false;
  }
}

int main(){
  int intArray[]={1,2,3,4,5};
  Tree myTree;
  myTree.createBST(&(myTree.getRoot()),intArray,0,4);
  cout<<"MIN:"<<myTree.minDepth(myTree.getRoot())<<endl;
  cout<<"MAX:"<<myTree.maxDepth(myTree.getRoot())<<endl;
  cout<<"isBalance:"<<myTree.isBalance()<<endl;
  cout<<"isBST:"<<myTree.isBST(myTree.getRoot())<<endl;

}
