class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        
        vector<vector<int> > result;
        
        
        vector< vector<vector<int> > >S = vector<vector<vector<int> > >( target+1,  vector<vector<int> >() ) ;
        vector<int> M = vector<int>(target+1, 0);
        M[0] = 1;
        
        for(unsigned int i=0; i<candidates.size(); i++)
        {
            int k = candidates[i];
            int num = 1;
            
            
            
            while( k*num <= target)
            {
                vector<int > tmp (num, k);
                S[k*num].push_back(tmp);
                M[k*num] =1;
                
                if (k*num == target)
                {
                    result.push_back(tmp);
                }
                else
                {
                    if ( M[target-k*num] == 1 )
                    {
                        
                        for(int j=0; j< S[target-k*num].size(); j++  )
                        {
                            vector<int> tmp_result = S[target-k*num][j];
                            for(int x=0; x<num; x++)
                                tmp_result.push_back(k);
                                
                            result.push_back( tmp_result );
                        }
                    }
                }
                num++;
                
            }
        }
        return result;
        
        
    }
};
