# TODO
from cs50 import get_float

while True:
    b = get_float("Change owed: ")
    if b > 0:
        break
    else:
        continue

total = round(b * 100)

mony = 0

while total > 0:
    if total >= 25:
        total -= 25
    elif total >= 10:
        total -= 10
    elif total >= 5:
        total -= 5
    else:
        total -= 1
    mony += 1
print(mony)
