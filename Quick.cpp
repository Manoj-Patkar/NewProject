#include<bits/stdc++.h>


using namespace std;
void swap(int &a,int &b){
   int temp;
   temp=a;
   a=b;
   b=temp;
}
int partition(int arr[],int low ,int high){

int pivot =arr[high];
int i=(low-1);

for(int j=low;j<high;j++){

    if(arr[j]<=pivot){
        i++;
        swap(arr[i],arr[j]);
    }
}

swap(arr[i+1],arr[high]);

     return (i+1);
}
void quickSort(int arr[],int low ,int high){
if(low<high){
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
}

int main(){

int arr[]={5,8,3,4,1,9,15,11,99};
int size=sizeof(arr)/sizeof(arr[0]);
quickSort(arr,0,size-1);
for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

}
