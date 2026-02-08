#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
    
};
    
class Linklist{
public:
    Node* head;
    
    Linklist(){
        head = NULL;
    }

    void insertTail(int val){
    
        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            return;
        }
        
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    
    void display(){
    
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

Node* mergeLinkLists(Node* &head1,Node* &head2){

    Node* dummyHeadNode = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if(ptr1!=NULL){
        ptr3->next = ptr1;
    }else{
        ptr3->next = ptr2;
    }
    
    return dummyHeadNode->next;
}

Node* mergekLinklist(vector<Node*> &list){

    if(list.size()==0){
        return NULL;
    }

    while(list.size()>1){
        Node* mergelist = mergeLinkLists(list[0],list[1]);
        list.push_back(mergelist);
        list.erase(list.begin());
        list.erase(list.begin());
    }

    return list[0];
}

int main(){

    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(9);
    l1.display();

    Linklist l2;
    l2.insertTail(4);
    l2.insertTail(8);
    l2.insertTail(10);
    l2.display();

    Linklist l3;
    l3.insertTail(7);
    l3.insertTail(11);
    l3.insertTail(31);
    l3.display();

    vector<Node*> list;
    list.push_back(l1.head);
    list.push_back(l2.head);
    list.push_back(l3.head);

    Linklist mergelist;
    mergelist.head = mergekLinklist(list);
    mergelist.display();
    return 0;
}