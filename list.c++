#include <iostream>
using namespace std;

class LikedList{
    private:

    class Node{
        int data;
        Node*next;

        Node(int val){
            data=val;
            next=nullptr
        }
    
    
    };
        Node*head;
        public:
        LikedList(){
            head=nullptr;
        }
        

        // insert 
        void insert(int val){
            Node* newNode=new Node(val);
            
            if(head==nullptr){
                head=newNode;
                return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;

        void display(){
            Node* temp=head;
            while(temp!=nullptr){   
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
        

     void remove(int val){
        if (head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        // kuch ha agr list me ///// list me agr sirf ek node ho 
        if (head->data==val){
            Node* temp=head;   // save old head
            head=head->next; // head ko next 
            delete temp;
            return;
        }//

        Node* temp=head;

        // before the node to be deleted
        while(temp->next!=nullptr && temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            cout<<"Value not found in the list"<<endl;
            return;
        }//
        Node* nodetoDelete=temp->next;
        temp->next=nodetoDelete->next;
        delete nodetoDelete;
    }   

}