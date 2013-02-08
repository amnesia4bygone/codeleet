class Solution {
public:

    bool trace(vector<vector<char> > &board,  vector< vector<int> > &traced , string word, int offset, int xx, int yy)
    {
        int len = word.length();
        
        if (len == 0 )
            return true;
            
        if (offset >= len)
            return true;

        char c = word[offset];
        
        int x, y;
        
        // left
        x = xx ;
        y = yy -1;
        //                                  bug: miss it
        if (y >= 0 && traced[x][y] == 0 && c == board[x][y])
        {
            traced[x][y] = 1;
            bool ret = trace( board, traced, word, offset+1 , x , y);
            if (ret == true)
                return true;
            traced[x][y] = 0;
        }
            
        y = yy + 1;
        if (y < traced[0].size() && traced[x][y] == 0 && c == board[x][y])
        {
            traced[x][y] = 1;
            bool ret = trace( board, traced, word, offset+1 , x , y);
            if (ret == true)
                return true;
            traced[x][y] = 0;
        }        


        y = yy;
        x = xx-1;
        if (x >= 0 && traced[x][y] == 0 && c == board[x][y])
        {
            traced[x][y] = 1;
            bool ret = trace( board, traced, word, offset+1 , x , y);
            if (ret == true)
                return true;
            // bug, 0 --> 1
            traced[x][y] = 0;
        }        

        x = xx+1;
        if (x < traced.size() && traced[x][y] == 0&& c == board[x][y] )
        {
            traced[x][y] = 1;
            bool ret = trace( board, traced, word, offset+1 , x , y);
            if (ret == true)
                return true;
            traced[x][y] = 0;
        }        

        return false;           
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
        if (row == 0 )
            return false;
        int col = board[0].size();
        
        if (col == 0)
            return false;
        
        // bug, miss this logic item
        if ( col * row < word.length() )
            return false;
        
        vector< vector<int > >  traced =  vector<vector<int> > (row, vector<int>(col, 0));
        
        char c = word[0];
        
        for( int x=0; x<board.size(); x++ )
        {
            for(int y=0; y<board[0].size(); y++)
            {
                if( (board[x][y] == c)  )
                {
                    traced[x][y] = 1;
                    
                    bool ret = trace( board, traced, word, 1 , x, y);
                    
                    if (ret == true)
                        return true;
                        
                    traced[x][y] = 0;
                }
            }
        }
        return false;

    }
};
