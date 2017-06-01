#include<bits/stdc++.h>


using namespace std;

struct Box{
int h,w,d;
};

int min (int x,int y){
return (x<y)?x:y;
}

int max(int x,int y){
return (x>y)?x:y;
}

int compare(const void *a,const void *b){
return ( (*(Box*)b).d * (*(Box*)b).w)-( (*(Box *)a).d * (*(Box *)a).w );
}

int maxStackHieght(Box arr[],int n){
Box rot[3*n];
int index=0;
for(int i=0;i<n;i++){
    rot[index]=arr[i];
    index++;
    //first rotation
    rot[index].h=arr[i].w;
    rot[index].d=max(arr[i].h,arr[i].d);
    rot[index].w=min(arr[i].h,arr[i].d);
    index++;

    //second rotation
    rot[index].h=arr[i].d;
    rot[index].d=max(arr[i].h,arr[i].w);
    rot[index].w=min(arr[i].h,arr[i].w);
    index++;

}

n=3*n;
int msh[n];
int max_val=0;

qsort(rot,n,sizeof(rot[0]),compare);

for(int i=0;i<n;i++)
    msh[i]=rot[i].h;

for(int i=1;i<n;i++){

    for(int j=0;j<i;j++){

        if(rot[i].w<rot[j].w && rot[i].d<rot[j].d && (msh[i]<msh[j]+rot[i].h) ){
            msh[i]=msh[j]+rot[i].h;

            if(max_val<msh[i])
                max_val=msh[i];

        }

    }

}

return max_val;
}
int main(){
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("The maximum possible height of stack is %d\n",
         maxStackHieght(arr, n) );

  return 0;


}
