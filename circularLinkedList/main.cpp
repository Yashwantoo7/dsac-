#include <iostream>

using namespace std;

class Node{
public:
    int key;
    int data;
    Node *next;

    Node(){
    key=0;
    data=0;
    next=NULL;}
    Node(int k,int d){
    key=k;
    data=d;}
};

class circularLinkedList{
public:
    Node *head;
    circularLinkedList(){
    head=NULL;
    }
    circularLinkedList(Node *n){
    head=n;
    }

    //1. check if node exists using key value

    Node *nodeExists(int k){
    Node* temp=NULL;
    Node* ptr=head;
    if(ptr==NULL){
        return temp;
    }
    else{
        do{
        if(ptr->key==k){
            temp=ptr;
        }
        ptr=ptr->next;
        } while (ptr!=head);
    return temp;
    }
    }

    //2. append a node to the list
    void appendNode(Node *n){
    if(nodeExists(n->key)!=NULL){
        cout<<"Node already exists with key value "<<n->key<<endl;
    }
    else{
        if (head==NULL){
            head=n;
            n->next=head;
            }
        else{
            Node* ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=head;
        }
    }
    }

  //3. prepend node
  void prependNode(Node* n){
      if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with key value "<<n->key<<endl;
        }
    else{
        if(head==NULL){
            head=n;
            n->next=head;
        }
        else{
            Node* ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
            n->next=head;
            ptr->next=n;
            head=n;
        }
    }
  }


    //4. Insert a node after a particular node
    void insertAfter(int k,Node *n){
      Node *ptr=nodeExists(k);
      if(ptr==NULL){
        cout<<"No node exits with key value "<<k<<endl;
      }
      else{
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with key value "<<n->key<<endl;
        }
        else{
            if(ptr->next==head){
                ptr->next=n;
                n->next=head;
            }
            else{
                n->next=ptr->next;
                ptr->next=n;
            }
        }
      }
    }

    //5. delete node by unique key
    void deleteNodeByKey(int k){
    if(head==NULL){
        cout<<"singly Linked List already empty"<<endl;
    }
    else if(head!=NULL){
        if(head->key==k){
            Node* ptr=head;
            while(ptr->next!=head){
            ptr=ptr->next;
            }
            Node* temp=head;
            ptr->next=head->next;
            head=head->next;
            temp->next=NULL;
        }
        else{
        Node* ptr=head;
        bool found{false};
        Node* prevTemp;
        while(ptr->next!=head){
            if(ptr->next->key==k){
                Node* temp=ptr->next;
               ptr->next=temp->next;
               temp->next=NULL;
               found=true;
               break;
            }
            prevTemp=ptr;
            ptr=ptr->next;
        }
        if(ptr->next==head && found==false){
            prevTemp->next=head;
            ptr->next=NULL;
            found=true;
        }
        if (!found){
            cout<<"Node doesn't exist with key value"<<endl;
        }
        }
    }
    }

    //6. update node by key
    void updateNodeByKey(int k,int d){
    Node* ptr=nodeExists(k);
    if(ptr!=NULL){
            ptr->data=d;
    }
    else{
        cout<<"Node doesn't exist with key value"<<k<<endl;
    }
    }

    //7. printing
    void printList(){
        if(head==NULL){
            cout<<"No node in singly linked list";
        }
        else{
            cout<<endl<<"singly linked list value : ";
            Node* temp=head;
            while(temp->next!=head){
                cout<<"("<<temp->key<<","<<temp->data<<")--->";
                temp=temp->next;
            }
                cout<<"("<<temp->key<<","<<temp->data<<")--->";
                temp=temp->next;
        }
    }
    };

int main() {

  circularLinkedList c;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. ins()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      c.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      c.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      c.insertAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      c.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      c.updateNodeByKey(key1, data1);

      break;
    case 6:
      c.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
