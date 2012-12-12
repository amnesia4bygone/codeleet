#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


void dump( vector<int> & record)
{
    for(int i=0; i<record.size(); i++)
    {
        printf("%d ", record[i]);
    }
    printf("\n");
}


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<Interval> result;

            vector<int > tmp;

            int len = intervals.size();

            if (len <= 1)
                return intervals;

            tmp.push_back(intervals[0].start);
            tmp.push_back(intervals[0].end);

            int offset_start = 0;
            int offset_end = 0;
            for (int i=1; i<len; i++)
            {
                offset_start = 0;
                offset_end = 0;
                for(int k=0; k<tmp.size(); k++)
                {
                    if ( intervals[i].start > tmp[k] )
                        offset_start ++;

                    if (intervals[i].end >= tmp[k])
                        offset_end++;
                }

                vector<int > new_result;
                for(int n=0; n<offset_start; n++)
                {
                    new_result.push_back(tmp[n]);
                }
                if (offset_start %2 == 0)
                    new_result.push_back(intervals[i].start);

                if (offset_end %2 == 0)
                    new_result.push_back(intervals[i].end);   

                for(int n=offset_end; n<tmp.size(); n++)
                    new_result.push_back(tmp[n]);



                tmp.clear();
                tmp = new_result;
            }


            int i=0;
            while(i<tmp.size())
            {
                Interval one;
                one.start = tmp[i++];
                one.end = tmp[i++];
                result.push_back(one);
            }


            return result;

        }
};


int main(void)
{
    Interval a(1,4);        
    Interval b(0,2);        
    Interval c(3,5);        
    vector<Interval> tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    Solution s;
    s.merge(tmp);
    return 0;
}
