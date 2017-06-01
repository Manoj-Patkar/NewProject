#include<bits/stdc++.h>
#define M 6
#define N 6
using namespace std;

bool bpm(bool bpgraph[M][N],int u,bool seen[],int matchR[]){

for(int v=0;v<N;v++){

    if(bpgraph[u][v] && !seen[v]){
        seen[v] =true;

        if(matchR[v]<0 || bpm(bpgraph,matchR[v],seen,matchR)){
            matchR[v]=u;
            return true;
        }

    }


}

return false;
}
int maxBpm(bool bpgraph[M][N]){
 int matchR[N];

 memset(matchR,-1,sizeof(matchR));
 int result=0;
 for(int u=0;u<M;u++){
    bool seen[N];
    memset(seen,-1,sizeof(seen));

    if(bpm(bpgraph,u,seen,matchR))
        result++;
 }

 return result;
}

int main(){


}
