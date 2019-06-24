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
		res = 0

		while(b > 0):
			if (b & 1):
				res = res + a

			a = a << 1
			b = b >> 1

		return res	


#print(BitMathProblems.computeParity(13))

#print(BitMathProblems.swapBits(12, 4, 1)

#print(BitMathProblems.reverseBits(11))

#print(BitMathProblems.multiply(6, 2))



