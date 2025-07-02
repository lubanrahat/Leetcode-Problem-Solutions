/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */

function binarySearch(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        if (nums[mid] === target) return true;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

var intersection = function(nums1, nums2) {
    nums1.sort((a, b) => a - b);
    const resultSet = new Set();
    for (const target of nums2) {
        if (binarySearch(nums1, target)) {
            resultSet.add(target);
        }
    }
    return Array.from(resultSet);
};
