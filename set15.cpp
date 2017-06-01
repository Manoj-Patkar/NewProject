#include<bits/stdc++.h>

using namespace std;
int max(int a,int b){ return a>b?a:b; }
int largestBitonic(int arr[],int n){
  int li[n],ld[n];
 for(int i=0;i<n;i++){
    li[i]=1;
    ld[i]=1;
 }

  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
          if(arr[i]>arr[j])
           li[i]=max(li[i],li[j]+1);

    }

    for(int k=0;k<i;k++){
        if(arr[i] < arr[k])
            ld[i]=max(ld[i],ld[k]+1);

    }

  }

  int max_val=INT_MIN;
  for(int i=0;i<n;i++){
        if(li[i]+ld[i]-1>max_val)
            max_val=li[i]+ld[i]-1;
  }

  return max_val;


}
int main(){
       int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
       int n = sizeof(arr)/sizeof(arr[0]);

       cout<<largestBitonic(arr,n);
 }


