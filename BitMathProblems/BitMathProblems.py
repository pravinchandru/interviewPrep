import collections
import math


class BitMathProblems:
	def computeParity(num):
		parity = 0
		while(num):
			if (num & 1):
				parity += 1
			num = num >> 1
		return parity

	def swapBits(num, i, j):
		if ((num >> i-1) & 1  != (num >> j-1) & 1 ):
			bit_mask = ((1 << i-1) | (1 << j-1))
			num  ^= bit_mask
		return num

	def findHighBit(num):
		high_bit = 0
		while(num):
			high_bit += 1	
			num >>= 1
		return high_bit	

	def reverseBits(num):
		highBit = BitMathProblems.findHighBit(num)
		lowBit = 1
		while(highBit > lowBit):
			num = BitMathProblems.swapBits(num, highBit, lowBit)
			lowBit += 1
			highBit -= 1
		return num	

	def multiply(a, b):
		res = 0

		while(b > 0):
			if (b & 1):
				res = res + a

			a = a << 1
			b = b >> 1

		return res	

	def divide(dividend, divisor):
		
		sign = -1 if (dividend < 1 or divisor < 1) else 1
		temp = 0
		dividend = abs(dividend)
		divisor = abs(divisor)	

		for i in range(31, -1, -1):
			if (temp +(divisor << i) <= dividend ):
				temp += divisor << i
				q |= 1 << i

		return sign * q
	
	def reverse_number(num):
		try:
			res = 0
			if type(num) is not int: 
				raise Exception('Invalid format, num:', num) 
					
			while(num):
				res = (10 * res) + (num % 10)
				num //= 10

			return res
		except:
			print("Invalid format:",num)	

	def is_number_plaindrome(num):
		reverse_number	= BitMathProblems.reverse_number(num)
		return reverse_number == num

	def on_segment(p1, p , p2):
		if ((p.x <= max(p1.x, p2.x) and p.x >= min(p1.x, p2.x)) and 
		(p.y <= max(p1.y, p2.y)and p.y >= min(p1.y, p2.y))):
			return True
		return False	  	

	def orientation(p1, p , p2):
		val = ((p2.y-p1.y) * (p.x-p2.x)) - ((p.y-p2.y)*(p2.x-p1.x))
		if val == 0:
			return 0 

		if val > 0 :
			return 1
		else:
			return 2

	def do_intersect(p1, p2, p3, p4):
		
		o1 = orientation(p1, p2, p3)
		o2 = orientation(p1, p2, p4)
		o3 = orientation(p3, p4, p1)
		o4 = orientation(p3, p4, p2)

		if(o1 != o2 and o3 != o4):
			return True

		if (o1==0 and on_segment(p1, p3, p2)):
			return True
		if (o2==0 and on_segment(p1, p4, p2)):
			return True	
		if (o3==0 and on_segment(p3, p1, p4)):
			return True
		if (o4==0 and on_segment(p3, p2, p4)):
			return True	

		return False		

	def in_polygon(polygon, point):
		if len(polygon) < 3:
			return False 

		intersect_count = 0
		inf_pt = (math.inf, point.y)
		for i in range(1, polygon.size):
			if do_intersect((point, inf_pt),
							(polygon[i-1], polygon[i])):
				if orientation(polygon[i-1], point, polygon[i]) == 0:
					return on_segment(polygon[i-1], point, polygon[i])
				intersect_count += 1	

		if do_intersect((point, inf_pt),
							(polygon[i], polygon[0])):
				if orientation(polygon[i], point, polygon[0]) == 0:
					return on_segment(polygon[i], point, polygon[0])			
				intersect_count += 1

		return (intersect_count%2 == 1)		



	def does_rectangles_intersect(rectangle_1, rectangle_2):
		for point in rectangle_2:
			if in_polygon(rectangle_1, point):
				return True 
		return False	


		
	def prime_factors(num):
		temp_num = num
		result = []
		while(temp_num % 2 == 0):
			temp_num = temp_num // 2

		if temp_num == 0:
			return result 		

		odd_factor = 3	
		while (odd_factor <= math.sqrt(num)):	
			while(temp_num % odd_factor == 0):
				temp_num = temp_num // odd_factor
				if odd_factor not in result:
					result.append(odd_factor) 
			odd_factor += 2
			
		if temp_num == 0:
			return result 			

		if (temp_num > 2):
			result.append(temp_num)
		return result	

	def is_prime(number):
		prime_factors = BitMathProblems.prime_factors(number)
		if prime_factors and prime_factors[0] == number:
			return True 
		return False


	def lowest_product_digits(number):
		if BitMathProblems.is_prime(number):
			return -1
		elif (number > 0 and number <= 9):
			return (10+number)

		res, num, digit_unit = 0, number, 0
		while(num > 1):
			for i in range(9,1, -1):
				while (num % i == 0):
					res = (i * (math.pow(10, digit_unit))) + res  
					digit_unit += 1
					num //= i
			if (num == number or BitMathProblems.is_prime(num)):
				return -1		
		return res 			



#print(BitMathProblems.computeParity(13))

#print(BitMathProblems.swapBits(12, 4, 1)

#print(BitMathProblems.reverseBits(11))

#print(BitMathProblems.multiply(6, 2))

#print(BitMathProblems.reverse_number(42))

#print(BitMathProblems.is_number_plaindrome('4234'))

# Point = collections.namedtuple('Point', 'x y')

# Rectangle = collections.namedtuple('Rectangle','p1 p2 p3 p4')

# rectangle_1 = Rectangle(p1 = Point(x=2, y=2),
# 						p2 = Point(x=1, y=1),
# 						p3 = Point(x=2, y=2),
# 						p4 = Point(x=2, y=2) )

# rectangle_2 = Rectangle(p1 = Point(x=2, y=2),
# 						p2 = Point(x=2, y=2),
# 						p3 = Point(x=2, y=2),
# 						p4 = Point(x=2, y=2) )



#print(BitMathProblems.prime_factors(68))
#print(BitMathProblems.is_prime(9))
#print(BitMathProblems.lowest_product_digits(100))
