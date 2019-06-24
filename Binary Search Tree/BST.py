
from collections import namedtuple

class Queue:
	def __init__(self):
		self.data = []

	def isEmpty(self):
		if (not self.data):
			return True
		return False

	def size(self):
		return len(self.data)		

	def top(self):
		if self.isEmpty():
			raise IndexError('q empty')
		else:	
			return self.data[-1]	

	def dequeue(self):
		if (not self.data):
			raise IndexError('q empty')
		else:	
			return self.data.pop(0)

	def enqueue(self, data):
		self.data.append(data)

	def max(self):
		if (not self.data):
			raise IndexError('q empty')
		else:	
			return max(self.data)


def nodes_at_levels(node):
	if (not node):
		raise IndexError('BSt empty')
	else:
		result = []
		nodes_at_level = namedtuple('nodes_at_level', ('Level', 'Nodes'))

		nodesQ = Queue()
		nodesQ.enqueue(node)
		level = 0
		while( not nodesQ.isEmpty()):
			nodes = []
			nodes_level = nodesQ.size()

			while(nodes_level > 0):
				current_node = nodesQ.dequeue()
				nodes.append(current_node)

				if current_node.left:
					nodesQ.enqueue(current_node.left) 
				if current_node.right:	
					nodesQ.enqueue(current_node.right)

				nodes_level -= 1
		
			level += 1	
			result.append(nodes_at_level(level, nodes))	
			

		return result	



		

class BST:
	def __init__(self):
		self.root = None

	def nodes_at_levels(self):
		return nodes_at_levels(self.root)


class BSTNode:
	def __init__(self, data, left, right):
		self.data = data
		self.left = left
		self.right = right


e10 = BSTNode(10, None, None)
e8 = BSTNode(8, None, None)
e6 = BSTNode(6, None, None)
e4 = BSTNode(4, None, None)
e9 = BSTNode(9, e8, e10)
e5 = BSTNode(5, e4, e6)
e7 = BSTNode(7, e5, e9)

tree = BST()
tree.root = e7

result = tree.nodes_at_levels()
print(len(result))
for level, nodes in result:
	print("At Level:" , level)
	for i in nodes:
		print(i.data)

print(result[0])		






