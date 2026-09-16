double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                       nums1, nums1Size);
    }

    int left = 0, right = nums1Size;
    int totalLeft = (nums1Size + nums2Size + 1) / 2;

    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = totalLeft - partition1;

        int left1 = (partition1 == 0)
                    ? -1000000000 : nums1[partition1 - 1];

        int right1 = (partition1 == nums1Size)
                     ? 1000000000 : nums1[partition1];

        int left2 = (partition2 == 0)
                    ? -1000000000 : nums2[partition2 - 1];

        int right2 = (partition2 == nums2Size)
                     ? 1000000000 : nums2[partition2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {

            // Odd total length
            if ((nums1Size + nums2Size) % 2 == 1) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            // Even total length
            int maxLeft = left1 > left2 ? left1 : left2;
            int minRight = right1 < right2 ? right1 : right2;

            return (maxLeft + minRight) / 2.0;
        }

        // Move partition in nums1
        if (left1 > right2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}