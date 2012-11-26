class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = prices.size();
        
        if (len<=1)
            return 0;
        
        if (len==2)
        {
            int x = prices[1] - prices[0];
            if (x>0)
                return x;
            else
                return 0;
        }
        
        vector<int> left_vector( prices.begin(), prices.begin()+len/2);
        vector<int> right_vector(prices.begin() + len/2, prices.end() );
        
        int left = maxProfit(left_vector);
        int right = maxProfit(right_vector);
        
        int i = len/2 -1;
        int j = len/2;
        int value = 0;
        
        
        int max = prices[j];
        int min = prices[i];
        if (prices[i] < prices[j])
        {
            while( prices[i] < min && i>=0 )
            {
                min = prices[i];
                i--;
            }
            
            while(prices[j] > max && j<len)
            {
                max = prices[j];
                j++;
            }
            
            value = max - min;
        }
        
        return value + left + right;
    }
};
