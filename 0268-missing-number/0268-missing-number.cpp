class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> mp;
        int missingNumber = -1;
        for(int i = 0; i < nums.size(); i++) mp[i] = 0;
        for(int num: nums) mp[num]++;
        for(auto [key,val]: mp) {
            if(val == 0) missingNumber = key;
        }

        if(missingNumber == -1) {
            return nums.size();
        }
        return missingNumber;
    }
};