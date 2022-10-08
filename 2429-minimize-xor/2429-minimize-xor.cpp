class Solution {
public:
    int c(int n)
    {   int cnt=0;
        
        while(n)
        {
            n&=n-1;
            cnt++;
        }
     
     return cnt;
    }
    int minimizeXor(int num1, int num2) {
       int a = c(num1), b = c(num2), ans =0;
        
        if(a==b) return num1;
        
        else if(b>a)
        {
            int f = b-a;
            for(int i=0; i<32; i++)
            {
                if(!((1<<i)&num1))
                {
                    num1|=(1<<i);
                    f--;
                }
                if(f==0) return num1;
            }
        }
        
        else
        {
            int f = a-b;
            for(int i=0; i<32; i++)
            {
                if((1<<i)&num1)
                {
                    ans|=(1<<i);
                    f--;
                }
                if(f==0) return num1^ans;
            }
        }
        
        return ans;
        
        
    }
};
