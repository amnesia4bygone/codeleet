class Solution {
public:


    void unique_insert(vector<string>& current, vector<vector<string> >& result)
    {
        vector<vector<string> >::iterator it;
        it = find(result.begin(), result.end(), current);
        if (it == result.end() )
            result.push_back(current);
    }

    void parse(string s, vector<string>& current, vector<vector<string> >&result)
    {
        unsigned int len = s.length();
        
        if (len == 0)
        {           
            // bug here
            if (current.size() > 0)
                unique_insert(current, result);
            return;
        }
        

        
        string one(s, 0, 1);
        string two;
        
        if (len > 1)
            two.assign(s, 0, 2);
        
        int i_one = atoi(one.c_str() );
        int i_two = atoi(two.c_str() );
        
        //                            bug here
        if (i_two>0 && i_two < 27 && two[0] != '0')
        {
            vector<string> current_two = current;
            string new_s(s, 2);
            current_two.push_back(two);
            parse(new_s, current_two, result);
        }
        
        // bug here
        if (i_one > 0)
        {
            vector<string> current_one = current;
            string new_s(s, 1);
            current_one.push_back(one);
            parse(new_s, current_one, result);
        }
        
        
        
    }

    int numDecodings(string s) {
        
        if (s.length() >= 1 && s[0] == '0')
            return 0;
        
        
        vector<vector<string> > result;
        vector<string> current;
        parse(s, current, result);
        return result.size();
    }
};
