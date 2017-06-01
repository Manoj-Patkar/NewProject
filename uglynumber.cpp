#include<bits/stdc++.h>


using namespace std;

int maxDivide(int a,int b){
    while(a%b==0)
        a=a/b;
    return a;
}
int main(){

   cout<<maxDivide(300,2);
}


