class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int len = num.size();
        
        int closest_diff  = 999999;
        
        
        if (len==2)
            return num[0] + num[1];
            
        if (len==3)
            return num[0] + num[1] + num[2];
            
        int i = 0;
        int j = 1;
        int k = 2;
        int ret = 99999;
        
        while(i<len-2)
        {

            j = i+1;
            
            while (j< len-1)
            {
                k=j+1;
                
                while(k<len)
                {
                    int tmp = num[i] + num[j] + num[k];
                    int current_number = tmp - target;
                    
                    if (current_number == 0)
                        return tmp;
                        
                    if (current_number < 0 )
                        current_number = 0 - current_number;
                    
                    if( current_number < closest_diff)
                    {
                        closest_diff = current_number;
                        ret = tmp;
                    }
                    k++;            
                }   
                j++;
            }
            i++;
        }
        return ret;
    }
};
