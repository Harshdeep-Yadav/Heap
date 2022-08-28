class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26); // for countung the frequency of the character in tasks
        for(auto it:tasks){
            freq[it-'A']++; // frequency counted
        }
        
        sort(freq.begin(),freq.end(),greater<int>()); // sorted in decresing order
        
//         ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
        // A_,_,A,_,_,A,_,_,A,_,_,A,_,_,A 
        int ideal=(freq[0]-1)*n; // for counting the ideal spaces
        
        for(int i=1;i<freq.size();i++){
            ideal=ideal-min(freq[0]-1,freq[i]);
        }
        
        return tasks.size()+max(0,ideal);
    }
};