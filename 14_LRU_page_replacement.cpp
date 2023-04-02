#include <bits/stdc++.h>
#define MAX 100000;

using namespace std;

int main(){

    int n = 13;
    int pages[n] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;

    set<int> page_set;
    map<int,int> page_map;
    int page_faults = 0;
    int max = MAX;
    int c_max = max-1;      //Compare Max

    for(int i=0;i<n;i++){
        
        if(page_set.size() < capacity){
            if(page_set.find(pages[i]) == page_set.end()){
                page_set.insert(pages[i]);
                page_map.insert({pages[i], max});
                max--;
                page_faults++;
            }
        }
        else{
            if(page_set.find(pages[i]) == page_set.end()){
                int tmp;
                for(auto val: page_map){
                    if(val.second>c_max){
                        tmp = val.first;
                        page_map.erase(tmp);
                        c_max--;
                        break;
                    }
                }
                page_set.erase(tmp);
                page_set.insert(pages[i]);
                page_map.insert({pages[i], max});
                max--;
                page_faults++;
            }
            else{
                for(auto val: page_map){
                    if(val.first==pages[i]){
                        int tmp1;
                        tmp1 = val.first;
                        page_map.erase(tmp1);
                        page_map.insert({pages[i], max});
                        max--;
                        c_max--;
                        break;
                    }
                }
            }
        }
    }
    cout<<"Page Faults: "<<page_faults<<endl;
}