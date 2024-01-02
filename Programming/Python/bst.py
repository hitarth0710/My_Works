class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(inOrder, postOrder):
    if inOrder:
        root = Node(postOrder.pop())
        rootIndex = inOrder.index(root.data)
        root.right = buildTree(inOrder[rootIndex+1:], postOrder)
        root.left = buildTree(inOrder[:rootIndex], postOrder)
        return root
    return None

def preOrder(node):
    if node is not None:
        print(node.data, end=' ')
        preOrder(node.left)
        preOrder(node.right)

def write_dot(node, dot_file):
    if node is not None:
        if node.left is not None:
            dot_file.write(f'    "{node.data}" -- "{node.left.data}";\n')
            write_dot(node.left, dot_file)
        if node.right is not None:
            dot_file.write(f'    "{node.data}" -- "{node.right.data}";\n')
            write_dot(node.right, dot_file)

def generate_dot_file(root, filename):
    with open(filename, 'w') as f:
        f.write('graph BST {\n')
        write_dot(root, f)
        f.write('}\n')
    print("Dot file generated.")    

inOrder = ['D', 'B', 'H', 'E', 'I', 'A', 'F', 'J', 'C', 'G']
postOrder = ['D', 'H', 'I', 'E', 'B', 'J', 'F', 'G', 'C', 'A']
root = buildTree(inOrder, postOrder)
print("Tree built:", root is not None)

print("Preorder of the constructed tree :")
preOrder(root)

generate_dot_file(root, 'bstree.dot')