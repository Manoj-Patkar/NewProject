#include<bits/stdc++.h>

using namespace std;


int zeroOneKnapsack(int val[],int wt[],int n,int w){
    int t[n+1][w+1];

    for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){

                if (i==0 || j==0)
                    t[i][j]=0;

               else if(j<wt[i])
                    t[i][j]=t[i-1][j];

                else
                    t[i][j]=max(val[i]+t[i][j-wt[i]],t[i-1][j]);
            }

    }

    return t[n][w];
}
int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);

   cout<<zeroOneKnapsack(val,wt,n,W);
    return 0;


}
