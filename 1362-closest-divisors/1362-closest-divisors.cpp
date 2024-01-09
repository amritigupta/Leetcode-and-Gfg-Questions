class Solution {
public:
    vector<int> solve(int n){
        int last = 1;
        for(int i = 1;i<=sqrt(n);i++){
            if(n%i == 0)last = i;
        }
        return {last, n/last, abs(n/last - last)};
    }
    vector<int> closestDivisors(int num) {
        vector<int> t1 = solve(num+1);
        vector<int> t2 = solve(num+2);
        if(t2[2]<t1[2])swap(t1, t2);
        t1.pop_back();
        return t1;
    }
};