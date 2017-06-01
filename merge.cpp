#include<bits/stdc++.h>

using namespace std;


void merge(int a[],int l,int m,int r){

int i,j;

int n1=m-l+1;
int n2=r-m;
int L[n1],R[n2];
for(i=0;i<n1;i++)
    L[i]=a[l+i];
for(i=0;i<n2;i++)
    R[i]=a[m+1+i];


 i=0;
 j=0;
int k=l;

 while (i<n1 && j<n2){

    if(L[i] <= R[j])
    {
        a[k]=L[i];
        i++;
    }
    else{
        a[k]=R[j];
        j++;
    }
    k++;
 }

 while(i<n1){
    a[k]=L[i];
    i++;
    k++;
 }

 while(j<n2){
    a[k]=R[j];
    j++;
    k++;

 }


}
void merge(int arr[],int l,int r){
if(l<r){
    int m=(l+(r-1))/2;
    merge(arr,l,m);
    merge(arr,m+1,r);
    merge(arr,l,m,r);

}
}

int main(){
int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    merge(arr,0,arr_size-1);

    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";
}
