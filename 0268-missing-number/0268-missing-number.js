/**
 * @param {number[]} nums
 * @return {number}
 */

 function binarySearch(arr) {
    let left = 0,right = arr.length-1;
    while(left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        if(arr[mid] > mid) right = mid-1;
        else left = mid+1;
    }
    return left;
 }
var missingNumber = function(nums) {
    nums.sort((a,b) => a-b);
    return binarySearch(nums);
};