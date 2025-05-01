class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=(int)nums1.size(), m=(int)nums2.size();
        if(n>m*6 || n*6<m) return -1;

        int sm1=0;
        vector<int> cnt1(7,0);
        for(const int& num : nums1){
            sm1 += num;
            cnt1[num]++;
        }
        int sm2=0;
        vector<int> cnt2(7,0);
        for(const int& num : nums2){
            sm2 += num;
            cnt2[num]++;
        }

        if(sm1==sm2) return 0;

        if(sm1>sm2){
            cnt1.swap(cnt2);
            swap(sm1, sm2);
            swap(n, m);
        }
        // nums1 if now for sure the array w smaller sum
        // therefore to make the biggest jumps swap 1 -> 6 in nums1, and 6 -> 1 in nums2

        int diff = sm2-sm1;
        int i=1, j=6;
        int ans=0;
        while(diff>0){
            if(i<=6 && 6-i>=j-1 && cnt1[i]){
                diff -= (6-i);
                ans++;
                if(--cnt1[i]==0){
                    i++;
                }
            }
            else if (i<=6 && !cnt1[i]){
                i++;
            }

            if(diff<=0) break;

            if(j>=1 && j-1>=6-i && cnt2[j]){
                diff -= (j-1);
                ans++;
                if(--cnt2[j]==0){
                    j--;
                }
            }
            else if(j>=1 && !cnt2[j]){
                j--;
            }
        }
        return ans;
    }
};

// if possible we can just greedily change the elements that would make the biggest difference, i.e. 6 -> 1 in array with larger sum or 1 -> 6 in array with smaller sum to acheive equal sums in min operations
// to do this we just need the sum of each array and the cnt of each element in each array

// O(n) time -> to get sums + cnts, then for changing numbers we flip each number ONCE at most, therefore keeping complexity at O(n)
// O(1) space -> cnt arrays are constant in space as we always have exactly 6 indexes regardless of input array sizes

// can swap entire vectors with vector.swap(vector2);