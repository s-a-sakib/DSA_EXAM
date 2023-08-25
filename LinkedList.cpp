#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* nextNodePointer;
};
struct Node* head = NULL;

struct Node* getNewNode(){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    return newNode;
}


void insertInLinkList(int data){
    struct Node* newNode = getNewNode();
    newNode->data = data;
    newNode->nextNodePointer = NULL;

    if(head == NULL){
        head = newNode;
    }else{
        struct Node* Traverse = head;
        while(Traverse->nextNodePointer != NULL){
            Traverse = Traverse->nextNodePointer;
        }
        Traverse->nextNodePointer = newNode;
    }
}

void deleteFirstNode(){
    if(head == NULL){
        cout << "This is a empty LinkedList" << endl;
    }else{
        head = head->nextNodePointer;
    }
}

void deleteLastNode(){
    if(head == NULL){
        cout << "This is a empty LinkedList" << endl;
    }else{
        struct Node* Traverse = head ;
        struct Node* temp = head;
        while(Traverse != NULL){
            if(Traverse->nextNodePointer->nextNodePointer == NULL)
                Traverse->nextNodePointer = NULL;
            Traverse = Traverse->nextNodePointer;
        }
    }
}

void insertNodeSortedOrder(int item){
       struct Node* newNode = getNewNode() ;
       newNode -> data = item ;
       newNode -> nextNodePointer = NULL ;

       if(head == NULL or newNode -> data < head -> data){
              newNode -> nextNodePointer = head ;
              head = newNode ;
       }else{
            struct Node* previous = head ;
            struct Node* traverse = previous -> nextNodePointer ;

            while(traverse != NULL and  newNode -> data > traverse -> data){
                  previous = traverse ;
                  traverse = traverse -> nextNodePointer ;
            }
            previous -> nextNodePointer = newNode ;
            newNode -> nextNodePointer = traverse ;
       }
}


void printList(){
    struct Node* traverse = head ;
       while(traverse != NULL){
             cout << traverse -> data  << ' ' ;
             traverse = traverse -> nextNodePointer ;
       }
       cout << '\n' ;
}

int main(){
    for(int i = 0 ; i < 11 ; i++) insertInLinkList(i);
    deleteLastNode();
    printList();
    return 0;
}
