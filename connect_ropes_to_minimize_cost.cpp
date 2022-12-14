class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long cost=0;
        while(pq.size()>=2){
          long long first=pq.top();
          pq.pop();
          long long second=pq.top();
          pq.pop();
          cost=cost+first+second;
          pq.push(first+second);
        }
        return cost;
    }
};