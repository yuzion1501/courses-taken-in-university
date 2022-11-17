#include <iostream>
using namespace std;

struct Node{
    int key;
    Node*pNext;
};

Node* createNode(int data){
    Node*p = new Node();
    p->key = data;
    p->pNext = nullptr;
    return p;
}

void addToHead(Node*&head,int data){
    if (head==nullptr){
        head = createNode(data);
        return;
    }
    else 
    {
        Node*p = createNode(data);
        p->pNext=head;
        head = p;
    }
}

void addToTail(Node*&head,int data){
     if (head==nullptr){
        head = createNode(data);
        return;
    }
    else 
    {
        Node*i = head;
        Node*p = createNode(data);
        while (i->pNext!=nullptr)
            i = i->pNext;
        i->pNext = p;
    }
}

void generateList(Node*&head){
    for (int i =1;i<=10;i++){
        addToTail(head,i);
    }
}

void revesrse(Node*&head){
    Node*next = head->pNext;
    Node*prev=nullptr;
    Node*cur = head;
    while (next!=nullptr)
    {
        
    }
}

void printList(Node*head){
    while (head!=nullptr){
        cout << head->key << " ";
        head = head->pNext;
    }
}



int main(){
    Node*head = nullptr;
    //addToTail(head,1);
    //addToTail(head,2);
    generateList(head);
    printList(head);
}