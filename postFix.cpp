#include <bits/stdc++.h>
using namespace std;


int getCalculatedValue(int firstOperator , int secondOperator , char sign){
      if(sign == '+') return (firstOperator + secondOperator) ;
      if(sign == '-') return (firstOperator - secondOperator ) ;
      if(sign == '*') return (firstOperator * secondOperator ) ;
      if(sign == '/') return (firstOperator / secondOperator) ;
      if(sign == '^') return pow(firstOperator , secondOperator) ;
      return 0 ;
}

int postFix(string expression){
    stack<int > answer ;
       for(int i = 0 ; i < expression.size() ; i += 1){

             if(expression[i] >= '0' and expression[i] <= '9'){
                  answer.push(expression[i] - '0') ;
             }else if((expression[i] >= 'a' and expression[i] <= 'z') or (expression[i] >= 'A' and expression[i] <= 'Z')){
                int value;
                cin >> value;
                answer.push(value);
             }else{
                   int firsOperand = answer.top() ;
                   answer.pop() ;
                   int secondOperand = answer.top() ;
                   answer.pop() ;

                   int calculatedValue = getCalculatedValue(secondOperand , firsOperand , expression[i]);
                   answer.push(calculatedValue) ;
             }
       }

       return answer.top() ;
    }
    

int main(){
    string expression;
    cin >> expression;
    int result =  postFix(expression);
    cout << result << endl;
    return 0;
}
