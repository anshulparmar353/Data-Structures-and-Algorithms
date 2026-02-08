#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};


class DoublyLinklist{
public:

    Node* head;
    Node* tail;

    DoublyLinklist(){
        head = NULL;
        tail = NULL;
    }

  
    void insertAtTail(int val){

        Node* new_node = new Node (val);

        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }

    void display (){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

vector<int> pairSumInDoublyLinklist(Node* &head, Node* &tail, int x){

    vector<int> ans(2,-1);
    while(head!=tail){
        
        int sum = head->val + tail->val;
        if(sum==x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }

        if(sum<x){
            head = head->next;
        }else{
            tail = tail->prev;
        }
    }

    return ans;
}


int main(){

    DoublyLinklist dl1;
    dl1.insertAtTail(2);
    dl1.insertAtTail(5);
    dl1.insertAtTail(6);
    dl1.insertAtTail(8);
    dl1.insertAtTail(10);
    cout<<"THE GIVEN DOUBLY LINKLIST IS: "<<endl;
    dl1.display();

    cout<<"SUM OF PAIR SHOULD BE: "<<endl;
    int x;
    cin>>x;

    vector<int> ans = pairSumInDoublyLinklist(dl1.head,dl1.tail,x);

    for(int i=0; i<2; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}
