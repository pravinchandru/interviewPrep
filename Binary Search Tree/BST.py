
from collections import namedtuple
from collections import deque 
import copy

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

def in_order(node):
	if (not node):
		return 
	in_order(node.left)
	print(node.data)
	in_order(node.right)

def pre_order(node):
	if (not node):
		return 
	
	print(node.data)
	pre_order(node.left)
	pre_order(node.right)

def post_order(node):
	if (not node):
		return 
	
	post_order(node.left)
	post_order(node.right)
	print(node.data)
		

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


def add_node(node, val):
	if(val >= node.data):
		if (node.right):
			add_node(node.right, val)
		else:
			node.right = BSTNode(val, None, None)
	else:
		if (node.left):
			add_node(node.left, val)
		else:
			node.left = BSTNode(val, None, None)			

def num_of_nodes(node):
	if not node:
		return 0
	return (1 + num_of_nodes(node.left) + num_of_nodes(node.right))	

def height_of_tree(node):
	if not node:
		return 0
	return (1 + max(height_of_tree(node.left), height_of_tree(node.right)))	

def find_max(node):
	if not node:
		return 0
	return (max(node.data, find_max(node.left), find_max(node.right)))

def compare(node1, node2):
	if (not node1 and not node2):
		return True
	elif (not node1 or not node2):
		return False
	else:
		return (node1.data == node2.data and compare(node1.left, node2.left) and compare(node1.right, node2.right))

def copyTree(node):
	if not node:
		return None
	return BSTNode(node.data, copyTree(node.left), copyTree(node.right))

def mirror_copy(node):
	if not node:
		return None
	return BSTNode(node.data, copy(node.right), copy(node.left))		

def is_bst(node):
	if not node:
		return True
	if (not node.is_leaf()):
		if(not node.right):
			return (node.data > node.left)
		elif (not node.left):		
			return (node.data >= node.right)
		else:
			return (node.left.data < node.data <= node.right.data) and is_bst(node.left) and is_bst(node.right)
	return True

def count_leaves(node):
		if not node:
			return 0
		if(node.is_leaf()):
			return 1	

		return (count_leaves(node.left) + count_leaves(node.right))
		

		

def common_ancestors(node, node1, node2):
	if not node:
		return None
	elif ((node.data == node1.data or node.data	== node2.data) or (node1.data < node.data < node2.data)):
		return node	
	elif (node.data	> node1.data and node.data > node2.data):
		return common_ancestors(node.left, node1, node2)
	elif (node.data	< node1.data and node.data < node2.data):
		return common_ancestors(node.left, node1, node2)
	else:
		return None	

def print_left(node, is_left):
	if(not node):
		return

	print_left(node.left, True)
	if is_left:
		print(node.data)
	print_left(node.right,False)

def check_leaves_at_same_level(node):
		if not node:
			return False
					
		left_leaf_level = height_of_tree(node.left)
		right_leaf_level = height_of_tree(node.right)
		if (left_leaf_level - right_leaf_level == 0 or left_leaf_level ==0 or right_leaf_level == 0 ):
			return True
		else:
			return False	

def add_greater_values(node):
	if (not node):
		return 0

	return (node.data + add_greater_values(node.left) + add_greater_values(node.right))				

def print_ancestors(node, child_node):
	if not node:
		return False

	left_tree = print_ancestors(node.left, child_node)		
	right_tree = print_ancestors(node.right, child_node)

	if ((left_tree or right_tree) or (node.data == child_node.data)):
		print(node.data)
		return True
	else:
		return False

def print_horizontal_sum(node):
	horizontal_sum = {}
	index = 0
	q = deque()
	q.append(node)
	
	while(q):
		nodes_level = len(q)
		level_sum = 0
		while(nodes_level > 0):
			current = q.popleft()
			level_sum += current.data
			print("current")
			print(current.data)
			print("level_sum")
			print(level_sum)
			
			nodes_level-=1
			if current and current.left:
				q.append(current.left)
			if current and current.right:
				q.append(current.right)
		horizontal_sum[index] =	level_sum
		index+=1

def serialize(node):
	result = []
	index = 0
	def serialize_helper(node, index):

		nonlocal result

		if not node:
			result.append(-1)
		else:				
			result.append(node.data)
			index+=1
			serialize_helper(node.left, index)
			index+=1
			serialize_helper(node.right, index)	
	serialize_helper(node, index)		

	return result


def deserialize(node_list):
	index = 0
	print("node_list")
	print(node_list)
	def deserialize_helper(node_list):
		nonlocal index
		if node_list[index] == -1:
			return None
		else:
			node = BSTNode(node_list[index], None, None)
			index+=1
			node.left = deserialize_helper(node_list)
			index+=1
			node.right = deserialize_helper(node_list)
			return node		

	return deserialize_helper(node_list)	

def first_k(node, k):
	
	index = 0 
	def in_order_traversal(node):
		nonlocal index
		if not node:
			return
			
		in_order_traversal(node.left)	
		index+=1
		if( index > k ):
			return
		print(node.data)
		in_order_traversal(node.right)		
	in_order_traversal(node)

def build_bst(arr, start, end):
	if start < end:
		middle = (start + end) // 2
		node = BSTNode(arr[middle], None, None)
		node.left = build_bst(arr, start, middle)
		node.right = build_bst(arr, middle+1, end)
		return node
	else:
		return None	

def range_lookup(node, min, max):
	res = []
	def range_lookup_helper(node, min, max):
		nonlocal res
		if not node:
			return
		else:
			if(min <= node.data and node.data <= max):
				range_lookup_helper(node.left, min, max)
				res.append(node)	
				range_lookup_helper(node.right, min, max)
			elif (min > node.data):
				range_lookup_helper(node.right, min, max)
			elif (max < node.data):
				range_lookup_helper(node.left, min, max)
	range_lookup_helper(node, min, max)				
	return res

def largest_k(node, k):
	
	index = 0 
	def in_order_traversal(node):
		nonlocal index
		if not node:
			return
			
		in_order_traversal(node.right)	
		index+=1
		if( index > k ):
			return
		print(node.data)
		in_order_traversal(node.left)		
	in_order_traversal(node)				


class BST:
	def __init__(self):
		self.root = None

	def level_order(self):
		return nodes_at_levels(self.root)

	def in_order(self):
		in_order(self.root)

	def pre_order(self):
		pre_order(self.root)
	
	def post_order(self):
		post_order(self.root)	

	def add_node(self, val):
		if not self.root:
			IndexError("Root empty") 
		add_node(self.root, val)

	def num_of_nodes(self):
		return num_of_nodes(self.root)	

	def height_of_tree(self):
		return height_of_tree(self.root)

	def find_max(self):
		return find_max(self.root)

	def compare(self, root_2):
		return compare(self.root, root_2)

	def copyTree(self):
		new_tree = BST()
		new_tree.root = copyTree(self.root)
		return new_tree

	def mirror_copy(self):
		new_tree = BST()
		new_tree.root = mirror_copy(self.root)
		return new_tree	

	def is_bst(self):
		return is_bst(self.root)

	def count_leaves(self):
		return count_leaves(self.root)	

	def common_ancestors(self, node1, node2):
		return common_ancestors(self.root, node1, node2)

	def print_left(self):
		print_left(self.root, True)		

	def check_leaves_at_same_level(self):
		return check_leaves_at_same_level(self.root)	

	def add_greater_values(self):
		return add_greater_values(self.root)	

	def print_ancestors(self, child_node):
		return print_ancestors(self.root, child_node)		

	def print_longest_path(self):
		result = []
		current = []

		def print_longest(node, current):
			nonlocal result

			if not node:
				return

			current.append(node)	
			if(node.is_leaf()):
				if(len(current) >= len(result)):
					result = copy.copy(current)
						
			print_longest(node.left, current)	
			print_longest(node.right, current)	
			current.pop()
			
		print_longest(self.root, current)
			
		for node_entry in result:
			print(node_entry.data)

	def print_vertical_sum(self):
		vertical_sum = {}
		index = 0
		
		def vertical_sum_helper(node, index):
			nonlocal vertical_sum
			if not node:
				return
			if index in vertical_sum:
				vertical_sum[index] = vertical_sum[index] + node.data	
			else:
				vertical_sum[index] =  node.data

			vertical_sum_helper(node.left, index-1)
			vertical_sum_helper(node.right, index+1)
				

		vertical_sum_helper(self.root, index)
		
	def print_horizontal_sum(self):
		print_horizontal_sum(self.root)

	def serialize(self):
		return serialize(self.root)	

	def deserialize(self, node_list):
		return deserialize(node_list)		
		
	def first_k(self, k):
		return first_k(self.root, k)

	def largest_k(self, k):
		return largest_k(self.root, k)	

	def build_bst(self, arr):
		start = 0 
		end = len(arr)
		self.root = build_bst(arr, start, end)	
	def range_lookup(self, min, max):
		return range_lookup(self.root, min, max)	
				


class BSTNode:
	def __init__(self, data, left, right):
		self.data = data
		self.left = left
		self.right = right
	def is_leaf(self):
		return (not self.right and not self.left)	


e10 = BSTNode(10, None, None)
e8 = BSTNode(8, None, None)
e6 = BSTNode(6, None, None)
e4 = BSTNode(4, None, None)
e9 = BSTNode(9, e8, e10)
e5 = BSTNode(5, e4, e6)
e7 = BSTNode(7, e5, e9)
tree = BST()
tree.root = e7

f10 = BSTNode(100, None, None)
f8 = BSTNode(80, None, None)
f6 = BSTNode(60, None, None)
f4 = BSTNode(4, None, None)
f9 = BSTNode(9, f8, f10)
f5 = BSTNode(5, f4, f6)
f7 = BSTNode(7, f5, f9)

tree2 = BST()
tree2.root = f7



# tree.in_order()		
# tree.pre_order()
# tree.post_order()

# result = tree.level_order()
# print(len(result))
# for level, nodes in result:
# 	print("At Level:" , level)
# 	for i in nodes:
# 		print(i.data)


#tree.add_node(12) 

#print(tree.num_of_nodes())

#print(tree.height_of_tree())

#print(tree.find_max())

#print(tree.compare(tree2.root))

#new_tree = tree.copy()

#new_tree = tree.mirror_copy()

#print(tree2.is_bst())

#print(tree.count_leaves())

# ancestor_node = tree.common_ancestors(e5, e7)
# print(ancestor_node.data)

#tree.print_left()

#print(tree.check_leaves_at_same_level())

#print(tree.add_greater_values())

#tree.print_ancestors(e4)

#tree.print_longest_path()

#tree.print_vertical_sum()
#tree.print_horizontal_sum()

# res = tree.serialize()
# head = tree.deserialize(res)
# tree3 = BST()
# tree3.root = head
# #tree3.pre_order()
# print(tree.compare(tree3.root))

#tree.first_k(9)

# tree_4 = BST()
# tree_4.build_bst([4,5,6,7,8,9,10])


# result = tree.range_lookup(3, 8)
# for i in result:
# 	print(i.data)

tree.largest_k(3)






