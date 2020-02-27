
def reverse(words):
	reversed_strings = []
	for i in words.split(" "):
		reversed_strings.append(i[::-1])

	return " ".join(reversed_strings)	

def permute(a, l, r): 
    if l==r: 
        print(a)
    else: 
        for i in range(l,r): 
            a[l], a[i] = a[i], a[l] 
            permute(a, l+1, r) 
            a[l], a[i] = a[i], a[l] # backtrack 


def perms(word):
    stack = list(word)
    results = [stack.pop()]
    while len(stack) != 0:
        c = stack.pop()
        new_results = []
        for w in results:
            for i in range(len(w)+1):
                new_results.append(w[:i] + c + w[i:])
        results = new_results
    return results

    
           

def strstr(str, substr):
    if (len(substr) > len(str)) or not substr or not str:
        raise Exception("string invalid format")            
    for i in  range(len(str)):
        if str[i] == substr[0] and str[i:(i+len(substr))] == substr:
            return i            
        
  
def count_n_say(strin, n):

    def process_str(curr):
        if not curr:
            raise Exception("str empty")
        result = ''    
        count = 1
        for i in range (1, len(curr)):
            if curr[i-1] == curr[i]:
                count+=1
            else:
                result+= str(count)    
                result+=curr[i-1]
                count = 1    
        result+= str(count)    
        result+=curr[len(curr)-1]       
        return result

    if not strin:
        raise Exception("str empty")

    res = []
    curr = strin
    res.append(curr)
    while (len(res) <= n):
        curr = process_str(curr)
        res.append(curr)
    return res[n-1]    



# def integer_2_roman(num):
# 	roman_map = {
# 		1: 'I', 
# 		2: 'II', 
# 		3: 'III', 
# 		4: 'IV', 
# 		5: 'V',
#         6: 'VI', 
#         7: 'VII', 
#         8: 'VIII', 
#         9: 'IX', 
#         10: 'X', 
#         20: 'XX',
#         30: 'XXX', 
#         40: 'XL',
#         50: 'L', 
#         60: 'LX', 
#         70: 'LXX', 
#         80: 'LXXX',
#         90: 'XC', 100: 'C', 200: 'CC', 300: 'CCC', 400: 'CD', 500: 'D',
#                 600: 'DC', 700: 'DCC', 800: 'DCCC', 900: 'CM', 1000: 'M',
#                 2000: 'MM', 3000: 'MMM'}
#     result = ''
#     pow = len(str(num))-1             
#     while(num):
#     	curr_power = (10**pow)
#     	reminder = num %  curr_power	
#     	quotient  = num // curr_power
#     	if (quotient in roman_map):
#     		result +=  roman_map[quotient]
#     	else:
#     		while(quotient):
#     			result += roman_map[curr_power]
#     			quotient -= 1
#     	num = reminder
#     return result	           


# rev_str_result = reverse("Hi Reverse these words")
# print(rev_str_result)	


# string = "ABC"
# n = len(string) 
# a = list(string) 
# permute(a, 0, n) 

# def mod(val):
# 	val+=1

# val = 6
# print(mod(val))
# print(val)
#print(integer_2_roman(56))


#print(strstr("pravin", ""))

#print(count_n_say("1",4))
print(permute_iter([1,2,3]))
