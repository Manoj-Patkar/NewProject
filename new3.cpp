#include<bits/stdc++.h>

 using namespace std;
int max(int a,int b){
return a>b?a:b;
}
int eggdrop(int k,int n){
    if(k==1 || k==0)
        return k;

    if(n==1)
        return k;

    int minval=INT_MAX,x,res;

    for(int i=1;i<=k;i++){
        res=1+max(eggdrop(i-1,n-1),eggdrop(k-i,n));

        if(res<minval)
            minval=res;
    }

    return minval;

 }

 int dyeggdrop(int n,int k){
     int s[n+1][k+1];
     int res,minval=INT_MAX;

     for(int i=1;i<=n;i++){
           s[i][0]=0;
           s[i][1]=1;
     }

     for(int j=1;j<=k;j++)
        s[1][j]=j;

     for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            s[i][j]=INT_MAX;
           for(int x=1;x<=j;x++){

          res=1+max(s[i-1][x-1] ,s[i][j-x]);

          if(res<s[i][j])
           s[i][j]=res;

           }
        }
     }

  return s[n][k];
 }
 int main(){

     cout<<dyeggdrop(2,10);

 }
