’‘’
首先理解题目意思，“第i个棋子放在第x[i]行y[i]列”这句话的意思不是棋子都是对角放置，因为i只是指的下标，所以棋子可以任意放置。
要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数，我们需要知道堆棋子的格子坐标，例如我们总共有4个棋子，如果要让一个格子存在2个棋子，
我们就要知道哪个格子是放置2个棋子的。同理，哪个格子堆三个棋子，操作最少。
寻找堆棋子的格子坐标，我们可以采用简单粗暴的做法（循环遍历），遍历给定棋子x坐标的所有点和y坐标的所有点来找到“堆棋子”的格子。
这里有个假设（堆棋子的格子 x轴的坐标肯定在给定棋子之间，y轴坐标肯定在给定棋子之间，可证明。）
‘’‘
a = raw_input()
x = [int(i) for i in raw_input.split()]
y = [int(j) for j in raw_input.split()]
z = []

def calculateDistance(pointx_1, pointk_1, pointy_2, pointk_2):
    return abs(pointx_1-pointk_1)+abs(pointy_2-pointk_2)
ans = [6553000000]*100
for i in range(len(x)):
    for j in range(len(y)):
        lingshi = 0
        tmp = []
        for k in range(len(y)):
            tmp.append(calculateDistance(x[i], x[k], y[j], y[k]))
        tmp.sort()
        for k in range(len(y)):
            lingshi = lingshi + tmp[k]
            ans[k] = min(ans[k], lingshi)

for i in range(len(x)):
    z.append(str(ans[i]))

print ' '.join(z)
