perm_n = int(input())
permissions = []
for i in range(perm_n):
    inp = input().split(" ")
    p = int(inp[1], 16)
    permissions.append([inp[0], p])

existing, wanted = map(lambda x: int(x, 16), input().split(" "))
to_add = (wanted ^ existing) & ~existing
res = ""
for perm in permissions:
    if perm[1] & to_add == perm[1]:
        res += (perm[0] + " ")
print(res if len(res) > 0 else "All Good!")
