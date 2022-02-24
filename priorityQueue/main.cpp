#include <iostream>
#define N 5

using namespace std;

class Element{
public:
    int pri;
    int data;
    Element(int v=0,int p=0){
        pri=p;
        data=v;
    }

};


class PQueue{
    Element pq[N];
    int r=-1;
    int f=-1;
public:
    PQueue(){
        for(int i=0;i<N;i++){
            pq[i].pri=0;
            pq[i].data=0;
        }
    };

    bool isEmpty(){
        if(r==-1 &&f==-1)
            return true;
        return false;
    }

    bool isFull(){
        if(r==N-1)
            return true;
        return false;
    }

    void enqueue(Element ele){
        if(isFull()){
            cout<<"overflow"<<endl;
            return;
        }
        if(isEmpty()){
            r=0;
            f=0;
            pq[f]=ele;
        }
        else{
            int t=r;
            while(pq[t].pri>ele.pri && t>=f){
                pq[t+1]=pq[t];
                t--;
            }
            pq[t]=ele;
        }
    }
    Element * dequeue(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
            return NULL;
        }
        Element *temp=&pq[f];
        f+=1;
        return temp;
    }

    void display(){
        if(isEmpty()){
            cout<<"priority queue is empty"<<endl;
            return;
        }
        int t=f;
        while(t!=r+1){
            cout<<"("<<pq[t].data<<","<<pq[t].pri<<")";
            t+=1;
        }
        cout<<endl;
    }
};


int main()
{
    Element el1(1,3);
    PQueue pq;
    pq.display();
    pq.enqueue(el1);
    pq.display();
    Element el2(5,2);
    cout<<"el2"<<el2.data<<endl;
    pq.enqueue(el2);
    pq.display();
    Element el3(6,0);
    cout<<"el3"<<el3.data<<endl;
    pq.enqueue(el3);
    pq.display();
    Element el4(0,1);
    cout<<"el4"<<el4.data<<endl;
    pq.enqueue(el4);
    pq.display();

    return 0;
}
