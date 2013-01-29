class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >  result;
        
        if (k==0)
            return result;
        
        
        if (k == 1)
        {
            for(int i=1;i<=n;i++)
            {
                vector<int > tmp;
                tmp.push_back(i);
                result.push_back(tmp);
            }
            return result;
        }
        
        for(int x=n; x>=1; x--)
        {
            int num = x;
            
            vector<vector<int> > tmp = combine(x-1, k-1);
            
            for(int i=0; i<tmp.size(); i++)
            {
                tmp[i].push_back(num);
                result.push_back(tmp[i]);
            }
        }
        
        return result;
    }
};
