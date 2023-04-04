class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int L = 0, R = p.size()-1, cnt = 0;
        while(L <= R){
            if(L != R){
                if(p[L] + p[R] <= limit){
                    R--;
                    L++;
                    cnt++;
                }else{
                    R--;
                    cnt++;
                }
            }else{
                cnt++;
                L++;
            }
        }
        return cnt;
    }
};