class Solution {
public:
    bool isPowerOfFour(int n) {
            
//~~~~~~~~~~~~~itrative approach~~~~~~~~~~~~        

      if(n==0) return false;
        while(1){
            if(n==1||n==4) return true;
           if(n%4!=0) return false;
           n=n/4;         
        }
        return true;   
        
//         ~~~~~~~~~~~~SHort best~~~~~~~~~~~~~~
        
        return (n > 0 and pow(4, int(log2(n) /
                                 log2(4))) == n);
    }
};