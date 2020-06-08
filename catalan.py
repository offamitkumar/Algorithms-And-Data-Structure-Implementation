factorial= [1]
for i in range(1,10100):
    factorial.append(factorial[i-1] * i)

n = 5000 # nth catalan number 
print ( factorial[2*n] // (factorial[n+1] * factorial[n]))
