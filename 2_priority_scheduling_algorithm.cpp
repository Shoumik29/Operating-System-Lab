//Non-Preemtive

#include <bits/stdc++.h>
#define Max 100000

using namespace std;

int main(){

    int n = 6;

    int srt_pr[n];
    int pr[n] = {2,1,3,4,3,5}; //Priority
    int ar[n] = {3,2,5,4,1,0}; //Arrival time
    int br[n] = {5,4,1,7,6,2}; //Burst time

    int time = 0;

    vector<int> proc_seq;
    
    vector<int> vec;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[j]==i){
                ar[j]==Max;
                vec.push_back(j);
            }
        }
    }
    int ind=0;
    for(auto val: vec) {srt_pr[ind]=val; ind++;}

    vector<int> pr_vec;
    vector<int> time_vec;
    while(1){
        for(int i=0;i<n;i++){
            if(ar[srt_pr[i]]<=time) pr_vec.push_back(srt_pr[i]);
        }
        
        time_vec.push_back(time);

        if(pr_vec.empty()) break;

        vector<int> prt_vec;
        for(auto val: pr_vec) prt_vec.push_back(pr[val]);

        sort(prt_vec.begin(), prt_vec.end());
        //reverse(prt_vec.begin(), prt_vec.end());

        for(auto val: prt_vec){
            for(auto prc: pr_vec){
                if(pr[prc]==val){
                    time += br[prc];
                    ar[prc] = Max;
                    proc_seq.push_back(prc+1);
                    break; 
                }
            }
            break;
        }
        prt_vec.clear();
        pr_vec.clear();
    }

    cout<<endl;

    int length = proc_seq.size();
    cout<<time_vec[0]<<endl;
    for(int i=0;i<length;i++){
        cout<<"     "<<proc_seq[i]<<endl;
        cout<<time_vec[i+1]<<endl;
    }
    cout<<endl;
}