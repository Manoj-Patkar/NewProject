#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;


int printSolution(int p[],int n);
int solvewordwrap(int l[],int n,int M){

 int extras[n+1][n+1];
 int lc[n+1][n+1];
 int c[n+1];
 int p[n+1];

 for(int i=1;i<=n;i++){
    extras[i][i]=M-l[i-1];
    for(int j=i+1;j<=n;j++)
        extras[i][j]=extras[i][j-1]-l[j-1]-1;

 }

 c[0]=0;
 for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if(extras[i][j]<0)
        lc[i][j]=INF;

        else
        lc[i][j]=extras[i][j]*extras[i][j]*extras[i][j];

    }

 }


 for(int j=1;j<=n;j++){
        c[j]=INF;
    for(int i=1;i<=j;i++){

        if(c[i-1]!=INF && lc[i][j]!=INF && (c[i-1]+lc[i][j]<c[j]))
        {

            c[j]=c[i-1]+lc[i][j];
            p[j]=i;
        }
    }

 }

printSolution(p,n);
 return c[4];
}
printSolution(int p[],int n){
int k;

if(p[n]==1)
    k=1;
else
   k= printSolution(p,p[n]-1)+1;
   printf("Line number %d: From word number. %d to %d \n",k,p[n],n);

}
int main(){
      int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    cout<<solvewordwrap(l, n, M);
    return 0;
}
