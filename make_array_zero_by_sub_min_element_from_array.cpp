class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int cur_min=0;
        while(!pq.empty()){
            if(pq.top()==0)
                pq.pop();
            else{
                int top=pq.top()-cur_min;
                if(top!=0){
                    cur_min+=top;
                    count++;
                }
            pq.pop();
            }
        }
        return count;
    }
};