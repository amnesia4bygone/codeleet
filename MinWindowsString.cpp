class Solution {
public:

    vector<char> fullfil(  vector<char> &s, vector<char> &t)
    {
        int slen = s.size();
        int tlen = t.size();
        
        vector<char> result;
        
        sort(s.begin(), s.end());
        
        int last =0;
        for(int i=0; i<slen; i++ )
        {
            for(int j=last; j<tlen; j++)
            {
                if ( s[i] == t[j] )
                {
                    last = j+1;
                    break;
                }
                else if (s[i] > t[j])
                {
                    result.push_back(s[i]);
                    break;
                }
            }
        }
        return result;        
    }


    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len_s = S.length();
        int len_t = T.length();
        
        if (len_s < len_t)
            return string("");
            
        if (len_s == len_t )
        {
            if (S==T)
                return S;
            else
                return string("");
        }
        
        vector<char> s;
        for(int i=0; i<len_s; i++)
            s.push_back(S[i]);
        vector<char> t;
        for(int i=0; i<len_t; i++)
            t.push_back(T[i]);  
        sort(t.begin(), t.end());
        vector< vector< vector<char> > > M = vector<vector< vector<char> > >( len_s+1, vector<vector<char> >(len_s+1) );
        
        for(int i=0; i<len_t; i++  )
        {
            vector<char> one;
            one.assign(s.begin()+ i, s.begin() + len_t - i);
            M[i][len_t-i] = fullfil(one, t);
        }
        int min = 999999;
        string min_str("");
        
        // i = offset
        for( int i=len_t; i<len_s; i++ )
        {
            char c =  S[i];
            
            for (int j=1; j<i; j++ )
            {
                if ( M[i-j][i-1].size() == 1 && M[i-j][i-1][0] == c )
                {
                    if ( min_str.length() == 0)
                        min_str.assign(S, i-j, j);
                    else
                    {
                        string tmp(S, i-j, j);
                        if (tmp.length() < min_str.length() )
                            min_str = tmp;
                    }
                }
                
            }
        }
        return min_str;
        
    }
};
