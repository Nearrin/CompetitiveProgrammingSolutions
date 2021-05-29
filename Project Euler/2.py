f = [1, 1]
while True:
    t = f[-2]+f[-1]
    if t <= 4000000:
        f.append(t)
    else:
        break
print(sum(v for v in f if v % 2 == 0))
