class Solution {
public:
    bool binary_search(vector<int>& nums,int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        unordered_set<int> result;
        for(int &target: nums2) {
            if(binary_search(nums1,target)) {
                result.insert(target);
            }
        }
        return vector<int> (result.begin(),result.end());
    }
};