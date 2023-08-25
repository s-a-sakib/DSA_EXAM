#include <bits/stdc++.h>
#define M 1000
int binaryTree[M];
using namespace std;

void makeTree(int value){
    queue < int > queue;
    int root = 0;

    if(binaryTree[root] == -1){
        binaryTree[root] = value;
        return;
    }

    queue.push(root);

    while(queue.size() != 0){
        int current = queue.front();
        queue.pop();

        int left = current + 1 , right = current + 2;

        if(binaryTree[left] == -1){
            binaryTree[left] = value;
            break;
        }else if(binaryTree[right] == -1){
            binaryTree[right] = value;
            break;
        }else{
            queue.push(left);
            queue.push(right);
        }
    }
}

void printPreOrder(int index){
    if(binaryTree[index] == -1){
        return;
    }
    cout << binaryTree[index] << ' ' ;
    printPreOrder(2 * index + 1) ;
    printPreOrder(2 * index + 2) ;
}

void printInOrder(int index){
    if(binaryTree[index] == -1){
        return;
    }  
    printPreOrder(2 * index + 1) ;
    cout << binaryTree[index] << ' ' ;
    printPreOrder(2 * index + 2) ;
}

void printPostOrder(int index){
    if(binaryTree[index] == -1){
        return;
    }  
    printPreOrder(2 * index + 1) ;
    printPreOrder(2 * index + 2) ;
    cout << binaryTree[index] << ' ' ;
}

int main(){
        for(int i = 0 ; i < M ; i += 1){
               binaryTree[i] = -1 ;
               //very indeies contains null 
        }

        int numberOfElement = 6 ;

        int a[] = {5 , 6 , 1 , 2 , 4 , 3} ;
        for(int i = 0 ; i < numberOfElement ; i += 1){
              makeTree(a[i]) ;
        }

        int root = 0 ;
        cout << "Pre-order : " ;
        printPreOrder(root) ;
        cout << '\n' ;

        cout << "In-order : " ;
        printInOrder(root) ;
        cout << '\n' ;

        cout << "Pos-order : " ;
        printPostOrder(root) ;
        cout << '\n' ;

        return 0 ;
}