public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        var nums3 = new int[n + m];

        if (n > 0)
        {
            var tt = nums2.Take(n).ToArray();
            tt.CopyTo(nums3, 0);
        }
//u
        if (m > 0)
        {
            var pp = nums1.Take(m).ToArray();
            pp.CopyTo(nums3, n );

        }
        Array.Sort(nums3);
        nums3.CopyTo(nums1, 0);
    }
}