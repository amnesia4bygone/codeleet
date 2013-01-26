#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void debug(vector<vector<vector<int> > > &x)
{
    for(int i=0; i<x.size(); i++)
	{
	if (x[i].size() == 0)   printf("--\n");
	for(int j=0; j<x[i].size(); j++)
	{
		if (x[i][j].size() == 0)   printf("--");
    		for(int m=0; m<x[i][j].size(); m++)
		{	printf("-%d-", x[i][j][m]);
		}
			printf("\n");
	}
	}
	printf("\n");
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
        
        sort(candidates.begin(), candidates.end());
        
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
                
                // bug: miss it, and second not right poistion
                for(int i=1; i<=M.size(); i++)
                {
                    if ( k*num + i < target )
                    {
                        M[i + k*num] = 1;
                                                  
                        for ( int j =0; j<S[i].size(); j++ )
                        {
                            vector<int> tmp_pp = S[i][j];
                            for(int n=0; n<num; n++)
                                tmp_pp.push_back(k);
                            S[i+k*num].push_back(tmp_pp);
                        }
                    }
    
                }
                                
                
                
                if (k*num == target)
                {
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
                                
                    	 	uniq_insert( result, tmp_result);
                        }
                    }
                }
                num++;
                
            }
        }
        
        // bug here, no inner sort
        for(unsigned int i=0; i<result.size(); i++)
            sort( result[i].begin(), result[i].end() );
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
