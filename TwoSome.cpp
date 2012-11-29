class Solution {
    public:
        vector<int> twoSum(vector<int> &number, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> pass;
            vector<int> result;

            if (number.size() <= 1)
                return result;

            if (number.size() == 2)
            {
                if (number[0] + number[1] == target)
                {
                    result.push_back(1);
                    result.push_back(2);
                }
                return result;

            }

            pass = number;
            sort(pass.begin(), pass.end());
            int len  = number.size();

            int x = 0;
            int y = 0;

            int i=0;
            int j=len-1;

            while(i<j)
            {
                int val = pass[i] + pass[j];

                if (val == target)
                {
                    x = pass[i];
                    y = pass[j];
                    break;
                }

                if (val < target)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }

            if (i>=j)
                return result;

            int first = 0;
            for (int m=0; m<number.size(); m++)
            {
                if ( first == 0)
                {
                    if (number[m] == x || number[m] == y )
                    {
                        first = 1;
                        i = m+1;
                    }
                }
                else
                {
                    if (number[m] == y || number[m] == x  )
                        j = m+1;
                }
            }



            result.push_back(i);
            result.push_back(j);
            sort(result.begin(), result.end() );
            return result;
        }
};
