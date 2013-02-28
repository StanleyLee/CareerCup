/*
 * Problem 1.8: decide if str2 is a rotation of str1
 * Solution: step 1: check whether same length (crude decision)
 *           step 2: strstr(str2+str2,str1)
 * Time complexity: O(n); Space complexity: O(1)
 * Aurthor: Stanley Lee
 * Date: 2013/2/28
*/


#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
// decide whether str2 is a rotation of str1
bool isRotation(char* str1,char* str2){
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if(len1 != len2){
    return false;
  }
  
  else{
    char* tempStr = (char*) malloc(sizeof(char)*len2*2+1);
    strcat(tempStr,str2);
    tempStr[len2] = '\0';
    strcat(tempStr,str2);
    if(strstr(tempStr,str1)==NULL){
      free(tempStr);
      return false;
    }
    else{
      free(tempStr);
      return true;
    }
  }
}


//reverse a string in the range of index1-index2
// this function is used for rotating a string
void reverseStr(char* str,int index1,int index2){
  int i=index1,j=index2;
  while(i<j){
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
  i++;
  j--;
  }
}

// rotate a string
void rotateStr(char* str, int index){
  int len = strlen(str);
  if(index==0 || index>=len){
    cout<<"No rotation is done!"<<endl;
    return;
  }
  else{
    reverseStr(str,0,index-1);
    reverseStr(str,index,len-1);
    reverseStr(str,0,len-1);
  }

}

int main(){
  char str1[] = "hello,what";
  char str2[] = "hello,what";
  cout<<"Original string:"<<str1<<endl;
  int k=0;
  cout<<"Please input the index k for rotation:";
  cin>>k;
  rotateStr(str2,k);
  cout<<"After rotation:"<<str2<<endl;
  if(isRotation(str1,str2))
    cout<<"IS rotation!"<<endl;
  else
    cout<<"NOT rotation!"<<endl;
  return 0;
}
