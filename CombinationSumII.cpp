#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void debug(vector<vector<vector<int> > > &x)
{
    printf("----------------------\n");
    for(int i=1; i<x.size(); i++)
    {
	if (x[i].size() == 0)   printf("--\n");
    	printf(" %d ----------------------\n", i);
	for(int j=0; j<x[i].size(); j++)
	{
	    if (x[i][j].size() == 0)   printf("--");
	    for(int m=0; m<x[i][j].size(); m++)
	    {	printf("-%d-", x[i][j][m]);
	    }
	    printf("\n");
	}
    	printf(" %d ----------------------\n", i);
    }
    printf("----------------------\n");
    printf("\n");
}

void debug2(vector<vector<int>  > &x)
{
    printf("!!!----------------------\n");
	for(int j=0; j<x.size(); j++)
	{
	    if (x[j].size() == 0)   printf("--");
	    for(int m=0; m<x[j].size(); m++)
	    {	printf("-%d-", x[j][m]);
	    }
	    printf("\n");
	}
    printf("!!!----------------------\n");
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


    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end() );
        
        if (num.size() == 0)
            return result;
        
        int len = num.size();
        vector< vector< vector<int>  > > S = vector<vector<vector<int> > >(target+1, vector<vector<int> >() );
        vector<int> M = vector<int>(target+1, 0);
        M[0] = 1;
        
        for(int i=0; i<num.size(); i++)
        {
            int k = num[i];
            if (k > target)
                continue;
            
            M[k] = 1;
            vector<int> tmp(1, k);
            
            for(int j=target-1; j>0; j--)
            {
                if (j+k > target)
                    continue;
                M[j + k] = 1;
		
                if (S[j].size() == 0)
			continue;
                for(int n=0; n<S[j].size(); n++)
                {
                    vector<int > tmp_one = S[j][n];
                    tmp_one.push_back(k);  
                    
 
                    if ( (j+k) < target)
                    {
                         S[j+k].push_back(tmp_one); 
                    }
                    else if (j+k == target)
                    {
                        uniq_insert(result,tmp_one);
                    }
                }
                
            }
            if(k< target ) 
                S[k].push_back(tmp);
            else  // == target
            {    uniq_insert( result, tmp);
		}
		debug(S);
        }
	debug2(result);
        return result;
    }
};

   

int main(void)
{
	Solution s;	
	vector<int> x;
	x.push_back(8);
	x.push_back(7);
	x.push_back(4);
	x.push_back(3);
	s.combinationSum2(x, 11);
	x.push_back(2);
	x.push_back(1);
	x.push_back(5);
	return 1;

}
