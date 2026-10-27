class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int left = 0, right = 0;
        int maxCount = 0;
        while(right < s.size()){
            while(seen.contains(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxCount = std::max(maxCount, right-left+1);
            right++;
        }
        return maxCount;
    }
};
