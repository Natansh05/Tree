
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        ios_base::sync_with_stdio(0);
        unordered_map<char, int> firstIndex;
        int ans = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[s[i]] - 1);
            } else {
                firstIndex[s[i]] = i;
            }
        }
        return ans;
    }
};

