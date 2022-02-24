#include <iostream>
#define N 5

using namespace std;

class circularDEqueue{
    int dq[N];
    int f=-1;
    int r=-1;
public:

    circularDEqueue(){
    for(int i=0;i<N;i++){
        dq[i]=0;
    }
    }

    bool isEmpty(){
        if(r==-1 && f==-1)
            return true;
        return false;
    }

    bool isFull(){
        if((r+1)%N==f)
            return true;
        return false;
    }

    void enqueueFront(int x){
        if(isEmpty())
        {
            f=0;
            r=0;
            dq[f]=x;
            return;
        }
        if(isFull()){
            cout<<"overflow"<<endl;
            return;
        }
        else{
            if(f==0)
            {
                f=N-1;
                dq[f]=x;
                return;
            }
            else{
                f=f-1;
                dq[f]=x;
                return;
            }
        }
    }

    void enqueueRear(int x){
        if(isEmpty())
        {
            f=0;
            r=0;
            dq[f]=x;
            return;
        }
        if(isFull()){
            cout<<"overflow"<<endl;
            return;
        }
        else{
            if(r==N-1){
                r=0;
                dq[r]=x;
                return;
            }
            r+=1;
            dq[r]=x;
            return;
        }

    }

    void dequeFront(){
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
            return;
        }
        if(f==r)
        {   cout<<"("<<dq[f]<<","<<f<<")"<<endl;
            f-=1;
            r-=1;
        }
        else if(f==N-1){
            cout<<"("<<dq[f]<<","<<f<<")"<<endl;
            f=0;
        }
        else
        { cout<<"("<<dq[f]<<","<<f<<")"<<endl;
            f++;
        }
    }

    void dequreRear(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
            return;
        }
        if(f==r){
            cout<<"("<<dq[r]<<","<<r<<")"<<endl;
            f-=1;
            r-=1;
        }
        else if(r==0){
            cout<<"("<<dq[r]<<","<<r<<")"<<endl;
            r=N-1;
        }
        else
        {
            cout<<"("<<dq[r]<<","<<r<<")"<<endl;
            r--;
        }

    }

    void display(){
        int i=f;
        while(i!=r){
            cout<<"("<<dq[i]<<","<<i<<")";
            i=(i+1)%N;
        }
        cout<<"("<<dq[r]<<","<<r<<")";
        cout<<endl;
        cout<<f<<" "<<r<<endl;
    }

    int getFront(){
        return dq[f];
    }
    int getRear(){
        return dq[r];
    }



};

int main()
{   //enqueue from front and dequeue form rear ->queue
    //enqueue from front and dequeue from front ->stack

    circularDEqueue DQ;
    DQ.display();
    DQ.enqueueFront(5);
    DQ.enqueueFront(4);
//    DQ.enqueueRear(3);
    DQ.enqueueFront(10);
//    DQ.enqueueRear(11);

    DQ.display();
//    DQ.dequeFront();
//    DQ.dequeFront();
    DQ.dequreRear();
//    DQ.dequeFront();
    DQ.dequreRear();

    DQ.display();


    return 0;
}
