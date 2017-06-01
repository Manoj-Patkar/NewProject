#include<bits/stdc++.h>

using namespace std;

int max(int a,int b){ return a>b?a:b;}
int func(int arr[],int n){
    int lis[n+1],i,j;


    int max_val=INT_MIN;

    for(int i=0;i<n;i++)
        lis[i]=1;

    for(i=1;i<n;i++){

        for(j=0;j<i;j++){

            if(arr[j]<arr[i]){
            lis[i]=max(lis[i],lis[j]+arr[i]);
            }


        }
        if(lis[i]>max_val)
            max_val=lis[i];


    }


    return max_val;

}

int cellIndex(vector<int> &v,int l,int r,int key)
{
    while(r-l >1)
    {
        int m= l+(r-l)/2;

        if(v[m] >= key)
            r=m;

        else
            l=m;


    }

    return  r;

}
int ls(vector<int> &v){

if(v.size()== 0)
    return 0;

vector<int> tail(v.size(),0);
int length=1;
 tail[0]=v[0];

   for(int i=0;i<v.size();i++){

      if(v[i]<tail[0])
        tail[0] = v[i];

      else if(v[i]>tail[length-1])
         tail[length++]=v[i];

      else
        tail[cellIndex(tail,1,length-1,v[i])]=v[i];

   }
     int max_val=0;

   for(int i=0;i<length;i++)
     max_val=max_val+tail[i];

   return max_val;

 }


int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
     vector<int> v(arr,arr+n);
    cout<<ls(v);

}
