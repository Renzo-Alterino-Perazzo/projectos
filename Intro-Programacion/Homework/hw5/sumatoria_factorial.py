l = []
m = 1
s = 0
for i in range(1, 5):
    l.append(i)

for i in l:
    m = m * i
    s += i

print(m)
print(s)
