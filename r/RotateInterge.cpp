class Solution {
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            vector<int> result; 

            int flag = 0;

            if (x<0)
            {
                flag =1 ;
                x *= -1;
            }

            while(x != 0)
            {
                int one = x %10;
                result.push_back(one);
                x = x/10;
            }

            int final = 0;


            for(int i=0; i<result.size(); i++)
            {
                final = final * 10;
                final += result[i];
            }

            if (flag == 1)
                final *= -1;

            return final;
        }
};
