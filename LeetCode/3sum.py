# please use index so that no thing are used more than once...
# sometime you make this mistake.....
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        new_nums=[]
        from collections import defaultdict
        cnt=defaultdict(int)
        # gou!!!! full zero you hua !!!! = = 
        for v in nums:
            cnt[v]+=1
            if cnt[v]<=3:
                new_nums.append(v)
        nums=new_nums
        ans=set()
        idx={i:j for j,i in enumerate(nums)}
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                k=idx.get(-nums[i]-nums[j],-1)
                if k>j:
                    ans.add(tuple(sorted([nums[i],nums[j],nums[k]])))
        return map(list,ans)
                
        
