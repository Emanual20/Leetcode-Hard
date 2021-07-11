代码量哪怕放在区域赛里也是比较大的一个题。

首先把所有单词暴力抽象成节点，如果两个单词之间只差一个字母就给这两个节点之间加一条边。

这里有一些剪枝：

1. 一开始想的是每个节点保存路径，在路径上出现过的点就不要往回走了，这样剪枝避免重复遍历。

2. 后来发现可能这样空间代价比较大，时间上也需要一个抽象化的过程，即我们在bfs时，如果已经遍历到第i层，第i-1层之前的节点就不需要再计入考虑了，这是非常重要的一个剪枝。

再其次难点就是代码实现了，小心bebug。