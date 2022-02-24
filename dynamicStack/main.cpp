#include <iostream>

using namespace std;

class Stack{
private:
    int Size;
public:
    int *top{nullptr};
    int *base{nullptr};
    Stack(int s){
    Size=s;
    top=new int[s];
    base=top;
    for(size_t i=0;i<Size;i++){
        *(top+i)=0;
    }}

    void print(){
    for(size_t i=0;i<Size-1;i++){
        cout<<*(base+i+1)<<" ";
    }
    cout<<endl;}

    bool isEmpty(){
    if(top==base)
        return true;
    return false;
    }

    bool isFull(){
    if(top==(base+Size-1))
       return true;
    return false;}

    void append(int val){
        if(isFull()){
            cout<<"stack overflow"<<endl;}
        else{
            if(isEmpty()){
                *(++top)=val;
            }
            else{
                *(++top)=val;
            }
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"stack innerflow"<<endl;
            return 0;
        }
        else{
            int temp= *top;
            *top=0;
            top--;
            return temp;
        }}

    int access(int indx){
        indx+=1;
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else if(indx>Size-1||indx<1){
            cout<<"index out of range"<<endl;
            return 0;
        }
        else{
            return *(base+indx);
        }
    }

    void update(int key,int val){
        if(key>Size-1||key<1){
            cout<<"index out of range"<<endl;
        }
        else{
            *(base+key+1)=val;
        }
    }


    };

int main()
{   int n=5;
    Stack s(n+1);
    s.print();
    int option{};
    do{
        cout<<"1. append"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. access"<<endl;
        cout<<"4. isEmpty"<<endl;
        cout<<"5. isFull"<<endl;
        cout<<"6. update"<<endl;
        cout<<"7. print"<<endl;
        cout<<"8. clear screen"<<endl;
        cout<<"0. exit"<<endl;
    int indx;
    int val;
    cin>>option;
        switch(option){
    case 1:
        cout<<"enter value"<<endl;
        cin>>val;
        s.append(val);
        break;
    case 2:
        cout<<"pop value"<<endl;
        cout<<s.pop()<<endl;
        break;
    case 3:
        cout<<"Enter a valid index to access value"<<endl;
        cin>>indx;
        cout<<s.access(indx)<<endl;
        break;
    case 4:
        cout<<"is Empty "<<s.isEmpty()<<endl;
        break;

    case 5:
        cout<<"is Full "<<s.isFull()<<endl;
        break;
    case 6:
        cout<<"Enter index to be updated and value to be updated"<<endl;

        cin>>indx>>val;
        s.update(indx,val);
        break;
    case 7:
        s.print();
        break;
    case 8:
       system("cls");
       break;
    default:
        cout<<"Enter valid choice"<<endl;
        }
    }while(option!=0);
    return 0;
}
