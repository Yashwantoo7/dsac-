#include <iostream>

using namespace std;

int find(int a[],int x)
{
        if(a[x]!=x)
        a[x]=find(a,a[x]);
        return a[x];
       //add code here
}
void unionSet(int a[],int x,int z)
{
    int xroot=find(a,x);
    int zroot=find(a,z);
    a[xroot]=zroot;
	//add code here.
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
