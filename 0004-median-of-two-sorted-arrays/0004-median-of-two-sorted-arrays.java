class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[] a = new int[n + m];

        int i = 0, j = 0, k = 0;

        while (i < n && j < m)
            a[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

        while (i < n) a[k++] = nums1[i++];
        while (j < m) a[k++] = nums2[j++];

        if (k % 2 == 1)
            return a[k / 2];

        return ((double)a[k / 2 - 1] + a[k / 2]) / 2;
    }
}