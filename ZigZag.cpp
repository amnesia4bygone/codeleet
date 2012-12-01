class Solution {
    public:
        string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            vector<string> buf;
            //memset(buf, 0, sizeof(buf));

            if (nRows <= 1)
                return s;

            int k = 0;
            int offset = 0;

            for (int i=0; i<nRows; i++)
            {
                buf.push_back("");
            }

            for(int i=0; i<s.length(); i++)
            {
                k = i % (2*nRows -2);

                if (k < nRows)
                {
                    buf[k] += s[i];

                }
                else
                {


                    buf[2*nRows -k-2] += s[i];                    

                }
            }

            string result;

            for (int i =0; i<nRows; i++)
            {
                result += buf[i];
            }
            //(buffer);
            return result;

        }
};
