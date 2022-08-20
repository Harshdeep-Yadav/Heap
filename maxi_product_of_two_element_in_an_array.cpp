class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>2){
                pq.pop();
            }
        }
        int ans=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            ans+=(x-1)*(y-1);
        }
        return ans;
    }
};