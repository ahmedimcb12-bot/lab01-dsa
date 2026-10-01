#include<iostream>
using namespace std;
class Linklist{
    private:
    struct Node
    {
        int data;
        Node * next;
    };
    public:
    Node * head;
    Node * tail;
    Linklist(){
        head=tail=NULL;
    }
    public:
    void CreateThreeNodes(int v1,int v2,int v3){
        
        Node *n1 = new Node();
        Node *n2 = new Node();
        Node *n3 = new Node();
        n1->data=v1;
        n2->data=v2;
        n3->data=v3;

        n1->next=n2;
        n2->next=n3;
        n3->next=NULL;

        head=n1;
        tail=n3;        
    }
    void printLL(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void cleanList(){
        Node* temp=head;
        while(head!=NULL){
            temp=head;
            head=head->next;
            delete temp;
        }
        tail=NULL;
       
        cout<<"The LinkList is being Cleaned totally"<<endl;
    }    
    void AddNode(int val){
        Node* temp=new Node();
        temp->data=val;
        temp->next=NULL;
        if(head==NULL){
            head=tail=temp;
        }
        else{
            
            tail->next=temp;
            tail=temp;
            
        }
    }
    void CountNode(){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        cout<<"The total nodes are "<<count<<endl;
    }
    void SearchNode(int searchData){
        Node* temp=head;
        int count=1;
        bool found = false;
        if(temp==NULL){
            cout<<"The list is empty "<<endl;
            return;
        }
        else{
        while(temp != NULL) {
            if(temp->data == searchData) {
                cout << "Your searched position is " << count << endl;
                    found=true;
                break;
            }
            temp = temp->next;
            count++;
            
        }
        if(!found) {
            cout << "Value not found" << endl;
        }

    }
    while(temp!=NULL){

    }
    }
    void printsecondNode(){
        Node * temp=head;
        if(temp->next==NULL||temp==NULL){
            cout<<"The node 2 does'nt exist "<<endl;
        }
        else{
        cout<<"The second node data is "<<temp->next->data<<endl;
        }
    }
};

int main(){
    Linklist ll;
     ll.CreateThreeNodes(10,20,30);
    cout<<endl;
    ll.AddNode(20);
    cout<<endl;
    // ll.printLL();
    cout<<endl;
    // ll.CountNode();
    // cout<<endl;
    // ll.cleanList();
    cout<<endl;
    ll.SearchNode(99);
    cout<<endl;
    ll.printsecondNode();
}
