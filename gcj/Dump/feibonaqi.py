a=int(raw_input("How many numbers do you wish to generate?(input must be greater than 2)"))
b=[1,1]
for i in range(2,a):
  b.append(int(b[i-2]+b[i-1]))
print b
