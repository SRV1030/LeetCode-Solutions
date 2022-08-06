class Solution:
    def poorPigs(self, b, y, x):
        T = x//y
        x = 0
        while (T+1)**x < b:
            x += 1
        return x