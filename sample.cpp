#include<bits/stdc++.h>


using namespace std;



int main(){

     long long n;
     long long k;
     long long l;
     long long r;


 //   freopen("C-small-2-attempt1.in","r",stdin);
 //   freopen("output.out","w",stdout);

    int t;
    cin>>t;
    long long a[2*t];



    for(int i=0;i<2*t;i++)
        cin>>a[i];

    for(int i=0;i<2*t;i+=2)
    {
        n=a[i];
        k=a[i+1];
        vector<long long > vec;
        map<long long,long long> c;
        make_heap(vec.begin(),vec.end());
        vec.push_back(n);
        push_heap(vec.begin(),vec.end());
       // cout<<vec.front()<<endl;
         c.insert(pair<long long,long long>(n,1));
        while(k>0)
        {
            long long x=vec.front();
            r=(long long)ceil((long double)(x-1)/2);
            l=(long long)floor((long double)(x-1)/2);
            if(n==k)
                {
                    l=0;r=0;
                    k=0;
                }
          //  cout<<"r "<<r<<" l "<<l<<endl;
            pop_heap(vec.begin(),vec.end());
            vec.pop_back();

            vec.push_back(r);
            push_heap(vec.begin(),vec.end());

            vec.push_back(l);
            push_heap(vec.begin(),vec.end());
            k--;

        }
       cout<<"Case "<<"#"<<i/2+1<<": "<<r<<" "<<l<<endl;


    }


}

