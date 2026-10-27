class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);

        for(int i = 0; i < s1.size(); i++){
            s1_freq[s1[i]-'a']++;
            s2_freq[s2[i]-'a']++;
        }

        for(int i = s1.size(); i < s2.size(); i++){
            if(s1_freq == s2_freq) return true;

            s2_freq[s2[i]-'a']++;
            s2_freq[s2[i-s1.size()]-'a']--;
        }

        return s1_freq == s2_freq;
    }   
};
