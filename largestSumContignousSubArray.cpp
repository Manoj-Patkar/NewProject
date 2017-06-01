#include<bits/stdc++.h>

using namespace std;

int LssP(int arr[],int length){

    int max_so_far=INT_MIN;
    int max_end_here=0;
    for(int i=0;i<length;i++)
    {
        max_end_here+=arr[i];

        if(max_end_here>max_so_far)
            max_so_far=max_end_here;

        if(max_end_here<0)
            max_end_here=0;

    }

    return max_so_far;
}
int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<LssP(a,n);
}

