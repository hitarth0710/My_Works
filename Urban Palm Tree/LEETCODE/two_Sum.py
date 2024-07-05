#METHOD 1 using lists 

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = []

        for i in range(len(nums)):
            for j in range(i + 1,len(nums)):
                if nums[i] + nums[j] == target:
                   l.append(i)
                   l.append(j)   
        return l
    
l = [3,2,4] 
r = Solution()
l2 = r.twoSum(l,6)
print(l2)

#METHOD 2 using dictionary(more optimal method)

class Solution(object):
	def twoSum(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		index_map = {}  # To store the indices of the elements

		for i, value in enumerate(nums):
			complement = target - value
			if complement in index_map:
				return [index_map[complement], i]
			index_map[value] = i
		
		return []

# Example usage
l = [3, 2, 4]
r = Solution()
l2 = r.twoSum(l, 6)
print(l2)  # Output: [0, 2]
