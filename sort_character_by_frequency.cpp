class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        int ct=0;
        map<char,int> map;
        for(int ind=0;ind<n;ind++){
            map[s[ind]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:map){
            pq.push({i.second,i.first});   
        }
        while(!pq.empty()){
            int k=pq.top().first;
            while(k--){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;   
    }
};