class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it : barcodes){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
           int m=pq.top().first;
           int tmp=pq.top().second;
            ans.push_back(tmp);
            m--;
            pq.pop();
            if(m>0){
                int n = pq.top().first;
                int tp = pq.top().second;
                ans.push_back(tp);
                pq.pop();
                n--;
                if(n>0)
                    pq.push({n,tp});
                pq.push({m,tmp});
            }
        }
        return ans;  
    }
};