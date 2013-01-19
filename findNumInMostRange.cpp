#include <vector>
#include "stdio.h"
using namespace std;

int findnum(vector< vector<int > > & ranges)
{
	int len = ranges.size();
	
	if (len ==0)
		return 0;
	if (len == 1)
		return ranges[0][0];
	
	int min = ranges[0][0];
	int max = ranges[0][1];
	int num = 0;
	int result = min;

	// [1,2] [4,5] [4,6] [7,10]
	for(int i=1; i<len; i++)
	{
		int overlap = 0;
		int cur_result = 0;
		int cur_min = ranges[i][0];
		int cur_max = ranges[i][1];
		
		for(int j=i-1; j>=0; j--)
		{
			if ( ranges[j][1] <= cur_min )
				overlap++;
			if (ranges[j][0] >= cur_min)
			{
				 cur_min = ranges[j][0];	
			}
			if (ranges[j][1] <=  cur_max )
			{
				cur_max = ranges[j][1];
			}

		}
		if (overlap > num)
		{
			num = overlap;
			result = cur_min;
		}
	}

	return result;
	
}

int main(void)
{
	vector< vector<int> > ranges;
	vector<int > tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	ranges.push_back(tmp);
	
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(5);
	ranges.push_back(tmp);
	
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(7);
	ranges.push_back(tmp);
	
	tmp.clear();
	tmp.push_back(5);
	tmp.push_back(10);
	ranges.push_back(tmp);
	
 	printf("%d\n", findnum(ranges) );	
	
}
