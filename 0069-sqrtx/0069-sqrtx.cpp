class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        
        long first = 1, last = x;
        while (first <= last) {
            long mid = first + (last - first) / 2;
          
            if (mid*mid == x)
                return mid;
            else if (mid*mid > x ) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        
        
        //return last as loop breaks when start>end and we need to submit rounded down nearest integer
        //if rounded up return first
        
        int ans = last;
        return ans;
    }
};