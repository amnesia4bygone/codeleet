#include <string>
#include <vector>
using namespace std;

class Solution {
    public:


        int return_offset(int loop_len, int & k)
        {


            int offset = (k-1)/loop_len;

            k = k - offset*loop_len;

            return offset;
        }


        string getPermutation(int n, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> stack;
            string result;
            int sum = 1;
            for(int i=1; i<=n; i++)
            {
                stack.push_back(i);
                sum *= i;
            }


            for(int i=n; i>= 1; i--)
            {
                sum /=i;

                int offset = return_offset(sum, k);

                char buf[8];
                memset(buf, 0, 8);
                sprintf(buf, "%d", stack[offset]);
                string one(buf);
                result += one;


                stack.erase(stack.begin() + offset);
            }

            return result;

        }
};

int main(void)
{
    Solution s;
    s.getPermutation(2,1);
    return 1;
}
