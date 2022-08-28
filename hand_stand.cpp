class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int m = groupSize;
        
        if(n%m != 0) return false;
        map<int,int> mp;
        for(auto x : hand) mp[x]++;
        
        while(!mp.empty()){
            auto frst = mp.begin();
            int start = (*frst).first;
            int k = m;
            while(k-- > 0){
                if(mp.count(start) == 0){
                    return false;
                }else{
                    mp[start]--;
                    if(mp[start] == 0) mp.erase(start);
                    start += 1;
                }
            }
        }
        return true;
    }
};
// ``````````````````````or````````````````````

 
        map<int,int> mp;
        for(auto it:hand){
            mp[it]++;  
        }
        
        for(auto it:mp){
            if(mp[it.first]>0)
                for(int i=1;i<groupSize;i++){
                    mp[it.first+i]-=mp[it.first];
                    if(mp[it.first+i]<0)
                        return false;
                }
        }
        return true;
    }
