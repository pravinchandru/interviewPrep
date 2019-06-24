


def evalRPNExpressions(expression):
	dlimiter = ','
	operators = {
		'+'	:	lambda x, y : x + y,
		'-'	:	lambda x, y : x - y,
		'*'	:	lambda x, y : x * y,	
		'/'	:	lambda x, y : x / y	
	}
	s = []
	for token in expression.split(dlimiter):
		if token in operators:
			s.append(operators[token](s.pop(),s.pop()))
		else:
			s.append(token)
	return s[-1]		
				



def wellFormedness(expression):
	matchMap = {
	 	'{' : '}',
	 	'[' : ']',
	 	'(' : ')'
	}

	s = []
	for i in expression:
		if (s and i == matchMap[s[-1]]):
			s.pop()
		else:
			s.append(i)
	return not s		


class Stack:
    def __init__(self):
        self.items = []
        self.maxItems = []
        self.minItems = []

    def print(self):
    	for i in range(0, len(self.items)):
    		print(self.items[(len(self.items)-1) - i])
    		print(' \n')    

    def is_empty(self):
    	return len(self.items) == 0    

    def push(self, item):
    	if self.is_empty():
    		self.items.append(item)
    		self.maxItems.append(item)
    		self.minItems.append(item)
    	else:
    		self.items.append(item)
    		self.maxItems.append(max(item, self.maxItems[-1]))
    		self.minItems.append(min(item, self.minItems[-1]))

    def pop(self):
    	if self.is_empty():
    		raise IndexError('No items')			
    	else:
    		self.maxItems.pop()
    		self.minItems.pop()	
    		return self.items.pop()

    def max(self):
    	if self.is_empty():
    		raise IndexError('max Error: No items')		
    	else:
    		return self.maxItems[-1]

    def min(self):
    	if self.is_empty():
    		raise IndexError('max Error: No items')		
    	else:
    		return self.minItems[-1]		




s = Stack()
s.push(6)
s.push(5)
s.push(7)

s.print()
print(s.max())
print(s.min())
s.pop()
s.pop()

s.print()
print(s.max())
print(s.min())

print(wellFormedness("{[]}())"))


