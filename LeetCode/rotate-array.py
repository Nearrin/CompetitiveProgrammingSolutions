class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # notes: this is my first thought (I used it several years ago in a interview...)
        # there is actually a better way... reverse the whole array and then reverse two part....
        def gcd(a,b):
            return gcd(b,a%b)if b else a
        n=len(nums)
        ring_size=n//gcd(k,n)
        num_rings=n//ring_size
        for i in range(num_rings):
            head=nums[i]
            p=i
            while (p-k+n)%n!=i:
                nums[p]=nums[(p-k+n)%n]
                p=(p-k+n)%n
            nums[p]=head
