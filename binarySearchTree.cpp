#include <bits/stdc++.h>
#define M 1000
using namespace std;

int BST[M];

void insertBST(int data){
    int index = 1;
    while(BST[index] != -M){
        if(data < BST[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    BST[index] = data;
}

bool isFound(int item){
      int index = 1 ;
      while(BST[index] != -M){
             if(BST[index] == item){
                  return true ;
             }else if(item > BST[index]){
                   index = 2 * index + 1 ;
             }else {
                    index = 2 * index ;
             }
      }
      return false ;
}

int getPosition(int item){
    int index = 1  , position = -1 ;
    while(BST[index] != -M){
        if(item == BST[index]){
            position = index ;
            break ;
        }else if(item > BST[index]){
            index = 2 * index + 1 ;
        }else {
            index = 2 * index ;
        }
       }
    return position ;
}

void printBST(int index){
    if(BST[index] == -M){
        return;
    }
    printBST(2 * index);
    cout << BST[index] <<'(' << index << ')' << "  ";
    printBST(2 * index + 1);
}

int main(){
    for(int i = 0 ; i < M ; i++) BST[i] = -M;

    int array[] = {7,8,2,4,6,9,5,1,25,15,10};
    for(int i = 0; i < 11; i++) insertBST(array[i]);
    printBST(1);
    cout << endl;
    return 0;
}