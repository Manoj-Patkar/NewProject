#include<bits/stdc++.h>

using namespace std;
bool dyisSubsetSum(int arr[],int n,int sum);
bool isSubsetSum(int arr[],int n,int sum){
  if(sum==0)
    return true;

  if(n == 0 && sum!=0)
    return false;

   if(arr[n-1]>sum)
    return isSubsetSum(arr,n-1,sum);

   return isSubsetSum(arr,n-1,sum)||isSubsetSum(arr,n-1,sum-arr[n-1]);

}
bool findPartiion(int arr[],int n){
 int sum=0;
 for(int i=0;i<n;i++)
    sum+=arr[i];

 if(sum%2 != 0)
    return false;

   return dyisSubsetSum(arr,n,sum/2);
}


bool dyisSubsetSum(int arr[],int n,int sum){
bool t[n][sum];

for(int i=0;i<=n;i++)
    t[i][0]=true;

for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){

        if(arr[i]>j)
            t[i][j]=t[i-1][j];
        else
            t[i][j]=t[i-1][j]||t[i-1][j-arr[i]];
    }
}

for(int i=1;i<n;i++){
    for(int j=1;j<sum;j++){
        cout<<t[i][j]<<" ";
    }
    cout<<endl;
}

return t[n][sum];


}
int findPart(int arr[],int n){
int sum=0;
int i,j;

for(int i=0;i<n;i++)
    sum+=arr[i];

bool t[sum/2+1][n+1];

for(int i=0;i<=n;i++)
    t[0][i]=true;

for(int i=1;i<=sum/2;i++)
        t[i][0]=false;


    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){

         if(arr[j-1]>i)
            t[i][j]=t[i][j-1];

         else
            t[i][j]=t[i][j-1]||t[i-arr[j-1]][j-1];

        }

    }


    return t[sum/2][n];






}
int main(){

  int arr[] = {4,5,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPart(arr, n) == true)
     printf("Can be divided into two subsets "
            "of equal sum");
  else
     printf("Can not be divided into two subsets"
            " of equal sum");
  return 0;


}
