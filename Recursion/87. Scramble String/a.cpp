class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2)    return true;

        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end())    return mp[key]; 

        int n = s1.size();
        for(int i = 1; i < n; ++i){
            // Without swap
            // gr|eat rg|eat
            // Left part of s1 and s2
            // Right part of s1 and s2
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) &&
               isScramble(s1.substr(i, n-i), s2.substr(i, n-i))){
                return true;
            }

            //ex of withswap: gr|eat  rge|at
			      //here we compare "gr" with "at" and "eat" with "rge"
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) &&
               isScramble(s1.substr(i, n-i), s2.substr(0, n-i))){
                return true;
            }
        }
        return mp[key] = false;
    }
};