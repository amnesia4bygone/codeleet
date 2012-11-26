class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = prices.size();
        
        if (len<=1)
            return 0;
        
        if (len ==2)
        {
            int x = prices[1] - prices[0];
            if ( x > 0 )
                return x;
            else
                return 0;
        }
        
        vector<int> left_price(prices.begin(), prices.begin() + len/2 );
        vector<int> right_price(prices.begin() + len/2  , prices.end() );
        
        int left =  maxProfit(left_price);
        int right = maxProfit(right_price);
        
        int min = 99999;
        int max = -1;
        for(int k = 0; k<left_price.size(); k++)
        {
            if (left_price[k] < min)
                min = left_price[k];
        }

        for(int k = 0; k<right_price.size(); k++)
        {
            if (right_price[k] > max)
                max = right_price[k];
        }
        int value = max - min;
        if (value < 0) value = 0;
        
        if (value > left && value > right)
            return value;
        
        else if (left > right)
            return left;
        else
            return right;
        
    }
};
