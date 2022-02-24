#include <iostream>

using namespace std;

//hoare's algorithm

int Partition(int arr[],int s,int e){
    int pivot=arr[s];

    int i=s-1,j=e+1;
    while(true){
        //find leftmost element greater than or equal to pivot
        do{
            i++;
        }while(arr[i]<pivot);

        //find rightmost element smaller than or equal to pivot
        do{
            j--;
        }while(arr[j]>pivot);

        if (i>=j){
            return j;
        }
        swap(arr[i],arr[j]);

    }

}

void QuickSort(int arr[],int s,int e){
    if(s<e){
        int p=Partition(arr,s,e);
        QuickSort(arr,s,p);
        QuickSort(arr,p+1,e);
    }
}

int main()
{
//    int size=0;
//    cout<<"enter the size of arr"<<endl;
//    cin>>size;
//    int myarray[size];
//
 int arr [] {7,9,3,2,6};
 cout<<"before sorting : ";
 for(auto i:arr){
    cout<<i<<" ";
 }cout<<endl;

// int s=size(arr)/size(arr[0]);
int s=5;

 QuickSort(arr,0,s-1);

 cout<<"After sorting : ";
 for(auto i:arr){
    cout<<i<<" ";
 }cout<<endl;

    return 0;
}
