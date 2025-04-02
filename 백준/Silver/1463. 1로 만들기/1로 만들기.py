n = int(input())
l=[100000000]*(n+1)
l[1] =0
for i in range(1,n+1):
  if i+1<=n:
    l[i+1]= min(l[i+1],l[i]+1)
  if i*2<=n:
    l[i*2] =min(l[i*2],l[i]+1) 
  if i*3<=n:
    l[i*3] =min(l[i*3],l[i]+1) 
print(l[n])