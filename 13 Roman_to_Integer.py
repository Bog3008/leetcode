class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        answ = 0
        num = {'I': 1,'V': 5,'X': 10,'L': 50,'C': 100,'D': 500,'M': 1000}
        val = list()
        for i in range(len(s)):
            val.append(num[s[i]])
        for i in range(len(val) - 1):
            if val[i] < val[i + 1]:
                answ -= val[i]
            else:
                answ += val[i]
        answ += val[len(val) - 1]
        return answ
        
