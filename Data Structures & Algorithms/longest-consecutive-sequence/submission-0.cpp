class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for(int x: nums){
            if(!seen.contains(x)){
                seen.insert(x);
            }
        }

        int count = 0 ;
        for(int num: seen){
            if(seen.contains(num-1)) continue;
            int len = 1;
            while(seen.contains(num+len)){
                len++;
            }
            count = std::max(count, len);
        }
        return count;
    }
};
