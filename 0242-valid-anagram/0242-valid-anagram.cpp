class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

    unordered_map <int, int> mpp;

    for (int i = 0; i<s.length(); i++){
        mpp[s[i] - 'a']++;
        mpp[t[i] - 'a']--;
    }

    for(int i =0; i<mpp.size(); i++){
        if(mpp[i] != 0){
            return false;
        }
    }
    return true;
    }
};