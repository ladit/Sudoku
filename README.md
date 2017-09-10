# 概述

使用深度优先搜索和回溯法批量生成数独棋盘，C++ 编写。

# 参考

算法实现：
  - [[Java] 数独生成和求解](https://segmentfault.com/a/1190000004641936)（使用深度优先搜索和回溯法填写数独）
  - [数独终盘生成的几种方法](https://my.oschina.net/wangmengjun/blog/781984)（矩阵转换法和随机法）
  - [数独 -- 一个高效率生成数独的算法](http://blog.csdn.net/peng_wu01/article/details/6026103)（另一种随机法，评论中说规律性强）

程序优化：
  - [vector 使用的简单优化技巧](https://yanyiwu.com/work/2014/05/25/vector-pushback-youhua.html)（弃用vector，直接使用更高效率的数组）
  - 文件读写效率提升（似乎以下文章都一致认为 C 标准的函数效率更高，但这些文章都较为老旧，不知道是否都使用 VS，有使用的版本又较低，新的 VS 使用 MSBuild 作为编译器，不知道 C++ 标准的函数效率是否有改进，为了统一风格，暂时先使用 C++ 标准的 ofstream）
    - [C/C++ 文件操作效率比较——FILE/fstream](http://blog.csdn.net/shudaxia123/article/details/50491451)
    - [fstream 与 C 风格（例如 fread 和 fwrite ）两种读写文件方法的效率比较](http://blog.csdn.net/kevin_ut/article/details/6088489)
    - [探寻 C++ 最快的读取文件的方案](https://www.byvoid.com/zhs/blog/fast-readfile)
    - [File I/O 效率 C vs C++ (一)](http://dantvt.is-programmer.com/posts/12701.html)

待使用更高效的 DLX 算法：
  - [【算法】Dancing Links (DLX) I](http://blog.csdn.net/keyboardlabourer/article/details/13015689)
  - [【算法】Dancing Links (DLX) II](http://blog.csdn.net/keyboardlabourer/article/details/13168391)
  - [DLX 算法介绍](http://blog.csdn.net/keyboardlabourer/article/details/13015689)
  - [Sudoku DLX 算法求解](http://blog.csdn.net/keyboardlabourer/article/details/13015689)
  - [用 DLX 解 sudoku(数独)](http://blog.gssxgss.me/use-dlx-to-solve-sudoku-1/)
  - [数独 Sudoku DLX 算法](https://www.oschina.net/code/snippet_1159061_22803)