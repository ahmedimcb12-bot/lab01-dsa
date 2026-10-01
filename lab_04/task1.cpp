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

};

int main(){
    Linklist ll;
    ll.CreateThreeNodes(1,2,3);
    ll.printLL();
    cout<<endl;
    cout<<endl;
    ll.cleanList();
}
