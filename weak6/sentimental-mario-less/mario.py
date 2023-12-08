# TODO
from cs50 import get_int

while True:
    b = get_int("Height:")
    if b >= 1 and b <= 8:
        break
    else:
        continue
for c in range(b):
    print(" " * (b - (c + 1)), end="")
    print("#" * (c + 1))
