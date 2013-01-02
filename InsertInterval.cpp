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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        
        if (   intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }
        
        // bugs
        if (newInterval.end <  intervals[0].start)
            result.push_back(newInterval);
        
        int new_start;
        int new_end;
        int overlap_flag = 0;
        
        for(int i=0; i<intervals.size();i++)
        {            
            if (intervals[i].end < newInterval.start && overlap_flag == 0)
            {
                result.push_back(intervals[i]);
                // bug
                if (i<intervals.size()-1 )
                {
                    if (newInterval.end < intervals[i+1].start)
                        result.push_back(newInterval);
                }
                continue;
            }
            if ( overlap_flag == 0 && newInterval.end < intervals[i].start)
            {
                result.push_back(intervals[i]);
                continue;
            }
            

            
            // bug
            if (overlap_flag == 0)
            {
                if (newInterval.start <= intervals[i].start )
                {
                    new_start = newInterval.start;
                    
                }
                else
                {
                    new_start = intervals[i].start;
                }
                overlap_flag = 1;
            }
            
            
            if (newInterval.end <= intervals[i].end)
            {
                new_end = intervals[i].end;
            }
            else
            {
                new_end = newInterval.end;
            }
            
            if (i < intervals.size() )
            {
                if (newInterval.end < intervals[i+1].start)
                {
                    Interval tmp;
                    tmp.start = new_start;
                    tmp.end = new_end;
                    result.push_back(tmp);
                    overlap_flag = 0;
                }
            }
            
        }
        
        // bugs
        if (overlap_flag == 1)
        {
                Interval tmp;
                tmp.start = new_start;
                tmp.end = new_end;
                result.push_back(tmp);
                overlap_flag = 0;            
        }
        
         // bugs
        if ( intervals[intervals.size()-1].end < newInterval.start )
        {
            result.push_back(newInterval);
        }
        
        return result;
        
    }
};


