#include <bits/stdc++.h>
using namespace std;


int getPrecedence(char sign){
      if(sign == '^') return 3 ;
      else if(sign == '/' or sign == '*') return 2 ;
      else if(sign == '+' or sign == '-') return 1 ;
      return 0 ;
}

string getInfexToPostfix(string infex){
    stack<char > valueStack ;
        string postfix = "" ;

        for(int i = 0 ; i < infex.size() ; i += 1){
                char character = infex[i] ;

                if(character == '(') valueStack.push(character) ;
                else if(character == ')'){
                        while(!valueStack.empty() and valueStack.top() != '('){
                               postfix += valueStack.top() ;
                               valueStack.pop() ;
                        }
                        valueStack.pop() ;
                }else if((character >= '0' and character <= '9') or (character >= 'A' and character <= 'Z') or (character >= 'a' and character <= 'z')){
                        postfix += character ;
                }else{
                      while(!valueStack.empty() and getPrecedence(character) <= getPrecedence(valueStack.top())){
                           postfix += valueStack.top() ;
                           valueStack.pop() ;
                      }

                      valueStack.push(character) ;
                }
        }

        while(!valueStack.empty()){
               postfix += valueStack.top() ;
               valueStack.pop() ;
        }

        return postfix ;
}

int main(){
      string infix = "5*(6+2)-2/4" ;
      string postfix = getInfexToPostfix(infix) ;
      cout << postfix << '\n' ;
      return 0 ;
}