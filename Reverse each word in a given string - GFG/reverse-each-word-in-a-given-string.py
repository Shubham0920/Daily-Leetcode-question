#User function Template for python3

class Solution:
    
    def reverse(self,s):
        str = ""
        for i in s:
            str = i + str
        return str
        
    def reverseWords(self, s):
        # code here
        lis = list(s.split('.'))
        ans = "";
        for i in lis:
            # print(str(reversed(i)))
            ans = ans + self.reverse(i) + "."
        return ans [:-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseWords(s)
        print(ans)
# } Driver Code Ends