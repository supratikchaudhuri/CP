n = int(input())
nums = list(input().split())
res = 0
digits = "123457"
for num in nums:
    if not any((d in digits) for d in num):
        if len(num) > 1 and num[-1] == '0':
            continue
        res += 1
print(res)
