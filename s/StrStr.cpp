class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // should negoticate
        if (haystack ==NULL && needle == NULL)
            return haystack;
        
        if (haystack == NULL || needle == NULL)
            return NULL;
        
        int lenh = strlen(haystack);
        int lenn = strlen(needle);
        
        // bug, len == 0
        if (lenh < lenn ) // len == 0
            return NULL;
        
        //           bug here, miss =
        for(int i=0; i<=lenh-lenn; i++)
        {
            int j = 0;
            for(j=0; j<lenn; j++)
            {
                if (*(haystack + i+j) != *(needle + j) )
                    break;
            }
            if (j == lenn)
                return haystack + i;
        }
        return NULL;
    }
};
