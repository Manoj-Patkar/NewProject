#include<bits/stdc++.h>

using namespace std;

bool inRange(int low ,int high ,int lowTemp,int HighTemp){

if(HighTemp<low)
    return false;
else if(lowTemp>high)
    return false;
else
    return true;

}
bool calcServ(double xx,double xy){

   double templ=floor(xx/xy);
   double temph=ceil(xx/xy);
   double temp=xx/xy;

     if( temp >=temph*(0.9) )
        return true;

     else if(templ*(1.1) >=temp ){
        return  true;
     }

     else
        return false;


}
int main(){


    freopen("inp.in","r",stdin);
    freopen("output.out","w",stdout);

    int t;
    int n,p;


    cin>>t;

    for(int i=0;i<t;i++){
       cin>>n;
       cin>>p;
    int ing[n],ingList[n][p];

    for(int k=0;k<n;k++)
       cin>>ing[k];

       int count=0;

       for(int j=0;j<n;j++){
        for(int k=0;k<p;k++){
           int temp;
           cin>>temp;

           ingList[j][k] =temp;


        }

            sort(ingList[j],ingList[j]+p);
       }

       for(int j=0;j<p;j++){
         bool isKit=false;
        if(calcServ((double)ingList[0][j],(double)ing[0])){
         isKit=true;
        int low=ceil((double)ingList[0][j]/(ing[0]*1.1));
        int high=floor((double)ingList[0][j]/(ing[0]*0.9));
          for(int k=1;k<n;k++){

          int lowTemp=ceil((double)ingList[k][j]/(ing[k]*1.1));
          int highTemp=floor((double)ingList[k][j]/(ing[k]*0.9));
            isKit=inRange(low,high,lowTemp,highTemp);

           cout<<low<<" "<<high<<" "<<lowTemp<<" "<<highTemp<<endl;
            if(!isKit)
                break;

          }
        //  cout<<isKit<<endl;
        }

        if(isKit)
            count++;

       }

       cout<<"Case #"<<i+1<<": "<<count<<endl;


}




}
