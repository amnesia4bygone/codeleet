class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> >  result;

            int len = S.size();

            if (len == 0)
                return result;

            sort(S.begin(), S.end());

            vector<int > one;
            result.push_back(one);

            // i means element number of subset
            for (int i=0; i<S.size(); i++)
            {
                int number = result.size();
                for (int j=0; j<number; j++)
                {
                    vector<int > one = result[j];
                    one.push_back(S[i]);

                    vector<vector<int> >::iterator it ;
                    it = find(result.begin(), result.end(), one);
                    if (it == result.end())
                        result.push_back(one);
                }
            }

            return result;

        }
};

