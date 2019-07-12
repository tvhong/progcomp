from sys import stdin
import operator

MAX_SENTINEL = -1
MIN_SENTINEL = 100
ANSWER_STRING = "Class Room#{} contains atleast {} and atmost {} liars"
PARADOX_STRING = "Class Room#{} is paradoxical"

def solve():
    T = int(stdin.readline())
    for classroom in range(1, T+1):
        n = int(stdin.readline())
        val = [0] * n
        liars_count = [0] * n
        for i in range(n):
            line = stdin.readline()
            for j in range(n):
                val[i] |= (1 << j) if line[j] == 'T' else 0
                liars_count[i] += 1 if line[j] == 'L' else 0

        # print(val, liars_count)
        res_min = MIN_SENTINEL
        res_max = MAX_SENTINEL
        for i in range(n):
            # assuming ith is telling a truth-speaker
            if val[i] & (1 << i) == 0: continue
            if not has_contradiction(n, val, val[i]):
                res_min = min(res_min, liars_count[i])
                res_max = max(res_max, liars_count[i])

        if not has_contradiction(n, val, 0):
            res_min = min(res_min, n)
            res_max = max(res_max, n)

        if res_min != MIN_SENTINEL:
            print(ANSWER_STRING.format(classroom, res_min, res_max))
        else:
            print(PARADOX_STRING.format(classroom))

def has_contradiction(n, val, assumed_state):
    result = False
    for j in range(n):
        if assumed_state & (1 << j):
            # j is truth-speaker, according to assumed_state
            contradict_fn = operator.ne
        else:
            contradict_fn = operator.eq

        if contradict_fn(assumed_state, val[j]):
            result = True
            break

    return result
solve()
