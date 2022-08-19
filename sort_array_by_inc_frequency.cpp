
#define ppi pair<int,int>
class Solution {
public:
      class Compare{
        public:
        bool operator()(ppi below, ppi above){
            
            if(below.first == above.first){ //same freq
                return below.second < above.second; //val high at top when same freq
            }
            return below.first > above.first; // less freq at TOP
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        
      priority_queue<ppi, vector<ppi>, Compare> pq;
        map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto i:map){
            pq.push({i.second,i.first});
        } 
        while(pq.size()>0){
            int freq=pq.top().first;
            int el=pq.top().second;
            for(int i=0;i<freq;i++){
                ans.push_back(el);  
            }
            pq.pop();
        }
        return ans;
    }
};

