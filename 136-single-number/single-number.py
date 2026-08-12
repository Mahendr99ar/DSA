class Solution:
    def singleNumber(self, nums):
        index = 0
        for num in nums:
            index ^= num
        return index