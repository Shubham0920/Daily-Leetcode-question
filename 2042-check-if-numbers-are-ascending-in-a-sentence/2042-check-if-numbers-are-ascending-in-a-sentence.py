class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        string = s.split(" ")
        lis = []
        for i in string:
            if i.isnumeric():
                lis.append(int(i))
                
        for i in range(len(lis)-1):
            print(lis[i+1])
            if(lis[i]>=lis[i+1]):
                return False
            
        return True