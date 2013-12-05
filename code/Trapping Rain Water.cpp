class Solution {
public:
    int trap(int A[], int n) {
        if (n==0)   return 0;
        int maxh=A[0],maxid = 0;
        int res = 0;
        for (int i=1;i<n;++i)
            if (A[i] > maxh){maxh = A[i];maxid = i;}
        int i=0;
        int curH = -1;
        while(i<maxid)
        {
            if (curH==-1 || A[i]>=curH)
            {
                curH = A[i];
                ++i;
            }
            else if(A[i]<curH)
            {
                res += curH - A[i];
                ++i;
            }
        }
        i = n-1; curH = -1;
        while(i>maxid)
        {
            if (curH==-1 || A[i]>=curH)
            {
                curH = A[i];
                --i;
            }
            else if(A[i]<curH)
            {
                res += curH - A[i];
                --i;
            }
        }
        return res;
    }
};