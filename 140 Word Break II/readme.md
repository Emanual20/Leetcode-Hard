与之相关的是题目139 Word Break

先判断能不能，再判断路径。

判断能不能比较容易线性dp，每次枚举分割点，再检查分割点后的单词是否在单词集里，是O(n^2 logM)的。

判断路径直接模拟dp过程即可。