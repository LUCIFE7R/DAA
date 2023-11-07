#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>B1,pair<int,int>B2){
    double result1=(double)B1.first/(double)B1.second;
    double result2=(double)B2.first/(double)B2.second;
    return result1<result2;
}


int main()
{
    cout<<"Hello World";
    int N,W,a,b,MaxProfit=0;
    cout<<"Enter no. Of Objects: \n";
    cin>>N;
    cout<<"Enter capacity of Bag: \n";
    cin>>W;
     vector<pair<int, int>> item;
    // vector<pair<int,int>item;
    for(int i=0;i<N;i++){
        cout<<"Enter profit and weight of Object"<<i<<"\n";
        cin>>a>>b;
        item.push_back(make_pair(a,b));
    }
          sort(item.begin(),item.end(),cmp);
          for(int i=0;i<N;i++){
              if(item[i].second<=W){
                  W-=item[i].second;
                  MaxProfit+=item[i].first;
              }
              else
                  MaxProfit+=(item[i].first*W)/item[i].second;
              
          }
          cout<<"MaxProfit"<<MaxProfit;
    return 0;
}