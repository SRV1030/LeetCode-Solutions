class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        
        last = start + 2 * (n-1)

        if start % 4 <= 1:
            if n % 4 == 1: 
                return last
            elif n % 4 == 2: 
                return 2
            elif n % 4 == 3: 
                return 2 ^ last
            else: 
                return 0

        else:
            if n % 4 == 1: 
                return start
            elif n % 4 == 2: 
                return start ^ last
            elif n % 4 == 3: 
                return start ^ 2
            else: 
                return start ^ 2 ^ last

            
# https://leetcode.com/problems/xor-operation-in-an-array/discuss/699141/Visual-Solution-Python-or-O(1)-Time-or-O(1)-Space