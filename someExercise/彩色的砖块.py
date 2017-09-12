import sys

line = sys.stdin.readline().strip()

def get_s(s):
    len_s = len(list(set(s)))
    if len_s > 2:
        return 0
    else:
        return len_s

print get_s(line)

'''
a = raw_input("")
new = []
for i in range (len(a)):
    new.append(a[i])
if len(set(new)) == 2:
    print 2
elif len(set(new)) == 1:
    print 1
else:
    print 0
'''
