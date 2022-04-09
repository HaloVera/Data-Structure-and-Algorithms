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

**二叉树(Binary Tree)**: 一个有穷的结点集合

- 这个集合可以为空
- 若不为空，则它是由根结点和称为其左子树和右子树的两个不相交的二叉树组成

------

**特殊二叉树**

1. 斜二叉树(Skewed Binary Tree)<img src="/Users/vera/Desktop/Data-Structure-and-Algorithms/Data-Structure/Chapter3/Screen Shot 2022-04-09 at 10.02.00 AM.png" style="zoom:33%;" />
2. 完美二叉树(Perfect Binary Tree) / 满二叉树(Full Binary Tree)<img src="/Users/vera/Desktop/Data-Structure-and-Algorithms/Data-Structure/Chapter3/Screen Shot 2022-04-09 at 10.03.13 AM.png" style="zoom:33%;" />
3. 完全二叉树(Completed Binary Tree)<img src="/Users/vera/Desktop/Data-Structure-and-Algorithms/Data-Structure/Chapter3/Screen Shot 2022-04-09 at 10.03.49 AM.png" style="zoom:33%;" />

------

**二叉树几个重要性质**

- 一个二叉树第i层的最大结点数为：2^(i-1), i>=1.
- 深度为k的二叉树有最大结点总数为：2^k - 1, k >= 1.
- 对任何非空二叉树T，若n0表示叶结点的个数、n2是度为2的非叶结点个数，那么两者满足关系n0 = n2+1；

------

**二叉树的抽象数据类型定义**

**类型名称**：二叉树

**数据对象集**：一个有穷的结点集合

​						若不为空，则由根结点和其左右二叉子树组成

**操作集**：

```c
Boolean isEmpty(BinTree BT) // 判别BT是否为空

void Traversal(BinTree BT) // 遍历
  
BinTree CreatBinTree() // 创建一个二叉树
```

常见的遍历方法：

```c
void PreOrderTraversal(BinTree BT) // 先序 --- 根、左子树、右子树
  
void InOrderTraversal(BinTree BT) // 中序 --- 左子树、根、右子树
  
void PostOrderTraversal(BinTree BT) // 后序 --- 左子树、右子树、根
  
void LevelOrderTraversal(BinTree BT) // 层次遍历，从上到下，从左到右
```

------

**二叉树的存储结构**

1. 顺序存储结构

   - 完全二叉树：按从上至下，从左到右顺序存储。

   ![](/Users/vera/Desktop/Data-Structure-and-Algorithms/Data-Structure/Chapter3/Screen Shot 2022-04-09 at 10.04.37 AM.png)

   - 一般二叉树也可以采用这种结构，但会造成空间浪费

   ![](/Users/vera/Desktop/Data-Structure-and-Algorithms/Data-Structure/Chapter3/Screen Shot 2022-04-09 at 10.05.02 AM.png)

2. 链表存储

   ```c
   typedef struct TreeNode *BinTree;
   typedef BinTree Position;
   struct TreeNode{
     ElementType Data;
     BinTree Left;
     BinTree Right;
   }
   ```

   

### 3.3 二叉树的遍历

