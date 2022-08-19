class Solution{
    public:
    long long f(long long A[], int n, int k){
        priority_queue<int> pq;
        for(long long i=0;i<n;i++){
            pq.push(A[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long num1=f(A,N,K1);
        
        long long num2=f(A,N,K2);
        long long ans=0;
            for(long long i=0;i<N;i++){
                if(A[i]>num1&&A[i]<num2){
                    ans+=A[i];
                }
            }
        return ans;
    }
};