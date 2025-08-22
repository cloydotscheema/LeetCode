class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int half = (m + n + 1) / 2;

        while (left <= right) {
            int i = (left + right) / 2; 
            int j = half - i;           
            int Aleft  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int Aright = (i < m) ? nums1[i] : INT_MAX;
            int Bleft  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int Bright = (j < n) ? nums2[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};
