# TODO
import string
from cs50 import get_string

input = get_string("Text : ")
letter = 0
for r in input:
    if r.isalpha() == True:
        letter += 1

word = len(input.split())

sentenc = 0

for g in input:
    if g == "." or g == "?" or g == "!":
        sentenc += 1

wordsent = word / 100
L = letter / wordsent
S = sentenc / wordsent

gamm = round(0.0588 * L - 0.296 * S - 15.8)

if gamm < 1:
    print("Before Grade 1")
elif gamm >= 16:
    print("Grade 16+")
else:
    print(f"Grade {gamm}")
