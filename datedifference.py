# given two dates find difference of days b/w two dates

from datetime import date, time, timedelta

d1, m1, y1 = list(map(int, input().strip().split()))
d2, m2, y2 = list(map(int, input().strip().split()))

a = date(y1, m1, d1)
b = date(y2, m2, d2)

# c = timedelta(11, 10, 10)
# d = timedelta(10, 10, 10)

# t = c - d
# print(t)

ans = abs(a - b)
print(ans)
