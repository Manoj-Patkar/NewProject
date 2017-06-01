#include<bits/stdc++.h>
#define INF 999999
using namespace std;



int min(int a,int b,int c,int d){
 return min(min(a,b),min(c,d));
}
int solveMaze(vector<vector<char> > v,int posx,int posy,int desx,int desy){

  // if nodes are equal
  if(posx==desx && posy==desy)
    return 0;

    //if the point exceeds boundry
    else if(posx >= v.size() || posy>= v[0].size() || posx < 0 || posy < 0)
        return INF;




   else {
    if(v[posx][posy]=='-' || v[posx][posy]=='d' || v[posx][posy]=='s'){
        v[posx][posy]='*';
      //  cout<<posx<<" "<<posy<<endl;
        return 1+min(solveMaze(v,posx+1,posy,desx,desy),
                     solveMaze(v,posx-1,posy,desx,desy),
                     solveMaze(v,posx,posy+1,desx,desy),
                     solveMaze(v,posx,posy-1,desx,desy));
    }

    else
        return INF;

   }


}
int main(){


vector<vector<char> > vec;

int size,desx=0,desy=0,posx=0,posy=0;

cin>>size;

for(int i=0;i<size;i++){
    vector<char> temp;
    for(int j=0;j<size;j++)
    {
     char c;
     cin>>c;
    temp.push_back(c);

    if(c=='s')
    {
     posx=i;posy=j;
    }

    if(c=='d')
    {
        desx=i; desy=j;
    }


    }
  vec.push_back(temp);
}
//acout<<posx<<" "<<posy<<" "<<desx<<" "<<desy<<endl;
cout<<solveMaze(vec,posx,posy,desx,desy);

//for(int i=0;i<vec.size();i++){
//    for(int j=0;j<vec[i].size();j++){
//        cout<<vec[i][j];
//    }
//    cout<<endl;
//}


}
