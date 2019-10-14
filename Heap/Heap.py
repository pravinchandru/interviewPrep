
import heapq
import collections

# def heap_sort(arr):

# 	n = len(arr)
# 	for i in range (round(n/2)-1, -1, -1 ):	
# 		heapify(arr, i, n)

# 	for i in range (n-1, -1, -1):
# 		arr[i], arr[0] = arr[0], arr[i]
# 		heapify(arr, 0, i)	


# def heapify(arr, start, end):
# 	largest = start
# 	left_child = (2*largest)+1
# 	right_child = (2*largest)+2

# 	if (left_child < end and arr[left_child] > arr[largest]):
# 		largest = left_child
# 	if (right_child < end and arr[right_child] > arr[largest]):
# 		largest = right_child

# 	if (largest !=  start):
# 		arr[largest], arr[start] = arr[start], arr[largest]
# 		heapify(arr, largest , end)


# class Heap:
# 	def __init__(self, arr):
# 		self.arr = arr
# 	def print(self):
# 		for i in self.arr:
# 			print(i)
# 			print("\n")	
# 	def sort(self):
# 		heap_sort(self.arr)		

# 	def heapify(self):
# 		n = len(self.arr)
# 		for i in range (round(n/2)-1, -1, -1 ):	
# 			heapify(self.arr, i, n)



# h = Heap([5,6,1,3,2,8,4])
# h.heapify()
# h.print()
# h.sort()
# h.print()


class Page:
	def __init__(self, name, content):
		self.name = name
		self.hits = 0
		self.content = content
		
	def visited(self):
		self.hits += 1

	def __lt__(self, other):
		return self.hits < other.hits

class Brows:
	def __init__(self):
		self.pages_map = {}
		self.pages = []
		self.k = 3
		
	def page_visit(self, page):
		page.visited()
		if page not in self.pages_map:
			self.pages_map[page.name] = page
		if (len(self.pages) < self.k):
				heapq.heappush(self.pages, (page.hits, page))	
		elif (page.hits >= self.pages[0].hits):
				heapq.heappushpop(self.pages, (page.hits, page))

	def most_visited(self):
		if len(self.pages) > 0:
			return self.pages[0]
		else:
			return None				


y_t = Page('youtube', 'Video Stream Site')
g = Page('google', 'Search Site')
fb = Page('Facebook', 'Social Media Site')


b = Brows()

b.page_visit(y_t)
b.page_visit(fb)
b.page_visit(y_t)
popular_page = b.most_visited()
print(popular_page[1].name)

	





