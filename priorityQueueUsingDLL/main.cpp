#include <iostream>

using namespace std;

class Node{
public:
    int pr;
    int da;
    Node *prev;
    Node *next;

    Node(int p,int d){
        pr=p;
        da=d;
        prev=NULL;
        next=NULL;
    }
};

class PQDLL{
public:
    Node *head;
    PQDLL(){
        head=NULL;
    }

    bool isEmpty(){
        if (head==NULL)
            return true;
        return false;
    }

    void enqueue(Node *node){
//        cout<<node->pr<<node->da<<endl;
        if(isEmpty()){
                cout<<"empty"<<endl;
            head=node;
            return;
        }
        Node * temp=head;
        while(temp->next!=NULL&&temp->pr<node->pr)
            temp=temp->next;
        if(temp->prev!=NULL&&temp->pr>=node->pr){
            cout<<node->pr<<node->da<<"if"<<endl;
            Node * temp2=temp->prev;
            temp2->next=node;
            temp->prev=node;
            node->next=temp;
            node->prev=temp2;
            return;
        }
        else{
            cout<<temp->da<<"else"<<endl;
            temp->next=node;
            node->prev=temp;
            return;
        }
    }

    int dequeue(){
        if(isEmpty()){
            cout<<" queue underflow"<<endl;
            return 0;
        }
        int p,d;
        p=head->pr;
        d=head->da;
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return d;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<"("<<temp->pr<<","<<temp->da<<")---->";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    PQDLL pq;
    Node *node=new Node(1,5);
    pq.enqueue(node);
        node=new Node(9,7);
    pq.enqueue(node);
        node=new Node(7,6);
    pq.enqueue(node);
        node=new Node(2,8);
    pq.enqueue(node);
        node=new Node(3,8);
    pq.enqueue(node);
        node=new Node(2,8);
    pq.enqueue(node);
    pq.display();

    cout<<pq.dequeue()<<endl;
    pq.display();
    cout<<pq.dequeue()<<endl;
    pq.display();
    cout<<pq.dequeue()<<endl;
    pq.display();
    return 0;
}
