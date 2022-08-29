class Solution {
public:
    string reorganizeString(string s) {
        int n =s.size();
        map<char,int> mp;
        for(auto it : s){ // freq count 
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mp){
            pq.push(make_pair(it.second,it.first));
        }
        
        
        string result="";
       while(pq.size() > 1)
        {
            auto elem1 = pq.top();
           pq.pop();
            auto elem2 = pq.top();
           pq.pop();
            
            result += elem1.second;
           elem1.first --;
            result += elem2.second;
           elem2.first --;
            
            if(elem1.first > 0)
            {
                pq.push(elem1);
            }
            if(elem2.first > 0)
            {
                pq.push(elem2);
            }
        }
        
        if(!pq.empty())
        {
            if(pq.top().first > 1)
            {
                return "";
            }
            else
            {
                result += pq.top().second;
            }
        }
        
        return result;

    }
};