

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > result;
        vector<int> one_result;
        
        sort(num.begin(), num.end() );
        
        int len = num.size();
        
        if (len<=2)
            return  result;
            
        if (len==3 )
        {
            if (num[0] + num[1] + num[2] == 0)  
            {
                result.push_back(num);
            }
            return result;
        }
        
        
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        int direction = 1;
        
        while( i < len-2 )
        {
            int first = num[i];
        	j=i+1;

        	while(j<len-1)
        	{
        		int second  = num[j];

	        	int target = 0 -num[i] - num[j];
	        	k = j+1;

	        	while(k <len )
	        	{
	        		if ( target == num[k] )
	        			break;
	        		k++;
	        	}

	        	if (k < len) //find it
	        	{
	        		one_result.clear();
                    one_result.push_back(num[i]);
                    one_result.push_back(num[j]);
                    one_result.push_back(num[k]);
                    
                    vector<vector<int> >::iterator tmp_find = find(result.begin(), result.end(), one_result);
                    if (tmp_find == result.end())
                        result.push_back(one_result);
	        	}

	        	j++; 
	        }
        	i++;
        }
    }
};