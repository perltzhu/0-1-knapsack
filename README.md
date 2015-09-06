# 0-1knapsack

0-1 knapsack problem solution

##Description##

回溯法求解0-1背包问题

##Input##

第一行：n c（物品个数，背包容量） 第二行：w1 w2 ... wn (n个物品的重量) 第三行：p1 p2 ... pn (n个物品的价值)

##Output##

最优值：bestp 最优解：n维0-1向量（用空格隔开）注意，这里物品的次序是输入序列的，不是按单位价值排序之后的次序。

##Sample Input##
4 7 3 5 2 1 9 10 7 4

##Sample Output##

最优值：20 最优解：1 0 1 1 