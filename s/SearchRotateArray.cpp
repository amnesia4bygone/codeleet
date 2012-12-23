class Solution {
    public:

        int is_order(int A[], int n)
        {
            if (n==1)
                return 0;

            if( A[0] < A[n-1])
                return 1;
            else
                return 0;
        }

        int search(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            if (n==1)
            {
                if (target == A[0])
                    return 0;
                else
                    return -1;
            }

            if (n==2)
            {
                if (target == A[0])
                    return 0;
                if (target == A[1])
                    return 1;
                return -1;
            }


            int y = A[ (n-1)/2];
            if (y == target)
            {
                return (n-1)/2;
            }

            int x;
            int z;


            if (is_order(A, (n+1)/2 )  ) // second part disorder
            {
                if (y<target)
                {


                    z = search(A+(n+1)/2, (n)/2, target);
                    if (z != -1)
                        return z + (n+1)/2;  
                }
                else
                {

                    x = search(A, (n-1)/2, target);
                    if (x != -1)        
                        return x;  

                    z = search(A+(n+1)/2, (n)/2, target);
                    if (z != -1)
                        return z + (n+1)/2;                
                }
            }
            else
            {
                if (y > target)
                {
                    x = search(A, (n-1)/2, target);
                    if (x != -1)        
                        return x;    
                }    
                else
                {
                    x = search(A, (n-1)/2, target);
                    if (x != -1)        
                        return x;    

                    z = search(A+(n+1)/2, (n)/2, target);
                    if (z != -1)
                        return z + (n+1)/2;                

                }

            }




            return -1;


        }
};
