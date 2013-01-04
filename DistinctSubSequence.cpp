class Solution {
public:

    int len_s;
    int len_t;
    

    int numDistinct(string S, string T) {
        len_s = S.length();
        len_t = T.length();
        
        if (len_s == 0 || len_t == 0 || len_s < len_t)
        {
            return 0;
        }
        
        
        vector<vector<int> > store = vector<vector<int> >(T.length()+1, vector<int>(S.length()+1, 0));

        store[0][0] = 0;
        store[1][0] = 0;
        //store[0][1] = 0;
        for(int i=1; i<=len_s; i++)
        {
            if (S[i-1] == T[0])
                store[1][i] = 1 + store[1][i-1];
            else
                store[1][i] = store[1][i-1];
        }

        
        if ( S[0] == T[0] )
            store[1][1] = 1;
        else
            store[1][1] = 0;
        

        
        for(int j=2; j<=len_t; j++ )
        {
            for(int i=2; i<=len_s; i++)
            {   
                int keep = 0;
                if (S[i-1] == T[j-1])
                    keep = store[j-1][i-1];
                int drop = store[j][i-1];
                
                store[j][i] = keep + drop;
            }
        }
        
        return store[ len_t][len_s];
        
    }
};
