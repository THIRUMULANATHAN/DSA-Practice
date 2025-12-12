class TreeNode:
    def _init_(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert_bst(root, value):
    if root is None:
        return TreeNode(value)
    if value < root.value:
        root.left = insert_bst(root.left, value)
    else:
        root.right = insert_bst(root.right, value)
    return root

def preorder(root):
    if root is None:
        return []
    result = [root.value]  # Visit root
    result.extend(preorder(root.left))  # Left subtree
    result.extend(preorder(root.right))  # Right subtree
    return result

# Input reading
n = int(input())
arr = list(map(int, input().split()))

# Construct the BST
root = None
for value in arr:
    root = insert_bst(root, value)

# Preorder traversal of the BST
preorder_result = preorder(root)
total_sum = sum(preorder_result)

# Print results
print(*preorder_result)
print(total_sum)