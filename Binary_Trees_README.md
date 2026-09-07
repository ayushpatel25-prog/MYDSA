# Binary Trees — Complete Quick Reference

## 1. What is a Binary Tree?

A **binary tree** is a hierarchical data structure in which every node has **at most two children**:
- Left child
- Right child

A binary tree is not necessarily sorted. If you need the ordering rule `left < root < right`, that is a **Binary Search Tree (BST)**.

### Basic representation

```text
          A
        /   \
       B     C
      / \     \
     D   E     F
```

---

## 2. Important Terminology

Using the tree above:

### Root Node
The topmost node of the tree.

```text
A = Root
```

A tree has exactly one root if it is non-empty.

### Parent Node
A node that has one or more children.

```text
A is parent of B and C.
B is parent of D and E.
```

### Child Node
A node directly connected below a parent.

```text
B and C are children of A.
D and E are children of B.
```

### Sibling Nodes
Nodes having the same parent.

```text
B and C are siblings.
D and E are siblings.
```

### Leaf Node
A node with **no children**.

```text
D, E, F = leaf nodes
```

### Internal Node
A node having at least one child.

```text
A, B, C = internal nodes
```

Note: Some textbooks use "internal node" to mean a non-leaf node.

### Ancestor
Any node that occurs on the path from the root to a given node, excluding the node itself.

For `E`:

```text
A → B → E
```

Ancestors of E:

```text
A, B
```

### Descendant
Any node below a given node.

Descendants of `B`:

```text
D, E
```

Descendants of `A`:

```text
B, C, D, E, F
```

### Subtree
A node together with all of its descendants.

Subtree rooted at `B`:

```text
      B
     / \
    D   E
```

---

# 3. Edge and Path

### Edge
A connection between two directly connected nodes.

In:

```text
A
|
B
```

there is **1 edge** between A and B.

### Path
A sequence of nodes connected by edges.

Path from `A` to `E`:

```text
A → B → E
```

Number of edges = 2.

---

# 4. Level / Depth

There are two common conventions.

## Convention used here

Root is at **level 0**.

```text
             A          level 0
           /   \
          B     C        level 1
         / \     \
        D   E     F      level 2
```

So:

```text
A → level 0
B,C → level 1
D,E,F → level 2
```

### Depth of a node

Depth = number of edges from the root to that node.

Therefore:

```text
depth(A) = 0
depth(B) = 1
depth(E) = 2
```

If your textbook starts the root at level 1, every level number shifts by 1. Always check the convention.

---

# 5. Height

Height is usually measured in **number of edges** on the longest downward path.

For:

```text
          A
        /   \
       B     C
      / \     \
     D   E     F
```

Longest path from root to leaf:

```text
A → B → D
```

or

```text
A → B → E
```

or

```text
A → C → F
```

Each has 2 edges.

Therefore:

```text
height of tree = 2
```

### Height of a node

Height of a node = number of edges in the longest path from that node to a leaf.

```text
height(D) = 0
height(B) = 1
height(A) = 2
```

### Important
A single-node tree has:

```text
height = 0
```

when height is defined in edges.

---

# 6. Size of a Binary Tree

**Size = total number of nodes.**

For:

```text
          A
        /   \
       B     C
      / \     \
     D   E     F
```

There are:

```text
A, B, C, D, E, F
```

So:

```text
size = 6
```

---

# 7. Degree of a Node

Degree = number of children of the node.

For the example:

```text
degree(A) = 2
degree(B) = 2
degree(C) = 1
degree(D) = 0
```

In a binary tree, node degree can only be:

```text
0, 1, or 2
```

---

# 8. Maximum Nodes at Each Level

If root is level 0:

```text
Level 0 → maximum 1 node
Level 1 → maximum 2 nodes
Level 2 → maximum 4 nodes
Level 3 → maximum 8 nodes
```

Formula:

```text
Maximum nodes at level L = 2^L
```

---

# 9. Maximum Nodes in a Binary Tree

If height is `h` measured in edges:

```text
Maximum nodes = 2^(h+1) - 1
```

Examples:

```text
h = 0 → 1 node
h = 1 → 3 nodes
h = 2 → 7 nodes
h = 3 → 15 nodes
```

---

# 10. Minimum Nodes for a Given Height

If height is measured in edges, a tree can be completely skewed.

Therefore:

```text
Minimum nodes = h + 1
```

Example:

```text
A
 \
  B
   \
    C
     \
      D
```

Height = 3

Nodes = 4 = 3 + 1.

---

# 11. Number of Edges

For any non-empty tree:

```text
Number of edges = Number of nodes - 1
```

If:

```text
nodes = 6
```

then:

```text
edges = 5
```

---

# 12. Binary Tree Properties

## Property 1

Every node has at most two children.

```text
Maximum degree = 2
```

## Property 2

For `n` nodes:

```text
edges = n - 1
```

## Property 3

Maximum nodes at level `L`:

```text
2^L
```

when root is level 0.

## Property 4

Maximum nodes for height `h`:

```text
2^(h+1) - 1
```

## Property 5

Minimum height for `n` nodes:

```text
ceil(log2(n + 1)) - 1
```

when height is measured in edges.

## Property 6

Maximum height for `n` nodes:

```text
n - 1
```

This occurs in a completely skewed tree.

---

# 13. Types of Binary Trees

## Full / Strict Binary Tree

Every node has either:

```text
0 children OR 2 children
```

Never exactly one child.

```text
        A
       / \
      B   C
     / \
    D   E
```

This is full.

For a full binary tree:

```text
number of leaf nodes = number of internal nodes + 1
```

---

## Complete Binary Tree

All levels are completely filled except possibly the last level, and the last level is filled **from left to right**.

```text
        A
       / \
      B   C
     / \  /
    D  E F
```

This is complete.

A complete binary tree is important for **heaps**.

---

## Perfect Binary Tree

Every internal node has exactly two children and all leaves are at the same level.

```text
          A
        /   \
       B     C
      / \   / \
     D   E F   G
```

For height `h`:

```text
nodes = 2^(h+1) - 1
leaves = 2^h
```

---

## Balanced Binary Tree

The tree's height remains approximately logarithmic with respect to the number of nodes.

Informally:

```text
height ≈ O(log n)
```

Examples include AVL trees and Red-Black trees (with their own balancing rules).

---

## Skewed Binary Tree

Most nodes have only one child.

### Left skewed

```text
      A
     /
    B
   /
  C
 /
D
```

### Right skewed

```text
A
 \
  B
   \
    C
     \
      D
```

Height becomes:

```text
n - 1
```

---

# 14. Binary Tree Traversals

Traversal means **visiting every node of the tree in a particular order**.

Consider:

```text
          A
        /   \
       B     C
      / \   / \
     D   E F   G
```

---

## 1. Preorder Traversal

Order:

```text
Root → Left → Right
```

Shortcut:

```text
N L R
```

For the tree:

```text
A B D E C F G
```

### Recursive idea

```cpp
preorder(root):
    if root == NULL:
        return

    visit(root)
    preorder(root->left)
    preorder(root->right)
```

---

## 2. Inorder Traversal

Order:

```text
Left → Root → Right
```

Shortcut:

```text
L N R
```

For the tree:

```text
D B E A F C G
```

### Important

For a **Binary Search Tree (BST)**, inorder traversal gives values in sorted order.

### Recursive idea

```cpp
inorder(root):
    if root == NULL:
        return

    inorder(root->left)
    visit(root)
    inorder(root->right)
```

---

## 3. Postorder Traversal

Order:

```text
Left → Right → Root
```

Shortcut:

```text
L R N
```

For the tree:

```text
D E B F G C A
```

### Recursive idea

```cpp
postorder(root):
    if root == NULL:
        return

    postorder(root->left)
    postorder(root->right)
    visit(root)
```

---

## 4. Level Order Traversal

Visit nodes level by level from left to right.

For the tree:

```text
          A
        /   \
       B     C
      / \   / \
     D   E F   G
```

Output:

```text
A B C D E F G
```

It uses a **queue**.

### Recursive/iterative C++ idea

```cpp
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}
```

---

# 15. Traversal Summary

For:

```text
          A
        /   \
       B     C
      / \   / \
     D   E F   G
```

| Traversal | Rule | Output |
|---|---|---|
| Preorder | Root Left Right | A B D E C F G |
| Inorder | Left Root Right | D B E A F C G |
| Postorder | Left Right Root | D E B F G C A |
| Level Order | Level by level | A B C D E F G |

Easy memory trick:

```text
PRE  → Root comes BEFORE children
IN   → Root comes IN BETWEEN children
POST → Root comes AFTER children
```

---

# 16. DFS and BFS

### DFS — Depth First Search

Go deep into the tree before moving to the next branch.

Tree traversals:

```text
Preorder
Inorder
Postorder
```

are DFS-style traversals.

Usually implemented using:

```text
Recursion / Stack
```

### BFS — Breadth First Search

Go level by level.

```text
Level Order
```

uses:

```text
Queue
```

---

# 17. Time Complexity of Traversals

Every node is visited once.

Therefore:

```text
Time = O(n)
```

where `n` = number of nodes.

Space:

### Recursive DFS

```text
O(h)
```

where `h` = tree height.

Worst case skewed tree:

```text
O(n)
```

Balanced tree:

```text
O(log n)
```

### Level Order

Queue can contain nodes from a level.

Worst-case auxiliary space:

```text
O(n)
```

---

# 18. Binary Tree Node in C++

A basic node:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
```

Example creation:

```cpp
Node* root = new Node(10);

root->left = new Node(20);
root->right = new Node(30);

root->left->left = new Node(40);
root->left->right = new Node(50);
```

Tree:

```text
        10
       /  \
     20    30
    /  \
   40   50
```

---

# 19. Binary Tree vs Binary Search Tree

Do not confuse them.

### Binary Tree

Only rule:

```text
At most 2 children
```

No ordering requirement.

### BST

Additional rule:

```text
Left subtree < Root < Right subtree
```

Example:

```text
        50
       /  \
     30    70
    / \    / \
   20 40  60 80
```

Inorder:

```text
20 30 40 50 60 70 80
```

which is sorted.

---

# 20. Quick Revision Sheet

```text
Binary Tree
    ↓
At most 2 children

Root
    ↓
Topmost node

Parent
    ↓
Node having child

Child
    ↓
Directly below parent

Sibling
    ↓
Same parent

Leaf
    ↓
0 children

Internal
    ↓
At least 1 child

Ancestor
    ↓
Above a node

Descendant
    ↓
Below a node

Edge
    ↓
Connection between two nodes

Depth
    ↓
Edges from root to node

Height
    ↓
Longest downward path in edges

Size
    ↓
Total number of nodes

Degree
    ↓
Number of children
```

### Traversals

```text
Preorder   = Root Left Right
Inorder    = Left Root Right
Postorder  = Left Right Root
LevelOrder = Level by Level
```

### Important formulas

```text
Edges = n - 1

Max nodes at level L = 2^L

Max nodes with height h = 2^(h+1) - 1

Min nodes with height h = h + 1

Max height with n nodes = n - 1
```

---

# 21. One Complete Example

```text
              10
            /    \
           20     30
          /  \      \
         40   50     60
```

### Root

```text
10
```

### Children of 10

```text
20, 30
```

### Parent of 50

```text
20
```

### Siblings

```text
20 and 30
40 and 50
```

### Leaf nodes

```text
40, 50, 60
```

### Internal nodes

```text
10, 20, 30
```

### Ancestors of 50

```text
10, 20
```

### Descendants of 20

```text
40, 50
```

### Size

```text
6
```

### Edges

```text
5
```

### Height

```text
2
```

### Preorder

```text
10 20 40 50 30 60
```

### Inorder

```text
40 20 50 10 30 60
```

### Postorder

```text
40 50 20 60 30 10
```

### Level order

```text
10 20 30 40 50 60
```

---

## Exam Tip

When solving a binary-tree question, first draw the tree and identify:

1. Root
2. Parent/children
3. Siblings
4. Leaf/internal nodes
5. Depth/level
6. Height
7. Number of nodes (size)
8. Required traversal

Then apply the relevant formula or traversal.
