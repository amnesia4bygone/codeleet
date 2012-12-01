class Solution {
    public:


        bool isValid(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = s.size();

            if (len == 0)
                return true;

            if (len %2 ==1 )
                return false;

            vector<char> result;

            for (int i=0;i < len ;i++)
            {
                int cur_len = result.size();

                char one = s[i]; 

                if (cur_len == 0)
                    result.push_back(one);
                else
                {



                    char two = result[cur_len -1] ;


                    if ( (two == '[' && one == ']') || (two == '(' && one==')') || (two == '{' && one == '}' ))
                    {
                        result.pop_back();
                    }
                    else
                        result.push_back(one);
                }
            }
            if(result.size() > 0)
                return false;
            else
                return true;

        }
};
