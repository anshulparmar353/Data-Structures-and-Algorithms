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

bool isCriticalPoint(Node* &currNode){

    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){ // local maxima
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){ //local minima
        return true;
    }

    return false;
}

vector<int> findCriticalMaximaAndMinima(Node* &head, Node* &tail){

    vector<int>ans(2,INT_MAX);
    int firstCP = -1;
    int lastCP = -1;

    Node* currNode = tail->prev;
    if(currNode==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }

    int currpos = 0;
    while(currNode->prev!=NULL){
        if(isCriticalPoint(currNode)){
            if(firstCP==-1){
                firstCP = currpos;
                lastCP = currpos;
            }else{
                ans[0] = min(ans[0],currpos-lastCP);
                ans[1] = currpos - firstCP;
                lastCP = currpos;
            }
        }
        currpos++;
        currNode = currNode->prev;
    }

    if(ans[0]==INT_MAX){
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main(){

    DoublyLinklist dl1;
    dl1.insertAtTail(1);
    dl1.insertAtTail(5);
    dl1.insertAtTail(2);
    dl1.insertAtTail(6);
    dl1.insertAtTail(3);
    dl1.display();

    vector<int> ans = findCriticalMaximaAndMinima(dl1.head,dl1.tail);

    for(int i=0 ;  i<2; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}
