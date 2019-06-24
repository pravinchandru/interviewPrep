class Queue:
	def __init__(self):
		self.data = []
		self._max_ele = []

	def isEmpty(self):
		if (not self.data):
			return true
		return false

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

	def enqueue(self, element):
		self.data.append(element)
		while (self._max_ele and self._max_ele[-1] < element)
			self._max_ele.popleft()


	def max(self):
		if (not self.data):
			raise IndexError('q empty')
		else:	
			return max(self.data)






