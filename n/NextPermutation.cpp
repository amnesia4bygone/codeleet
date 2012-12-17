#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1)
            return;
        int i = 0;    
        for(i=num.size() -1; i>0; i--)
        {
            if (num[i] > num[i-1] )
                break;
        }
    
        if (i==0)
        {
            sort(num.begin(), num.end());
        }
        else
        {
            int target = num[i-1];
            
            int min = 999999;
            int offset = -1;
            for(int k=num.size() -1; k>=i; k--)
            {
                if (num[k]<min && num[k] > num[i-1] )
                {
                    offset = k;
                    min = num[k];
                }
            }
            
            num[i-1] = min;
            num[offset] = target;
            
            sort(num.begin() + i, num.end() );
        }
    }
};

int main(void)
{
	vector<int> num;
	num.push_back(2);
	num.push_back(3);
	num.push_back(1);
	Solution s;
	s.nextPermutation(num);
	for(int i=0; i<num.size(); i++)
		printf("%d ", num[i]);
	return 1;
}
