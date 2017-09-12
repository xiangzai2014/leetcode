#-*- coding: UTF-8 -*-
'''
给定一个已经降序排好序的正数数组, 要求按[最小、最大、次小、次大...], 的顺序重新排序。期望的时间复杂度为O(n)，空间复杂度为O(1)，即不能申请额外的数组。
例如：输入[7,6,5,4,3,2,1]，输出[1,7,2,6,3,5,4]。
'''
a = [7,6,5,4,3,2,1]
n = 7
org_max = max(a)
shift = max(a) - min(a) + 1 #
print(shift)
for s in range(n):
    if a[s] > org_max:  # this element is already moved
       s += 1
       continue

    i = s
    tmp = a[i]
    j = 0
    while True:
        if i < 2/n: j = 2 * i + 1
        else: j = 2 * (n - 1 - i)

        a[j], tmp = tmp, a[j]
        a[j] += shift  # mark as 'moved'
        if j == s:
             break
        i = j
    s += 1

for s in range(n):
    if a[s] > org_max:
        a[s] -= shift
    print(a[s])
