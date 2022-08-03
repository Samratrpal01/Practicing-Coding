class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>need(amount+1,amount+1);
        need[0]=0;
        for(auto x:coins)
        for(int i=x;i<=amount;i++)    
            {
              
                    need[i]=min(need[i],need[i-x]+1);
            }
        
        
        return need.back()>amount?-1:need.back();
     
      
    }
};
 