class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        size_t l = 0;
        for(size_t r=k; r<arr.size(); ++r) {
            if(abs(x-arr[r]) < abs(x-arr[r-k])) {
                l=r-k+1;
            }
        }
        return vector<int>{arr.begin()+l, arr.begin()+l+k};
    }
};

// window expand to k
// move r to right iff abs(x-arr[r+1]) < abs(x-arr[l])

// pay close attention to inputs
// i.e. for this input is sorted so we can simply go across in O(n)
// OR we can binary search in O(logn) then expand window in O(k)
// if input were NOT sorted we would have to use a heap to maintain k closest elements resulting in O(nlogk + nlogn)