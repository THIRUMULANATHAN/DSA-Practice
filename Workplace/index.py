n = 3
s = set()
l = list()

for i in range (1, n+1):
    if n%i == 1:
        s.add(i)
        l.append(i)

for i in l:
    for index in range(1, i+1):
        if i%index == 1:
            s.add(index)
            l.append(index)

s.add(n)
print(*s)
print("Ans: ", len(s))
l.append(n)
print(*l)