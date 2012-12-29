class Solution {
public:


    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string cur(".");
        string par("..");
        
        string result;
        vector<string> db;
        
        string tmp;
        for(int i=0; i<path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (tmp.length() == 0)
                {
                    
                }
                else if ( tmp == "." )
                {
                    // do nothing
                    // bug here
                    //tmp.clear();
                }
                else if ( tmp == ".." )
                {
                    if (db.size() > 0)
                        db.pop_back();
                    // bug here
                    //tmp.clear();
                }
                else
                {
                    db.push_back(tmp);
                    
                }
                tmp.clear();
                
            }
            else
            {
                tmp += path[i];
            }
        }
        
        if (tmp.length() != 0)
        {
            if ( tmp == cur )
            {
                // do nothing
            }
            else if (tmp == par )
            {
                if (db.size() > 0)
                    db.pop_back();
            }
            else
            {
                db.push_back(tmp);
                tmp.clear();
            }            
        }
            
        
        if (db.size() == 0)
            result = "/";
        else
        {
            for(int i=0; i<db.size(); i++)
            {
                result += "/";
                result += db[i];
            }
        }
            
        return result;
    }
};
