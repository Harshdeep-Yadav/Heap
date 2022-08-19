class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            map[nums[i]]++;   
        }
        for(auto it : map){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
          for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
          }
        return ans;
    }
};