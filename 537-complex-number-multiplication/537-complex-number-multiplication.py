class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a=""
        b=""
        c=""
        d=""
        i = 0
        while(num1[i] != "+"):
            a = a + num1[i]
            i += 1
        i+=1
        while(num1[i] != "i"):
            b = b + num1[i]
            i += 1
            
        j = 0 
        while(num2[j] != "+"):
            c = c + num2[j]
            j += 1
        j+=1
        while(num2[j] != "i"):
            d = d + num2[j]
            j += 1
        
        p = int(a)*int(c) - int(b)*int(d)
        q = int(b)*int(c) + int(a)*int(d)
        print(int(a),int(b))
        print(int(c),int(d))
        print(p,q)
        
        return str(p)+"+"+str(q)+"i"
        