//#include <iostream>
//
//using namespace std;
//
//class Heap{
//public:
//    int n;
//    int *arr;
//    Heap(){
//        n=0;
//        arr=NULL;
//    }
//
//    void heapArr(int ptr[],int s){
//        arr=ptr;
//        n=s;
//    }
//
//    void buildHeapTree(int i,int arr[],int n){
//        int left=2*i+1;
//        int right=2*i+2;
//        int largest;
//        if(left<n &&arr[left]>arr[i]){
//            largest=left;
//        }
//        else
//            largest=i;
//        if(right<n && arr[right]>arr[largest])
//            largest=right;
//
//        if(largest!=i){
//            swap(arr[largest],arr[i]);
//            buildHeapTree(largest,arr,n);
//        }
//
//        return;
//    }
//
//    void buildHeap(int m){
//        int x=m/2;
//        for(int i=x-1;i>=0;i--){
//            this->buildHeapTree(i,arr,m);
//        }
//    }
//
//    int maxOfHeap(){
//        buildHeap(n);
//        int temp=arr[0];
//        arr[0]=arr[n-1];
//        arr[n-1]=-1;
//        buildHeap(n);
//        return temp;
//    }
//
//    void sortUsingHeap(){
//        buildHeap(n);
//        for(int i=n-1;i>0;i--){
//            swap(arr[i],arr[0]);
//            buildHeap(i);
//        }
//        return ;
//    }
//
//
//    void display(){
//        for(int i=0;i<n;i++){
//            cout<<*(arr+i)<<" ";
//        }
//        cout<<endl;
//    }
//
//};
//
//
//
//int main()
//{
//    int i;
//    int arr[]={2,4,6,7,5,8};
//    int n=sizeof(arr)/sizeof(arr[0]);
//    i=0;
//
//    Heap h;
//    h.heapArr(arr,n);
//    h.display();
//    int x=n/2;
//    for(int i=x-1;i>=0;i--){
//        h.buildHeapTree(i,arr,n);
//    }
//    h.display();
//    h.sortUsingHeap();
//    h.display();
//
////    cout<<h.maxOfHeap()<<endl;
////    cout<<h.maxOfHeap()<<endl;
////    cout<<h.maxOfHeap()<<endl;
////    cout<<h.maxOfHeap()<<endl;
//
//    return 0;
//}


#include <iostream>

using namespace std;

class Heap{
public:
    int n;
    char *arr;
    Heap(){
        n=0;
        arr=NULL;
    }

    void heapArr(char ptr[],int s){
        arr=ptr;
        n=s;
    }

    void buildHeapTree(int i,char arr[],int n){
        int left=2*i+1;
        int right=2*i+2;
        int largest;
        if(left<n &&arr[left]>arr[i]){
            largest=left;
        }
        else
            largest=i;
        if(right<n && arr[right]>arr[largest])
            largest=right;

        if(largest!=i){
            swap(arr[largest],arr[i]);
            buildHeapTree(largest,arr,n);
        }

        return;
    }

    void buildHeap(int m){
        int x=m/2;
        for(int i=x-1;i>=0;i--){
            this->buildHeapTree(i,arr,m);
        }
    }

    int maxOfHeap(){
        buildHeap(n);
        int temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=-1;
        buildHeap(n);
        return temp;
    }

    void sortUsingHeap(){
        buildHeap(n);
        for(int i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            buildHeap(i);
        }
        return ;
    }


    void display(){
        for(int i=0;i<n;i++){
            cout<<*(arr+i)<<" ";
        }
        cout<<endl;
    }

};



int main()
{
    int i;
    char arr[]={'y','a','s','h','w','a','n','t','p','a'};
    int n=sizeof(arr)/sizeof(arr[0]);
    i=0;

    Heap h;
    h.heapArr(arr,n);
    h.display();
    int x=n/2;
    for(int i=x-1;i>=0;i--){
        h.buildHeapTree(i,arr,n);
    }
    h.display();
    h.sortUsingHeap();
    h.display();

//    cout<<h.maxOfHeap()<<endl;
//    cout<<h.maxOfHeap()<<endl;
//    cout<<h.maxOfHeap()<<endl;
//    cout<<h.maxOfHeap()<<endl;

    return 0;
}
