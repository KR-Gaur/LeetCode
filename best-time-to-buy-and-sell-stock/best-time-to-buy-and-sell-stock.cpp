class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        
        int maxi = 0;
//         int i=0, j=1;
//         while( j < prices.size() ){
//             if( prices[j]-prices[i] > maxi ) maxi=prices[j]-prices[i];
//             else if (prices[j] < prices[i]) i=j;
//             j++;
//         }
        int mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            maxi = max(maxi, prices[i]-mini);
            mini = min(mini, prices[i]);
        }        
        return maxi;
    }
};