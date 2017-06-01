#include<bits/stdc++.h>


using namespace std;
int max(int a,int b ){
return a>b?a:b;
}
int main(){

    freopen("C:/Users/manoj.k/Documents/input/input.in","r",stdin);
    freopen("C:/Users/manoj.k/Documents/input/output.out","w",stdout);

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        int n,p;
        cin>>n>>p;
        vector<int> sol;
        sol.resize(p,0);
       // fill(sol.begin(),sol.end(),0);
        int ans=0;
        for(int j=0;j<n;j++){
            int g;
            cin>>g;
            sol[g%p]++;
        }
        if(p==2){
            ans=sol[0]+ceil((float)sol[1]/2);
        }
        else if(p==3)
        {
            ans=sol[0]+min(sol[0],sol[1])+ceil((float)(max(sol[0],sol[1]) - min(sol[0],sol[1]))/3);
        }
        else{
            ans+=sol[0];
            ans+=sol[2]/2;
            sol[2]%=2;
            ans+=min(sol[1],sol[3]);
            sol[1]-=min(sol[1],sol[3]);
            sol[2]-=min(sol[1],sol[3]);

            if(sol[2]>0){
                if(sol[1]>=2)
                {
                    sol[1]-=2;
                    ans++;
                }
                else if(sol[2]>=0){
                    sol[2]-=2;
                    ans++;
                }
                else if(sol[1]==0 && sol[2]==0){
                    ans++;
                }

                ans+=ceil((float)sol[1]/4);
                ans+=ceil((float)sol[2]/4);

            }


        }
         cout<<"Case "<<"#"<<i<<": "<<ans<<endl;
    }
}
