s = sorted(list(map(int, input().split())))
assert sum(s[:3]) == 2 * s[3]
b = s[0] - s[1] + s[2]
assert b % 2 == 0
b //= 2
a = s[0] - b
c = s[2] - b
print('{} {} {}'.format(a, b, c))
