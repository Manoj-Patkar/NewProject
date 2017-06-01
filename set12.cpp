#include<bits/stdc++.h>

using namespace std;
int max(int a,int b){
 return a>b?a:b;
}
int max(int a,int b,int c){
 return max(a,b)>c?max(a,b):c;
}
int longestPalindrome(char s[],int i,int j){

   if(i==j)
   return 1;

   if(s[i]==s[j] && i+1==j)
    return 2;

   if(s[i]==s[j]){
   return 2+longestPalindrome(s,i+1,j-1);
    }

   else
    return max(longestPalindrome(s,i+1,j),longestPalindrome(s,i,j-1));


}
int dylongestpalindrome(char s[]){
    int n=strlen(s);
    int lp[n][n],j;

    for(int i=0;i<n;i++)
        lp[i][i]=1;

        for(int cl=2;cl<=n;cl++){
            for(int i=0;i<n-cl+1;i++){

                j=i+cl-1;
                if(s[i]==s[j] && cl==2)
                    lp[i][j]=2;

                else if(s[i]==s[j])
                    lp[i][j] = 2+lp[i+1][j-1];

                else
                    lp[i][j] = max(lp[i+1][j],lp[i][j-1]);

            }

        }

   return lp[0][n-1];
}


int main(){

   char s[] ="GEEKSFORGEEKS";
   //string t="BBABCBCAB";
 int i=0,length=sizeof(s)/sizeof(*s);


 cout<< dylongestpalindrome(s);
  /* while (s[i] !=NULL ){
    cout<<s[i];
    i++;
  } */

}
