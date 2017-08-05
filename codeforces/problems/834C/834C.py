import bisect
cubes = []
def setup():
    for i in range (1, 1000000 + 1):
        cubes.append(i**3)

def is_perfect_cube(x):
    pos = bisect.bisect_left(cubes, x)
    if pos < 1000000:
        if cubes[pos] == x:
            return (True, pos + 1)
            
    return (False, -1)

def game_legit(a, b):
    prod = a * b

    (prod_is_cube, root) = is_perfect_cube(prod)
    if prod_is_cube:
        if a % root == 0 and b % root == 0:
            return True

    return False

setup()
n = int(input())
for i in range(0, n):
    a, b = [int(x) for x in input().split(' ')]
    if game_legit(a, b):
        print("Yes")
    else:
        print("No")


