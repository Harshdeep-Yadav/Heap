 priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        pq.push(num[i]);
        if(pq.size()>k){
           ans.push_back(pq.top());
            pq.pop();
        }
       
    }
     while(pq.size()>0){
            ans.push_back(pq.top());
            pq.pop();
        }
    return ans;
