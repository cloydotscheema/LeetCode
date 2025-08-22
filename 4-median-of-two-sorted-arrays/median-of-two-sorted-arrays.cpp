class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int medianIndex1 = (total - 1) / 2;
        int medianIndex2 = total / 2;

        int i = 0, j = 0, count = 0;
        int curr = 0, prev = 0;

        while (count <= medianIndex2) {
            prev = curr;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
            count++;
        }

        if (total % 2 == 1) return curr;                  
        return (prev + curr) / 2.0;                     
    }
};
