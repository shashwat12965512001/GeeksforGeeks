class Solution:
    def minParentheses(self, s):
        open_needed = 0
        insertions = 0
        
        for ch in s:
            if ch == '(':
                open_needed += 1
            else:  # ch == ')'
                if open_needed > 0:
                    open_needed -= 1
                else:
                    insertions += 1
        
        return insertions + open_needed
        
        