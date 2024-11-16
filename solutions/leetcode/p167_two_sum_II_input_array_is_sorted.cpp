class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;

        while(l<r){
            int curr_sum = numbers[l]+numbers[r];
            if(curr_sum<target) l++;
            else if(curr_sum>target) r--;
            else return {l+1,r+1};
        }
        return{-1,-1};
    }
};

// Since input is sorted we can solve twosum with O(1) memory by utilizing two pointers and moving in depending if we > or < target
// On normal twosum we can do the same approach to achieve O(1) memory but we would need to sort the vector first therefore giving O(nlogn) time instead of O(n) time from hashmap soln