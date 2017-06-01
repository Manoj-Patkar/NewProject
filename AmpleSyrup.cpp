#include<bits/stdc++.h>

#define PI 3.14159265358979
using namespace std;

long double max(long double a,long double b){
    return a>b?a:b;
}
long double getSide(pair<long,long> pancake){
  return 2*M_PI*pancake.first*pancake.second;
}
long double getArea(pair<long,long> pancake){
    return M_PI*pancake.first*pancake.first;
}

bool  cmpPancake(pair<long,long> a,pair<long,long> b){
    return getArea(a)>getArea(b);
}

int main(){


 freopen("C:/Users/manoj.k/Documents/input/input.in","r",stdin);
 freopen("C:/Users/manoj.k/Documents/input/output.out","w",stdout);

int t;
cin>>t;

for(int i=1;i<=t;i++){
  int n,k;
  cin>>n>>k;
  long double area=0.000000000;
  pair<long,long> p[n];
  for(int j=0;j<n;j++){
    cin>>p[j].first>>p[j].second;
  }
  sort(p,p+n,cmpPancake);

  for(int j=0;j<n-k+1;j++){
        long double tempArea=getArea(p[j]);
        for(int l=j;l<j+k;l++){
        tempArea+=getSide(p[l]);
        }
        area=max(area,tempArea);
  }
    printf("Case #%d: ", i);
    cout<<setprecision(7)<<(double)area<<endl;


}



}
