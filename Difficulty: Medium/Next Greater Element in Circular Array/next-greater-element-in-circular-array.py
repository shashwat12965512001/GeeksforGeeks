class Solution:
    def nextGreater(self, arr):
        n = len(arr)
        res = [-1] * n
        stack = []  # store indices
        
        # Traverse twice to simulate circular array
        for i in range(2 * n):
            while stack and arr[stack[-1]] < arr[i % n]:
                res[stack.pop()] = arr[i % n]
            if i < n:  # Only push indices of first pass
                stack.append(i)
        
        return res