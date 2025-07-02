class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> count;
        int answer = 0;
        for(int num: nums) count[num]++;
        for(auto [key,val]: count) {
            if(val == 1) answer = key;
        }
        return answer;
    }
};