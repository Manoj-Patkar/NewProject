#include<bits/stdc++.h>

using namespace std;


int minJump(int arr[],int l,int h){

if(arr[l]==0)
    return INT_MAX;

if(h==l)
    return 0;

int min=INT_MAX;

for(int i=l+1;i<=h && i<= l+arr[l];i++){
    int jumps=1+minJump(arr,i,h);
    if(jumps!=INT_MAX && jumps<min)
        min=jumps;
}

return min;
}
int dyminJump(int arr[],int n){
   int *jumps = new int[n];  // jumps[n-1] will hold the result
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

     for(int i=1;i<n;i++){

        jumps[i]=INT_MAX;
        for(int j=0;j<i;j++){

           if(i<=j+arr[j] && jumps[j]!=INT_MAX )
           {
               jumps[i]=min(jumps[i],jumps[j]+1);
               break;
           }
        }

     }

return jumps[n-1];
}
int main()
{
int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", dyminJump(arr, n));
  return 0;

}
