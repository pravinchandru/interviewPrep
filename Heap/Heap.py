



def heap_sort(arr):

	n = len(arr)
	for i in range (round(n/2)-1, -1, -1 ):	
		heapify(arr, i, n)

	for i in range (n-1, -1, -1):
		arr[i], arr[0] = arr[0], arr[i]
		heapify(arr, 0, i)	


def heapify(arr, start, end):
	largest = start
	left_child = (2*largest)+1
	right_child = (2*largest)+2

	if (left_child < end and arr[left_child] > arr[largest]):
		largest = left_child
	if (right_child < end and arr[right_child] > arr[largest]):
		largest = right_child

	if (largest !=  start):
		arr[largest], arr[start] = arr[start], arr[largest]
		heapify(arr, largest , end)


class Heap:
	def __init__(self, arr):
		self.arr = arr
	def print(self):
		for i in self.arr:
			print(i)
			print("\n")	
	def sort(self):
		heap_sort(self.arr)		

	def heapify(self):
		n = len(self.arr)
		for i in range (round(n/2)-1, -1, -1 ):	
			heapify(self.arr, i, n)



h = Heap([5,6,1,3,2,8,4])
h.heapify()
h.print()
h.sort()
h.print()






