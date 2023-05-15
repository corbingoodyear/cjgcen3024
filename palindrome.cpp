#include<iostream>
#include"stack.h"
#include<cstring>
#include<cctype>
using namespace std;

bool checkPalindrom(char*str, int size){
  Stack<char> stack,stackT;
  char tempStr[size];
  int j=0;
  for(int i=0;i<size;i++){
    if((str[i]>='A' && str[i]<='Z')){
      tempStr[j]=tolower(str[i]);
      j++;
    }else if(str[i]>='a' && str[i]<='z'){
      tempStr[j]=str[i];
      j++;
    }
  }
  tempStr[j]='\0';

  int length=strlen(tempStr);

  for(int i=0;i<length;i++){
    stack.push(tempStr[i]);
  }

  for(int i=length-1;i>=0;i--){
    stackT.push(tempStr[i]);
  }

  int i=0;
  j=length-1;
  bool check=true;
  while(i<j){
    char ch1=tempStr[i];
    char ch2=tempStr[j];
    if(stack.pop(tempStr[i]) && stackT.pop(tempStr[j])){
      if(ch1!=ch2){
        check=false;
        break;
      }
    }
    i++;
    j--;
  }
  if(check){
    return true;
  }else{
    return false;
  }
}

int main(){
  char str[100];
  cout<<"Please enter a string: \n> ";
  cin.getline(str,100);
  int size=strlen(str);
  bool result=checkPalindrom(str,size);
  if(result){
    cout<<"\n\""<<str<<"\"  IS a palindrome"<<endl;
  }else{
    cout<<"\n\""<<str<<"\"  IS NOT a palindrome"<<endl;
  }
	return 0;
}