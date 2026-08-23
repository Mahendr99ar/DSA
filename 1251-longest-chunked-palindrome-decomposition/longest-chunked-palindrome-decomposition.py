class Solution:
    def longestDecomposition(self, text: str, ptr = 1) -> int:

        n = len(text)

        if n < 2: return n

        while ptr <= n - 1:

            if text.endswith(text[:ptr]):
                return 2 + self.longestDecomposition(text[ptr:-ptr])

            ptr+= 1 

        return 1     