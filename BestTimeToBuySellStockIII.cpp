class Solution {
public:

    int find_profit_one(vector<int> &prices, int &begin, int &end)
    {
        int len = prices.size();
        if (len <=1)
        {
            begin = 1;
            end  = -1;
            return 0;
        }
        
        if (len ==2)
        {
            int x = prices[1] - prices[0];
            if ( x > 0 ) 
            {
                begin = 0;
                end = 1;
                return x;
            }
            else
            {
                begin = 1;
                end = -1;
                return 0;
            }
        }
        
        vector<int> left_price(prices.begin(), prices.begin() + len/2 );
        vector<int> right_price(prices.begin() + len/2  , prices.end() );
        
        int left_begin;
        int left_end;
        int right_begin;
        int right_end;
        
        int left = find_profit_one(left_price, left_begin, left_end);        
        int right = find_profit_one(right_price, right_begin, right_end);
    
        int i = len/2 -1;
        int j = len/2;
        int min = 999999;
        int max = -1;
        
    
        while(i  >= 0)
        {
            if (prices[i] < min)
            {
                min = prices[i];
                begin = i;
            }
            i--;
        }
        
        while(j <len)
        {
            if (prices[j] > max)
            {
                max = prices[j];
                end = j;
            }
            j++;
        }
        
        
        int value = max - min;
        if (value < 0)
        {
            value = 0;
            //begin = len;
            //end = 0;
        }
        
        if (value > left && value > right)
        {
            
            return value;
        }
        else if (left > right)
        {
            begin = left_begin;
            end = left_end;
            return left;
        }
        else
        {
            begin = right_begin+left_price.size();
            end = right_end + left_price.size();
            return right;
        }
    }


    int find_profit_two(vector<int> &prices)
    {
        int len = prices.size();
        if (len <=1)
            return 0;
        
        if (len ==2)
        {
            int x = prices[1] - prices[0];
            if ( x > 0 ) 
            {
                return x;
            }
            else
                return 0;
        }
        
        int m,n;
        int value3 = find_profit_one(prices, m,n);
        
        vector<int> left_price(prices.begin(), prices.begin() + len/2 );
        vector<int> right_price(prices.begin() + len/2  , prices.end() );
        
        

        int left_begin, left_end, right_begin, right_end;
        
        int left = find_profit_one(left_price,left_begin, left_end);        
        int right = find_profit_one(right_price, right_begin, right_end);
        
        vector<int> left_new_price (prices.begin() + left_end + 1, prices.end() );
        vector<int> right_new_price(prices.begin(), prices.begin() + left_price.size() + right_begin);
        
        int x,y,z,u;
        int value1 = find_profit_one(left_new_price, x,y);
        int value2 = find_profit_one(right_new_price, z, u);
    
        int left_two = find_profit_two(left_price);
        int right_two = find_profit_two(right_price);



/*
        int i = len/2 -1; 
        int j = len/2;
        int value = 0;
     
     
        int max = 0;
        int min =99999;
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
            
            if (value <=0 )
                value = 0;
            else
            {
                vector<int> left_price(prices.begin(), prices.begin() + i +1 );
                vector<int> right_price(prices.begin() + j  , prices.end() );
                
                
                int left = 0;    
                int right = 0;
                
                if (i>=0)
                    left = find_profit_one(left_price);    
                if (j<len) 
                    right = find_profit_one(right_price);    
                
                if (left>right)
                    value += left;
                else
                    value += right;
            }            
                
        }     
     
      */
    

        
        vector<int> result;
        result.push_back(left + right);
        result.push_back(left_two);
        result.push_back(right_two);
        result.push_back(value1+left);
        result.push_back(value2 + right);
        result.push_back(value3);

        sort(result.begin(), result.end() );
        return result[result.size() -1];
        
    }

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len  = prices.size();
        
        if (len <=1)
            return 0;
        
        if (len ==2)
        {
            int x = prices[1] - prices[0];
            if ( x > 0 ) 
                return x;
            else
                return 0;
        }
    
        return find_profit_two(prices);
        
    }
};
