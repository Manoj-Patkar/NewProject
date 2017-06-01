#include<bits/stdc++.h>

using namespace std;
#define V 4
#define INF 99999

void printSolution(int graph[][V]);
void floydMarshall(int graph[][V]){
    int dist[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

           dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }

        }
    }

    printSolution(dist);

}
void printSolution(int graph[][V]){
     cout<<"The shortest matrix is:"<<endl;

     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
           if(graph[i][j]==INF)
           {
              printf("%7s", "INF");
           }
           else
            printf ("%7d", graph[i][j]);
     }
     cout<<endl;
     }


}
int main(){

      int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

                      floydMarshall(graph);
}



