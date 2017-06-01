#include<bits/stdc++.h>


using namespace std;




struct Node{
  string  parent;
  int start;
  int end;
};
bool cmp(Node a,Node b){
    return b.start>a.start;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


   freopen("C:/Users/manoj.k/Documents/input/input.in","r",stdin);
   freopen("C:/Users/manoj.k/Documents/input/output.out","w",stdout);


   int T;
   cin>>T;


   for(int t=1;t<=T;t++){
      int ac,aj;
      vector<Node> job;
      int cquota=720,jquota=720;
      cin>>ac>>aj;
      for(int i=0;i<ac;i++)
          {
              Node node;
              node.parent="cersi";
              cin>>node.start;
              cin>>node.end;
              job.push_back(node);
              jquota=jquota-(node.end-node.start);
          }
        for(int i=0;i<aj;i++)
          {
              Node node;
              node.parent="jamie";
              cin>>node.start;
              cin>>node.end;
              job.push_back(node);
              cquota=cquota-(node.end-node.start);
          }


          sort(job.begin(),job.end(),cmp);
          Node node;
          node.parent=job.front().parent;
          node.start=(job.back().end+job.front().start);
          node.end=node.start+1;
          job.push_back(node);




          vector<int> cersi,jamie;
          int alternate=0;



          for(int j=1;j<job.size();j++){


           if(job[j].parent==job[j-1].parent){


                   if(job[j].parent=="cersi")
                    jamie.push_back(job[j].start-job[j-1].end);


                   else
                    cersi.push_back(job[j].start-job[j-1].end);


           }
           else
            alternate++;


          }


          sort(cersi.begin(),cersi.end());
          sort(jamie.begin(),jamie.end());

//         for(int i=0;i<cersi.size();i++)
//            cout<<"cersi"<<cersi[i]<<endl;
//
//         for(int i=0;i<jamie.size();i++)
//            cout<<"jamies "<<jamie[i]<<endl;

          while(cersi.size()!=0){
              //  cout<<"cquota "<<cquota<<" val "<<cersi.front()<<endl;
            if(cquota-cersi.front()>=0)
            {
                cquota-=cersi.front();
                cersi.erase(cersi.begin());
            }
            else{
                alternate=alternate+cersi.size()*2;
                break;
            }
          }



            while(jamie.size()!=0){

            if(jquota-jamie.front()>=0)
            {
                jquota-=jamie.front();
                jamie.erase(jamie.begin());
            }
             else{

                alternate=alternate+jamie.size()*2;
                break;
            }

          }


         cout<<"Case #"<<t<<": "<<alternate<<endl;





   }




}
