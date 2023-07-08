class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s= 0,e=n-1;
        char ans=letters[0];
        
        while(s<=e)
        {
            int mid = s +  (e-s)/2;
            int num = letters[mid] -'a'; // storing int val of mid element
            
            if(num > (target - 'a'))  //comparing int of mid and given target
            {
                ans = letters[mid];  //possible answer
                e = mid-1;  //searching left side of mid
            }
            else s=mid+1;
        }
        return ans;
    }

};