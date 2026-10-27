class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mapping;

        int target = 0;
        for(int x: skill){
            target += x;
            mapping[x]++;
        }
        target /= (skill.size()/2);

        long long chemistry = 0;
        for( int x: skill){
            if(mapping[x] == 0) continue;
            mapping[x]--;
            int y = target-x;
            if(mapping[y] == 0) return -1;
            mapping[y]--;
            chemistry += (long long)x*y;
        }
        return chemistry;
        
    }
};
