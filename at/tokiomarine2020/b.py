a,v = map(lambda x: int(x), input().split())
b,w = map(lambda x: int(x), input().split())
t = int(input())
if a == b or abs(a-b) <= (v-w)*t: print("YES")
else: print("NO")