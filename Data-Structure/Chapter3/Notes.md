# Chapter3 树（上）

### 3.1 树与树的表示

分层次组织在管理上具有更高效率。

------

**查找**

- 静态查找： 集合中记录是固定的 （无删除，插入操作）
  - 数组：顺序查找 （设置一个‘哨兵’）
  - 二分查找（Binary Search) (O(logN))
    - 假设n个数据元素的关键字满足有序，并且是连续存放（数组），可以进行二分查找

```c
int BinarySearch (List Tbl, ElementType K) {
  int left, right,NotFound=-1;
  left = 1;
  right = Tbl->length;
  while (left <= right) {
    mid = (left + right) / 2;
    if (K < mid) {
      right = mid - 1;
    } else if (K > mid) {
      left = mid + 1;
    } else {
      return mid
    }
  }
  return NotFound;
}
```

​		**！！！left and right can not be mid instead of mid + 1 or mid - 1 ** 因为会陷入死循环， 如果left为1， right为2。

- 动态查找：集合中记录是动态变化的 （存在删除，插入操作）

------

**树**：n（n >= 0）个结点构成的有限集合

​	当n=0时，称为空树

​	对于任一颗非空树，它具备以下性质：

​		树中有一个称为“根(root)”的特殊结点，用r表示

​		其余结点可分为m(m>0)个互不相交的有限集T1,T2,...,Tm，其中每个集合本身又是一棵树，称为原来树的‘子树’

​		子树是**不相交**的

​		除了根结点外，每个结点有且只有一个父结点

​		一棵N个结点的树有N-1条边

------

**树的表示**（儿子-兄弟表示法）

![](/Users/vera/Desktop/Screen Shot 2022-04-08 at 10.14.10 AM.png)

### 3.2 二叉树及存储结构



### 3.3 二叉树的遍历

