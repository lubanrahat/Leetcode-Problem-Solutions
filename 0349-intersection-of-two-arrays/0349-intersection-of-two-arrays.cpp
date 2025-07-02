class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count1,count2;
        for(auto it: nums1) count1[it]++;
        for(auto it: nums2) count2[it]++;
        vector<int> answer;
        for(auto [key,val]: count1) {
            if(count1[key] && count2[key]) answer.push_back(key);
        }
        return answer;
    }
};