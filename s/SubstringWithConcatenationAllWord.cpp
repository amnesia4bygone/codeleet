#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
    public:

        int valid(string s, vector<string> &L)
        {
            vector<int> result;
            int len = L[0].length();
            int length = s.length();
            int number = length/len;

            vector<string> target;

            for (int i=0; i<number; i++)
            {
                string one;
                one.assign(s, i*len, len);

                target.push_back(one);
            }        

            vector<string> target2 = L;


            sort(target.begin(), target.end());
            sort(target2.begin(), target2.end());

            for(int i=0; i<number ; i++)
            {
                if (target[i] != target2[i])
                    return 0;
            }
            return 1;
        }

        /*
           int valid(string s, vector<string> &L)
           {
           vector<int> result;
           int len = L[0].length();
           int length = s.length();
           int number = length/len;

           for (int j=0; j<number; j++)
           {
           for (int i=0; i<number; i++)
           {
           string one;
           one.assign(s, i*len, len);

           if (one == L[j])
           {
           vector<int>::iterator it;
           it = find(result.begin(), result.end(), j);
           if (it == result.end() )
           result.push_back(j);
           }
           }
           }   

           vector<int>::iterator it;
           for(int j=0; j<L.size(); j++)
           {
           it = find(result.begin(), result.end(), j);
           if (it == result.end())
           return 0;
           }

           return 1;
           }*/

        vector<int> findSubstring(string S, vector<string> &L) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            vector<int> result;
            //return result;

            int len = S.length();

            if (L.size() == 0)
                return result;

            int match_len  = L.size() * L[0].length();

            for(int i=0; i<len-match_len+1; i++)
            {
                string one ;
                one.assign(S, i,  match_len );

                int ret = valid(one, L);
                if (ret == 1)
                    result.push_back(i);

            }
            return result;

        }
};
int main(void)
{
    string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    string l1("fooo");
    string l2("barr");
    string l2("wing");
    string l2("ding");
    string l2("wing");

    vector<string> L;
    L.push_back(l1);
    L.push_back(l2);

    int x = valid(s, L);
    printf("%d\n", x);
    return 1;
}
