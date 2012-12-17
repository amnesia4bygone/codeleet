class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > result;
            int n = num.size();

            vector<vector<int> > tryed;

            if (n==1)
            {   
                vector<int > one;
                one.push_back(num[0]);
                result.push_back(one);
                return result;
            }   

            for (int i=0; i<n; i++)
            {   
                int one = num[i];

                vector<int> tmp_num ;
                vector<int> one_try;
                one_try.push_back(one);
                for (int j=0; j<n; j++)
                {   
                    if (j != i)
                    {
                        tmp_num.push_back(num[j]);
                        one_try.push_back(num[j]);
                    }
                }   

                vector<vector<int> >::iterator it;
                it = find(tryed.begin(), tryed.end(), one_try);
                if (it != tryed.end() )
                {
                    continue;
                }
                else
                {
                    tryed.push_back(one_try);
                }


                vector<vector<int> > tmp_result = permuteUnique(tmp_num);

                for (int j=0; j<tmp_result.size(); j++)
                {   
                    tmp_result[j].insert(tmp_result[j].begin(), one);

                    vector<vector<int> >::iterator it;

                    it = find(result.begin(), result.end(), tmp_result[j]);

                    if (it == result.end())
                        result.push_back(tmp_result[j]);
                }   
            }   


            return result;


        }
};
