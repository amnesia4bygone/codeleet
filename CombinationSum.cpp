#include <vector>
#include <stdio.h>

using namespace std;

void debug(vector<int> &x)
{
	for(int i=0; i<x.size(); i++)
		printf("-%d-", x[i]);
	printf("\n");
}


class Solution {
public:
    void uniq_insert(vector<vector<int> > &result, vector<int > &tmp)
    {
	  vector<vector<int> > :: iterator it;
	  it = find( result.begin(), result.end(), tmp );
	  if (it == result.end() )
		result.push_back(tmp);
    }    

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
		    //printf("%d %d\n", k, num);
		    //debug(tmp);
                    uniq_insert( result, tmp);
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
                                
		    		//printf("%d %d--\n", k, num);
		    		//debug(tmp_result);
                            	//result.push_back( tmp_result );
                    	 	uniq_insert( result, tmp_result);
                        }
                    }
                }
                num++;
                
            }
        }
	sort(result.begin(), result.end() );
        return result;
        
        
    }
};

int main(void)
{
	Solution s;	
	vector<int> x;
	x.push_back(2);
	x.push_back(3);
	x.push_back(5);
	s.combinationSum(x, 8);
	return 1;

}
