from fractions import Fraction

i = Fraction(1, 1)
n = 4

def iterate(i):
	numerator = 120 * (1 + i) ** 6 - 10 * (1 + i) ** 5 - 20 * (1 + i) ** 4 - 30 * (1 + i) ** 3 - 40 * (1 + i) ** 2 - 50 * (1 + i) ** 1
	denominator = 10 * (1 + i) ** 4 + 40 * (1 + i) ** 3 + 90 * (1 + i) ** 2 + 160 * (1 + i) + 250

	return i - numerator / denominator

for m in range(0, n):
	i = iterate(i)

print((i.numerator + i.denominator) % (10 ** 9 + 7)) # 498095931

print(i.numerator / i.denominator)
