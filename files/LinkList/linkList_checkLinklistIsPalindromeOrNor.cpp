#include<iostream>
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

bool isPalindrome(Node* &head){

    //1.find mid elements
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //now slow is pointing mid elememt
    //2.break the linklist form mid
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;

    //3.reverse the remaining half linklist
    while(curr!=NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    //4.check the linklist are equal or not 
    Node* head1 = head;
    Node* head2 = prev;

    while(head2!=NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;

}

int main(){

    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(3);
    l1.insertTail(2);
    l1.insertTail(1);
    l1.display();
    
    cout<<"THE LINKLIST IS PALINDROME:"<<endl;
    cout<<isPalindrome(l1.head)<<endl;
    return 0;
}

