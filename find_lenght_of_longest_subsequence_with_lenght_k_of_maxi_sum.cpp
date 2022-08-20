class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq, s;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
           s.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        while(!s.empty()){
            ans.push_back(s.top().second);
            s.pop();
        }
        return ans;
    }
};