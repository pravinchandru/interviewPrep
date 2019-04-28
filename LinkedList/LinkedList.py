class Node:
    def __init__(self, dataval, nextNode):
        self.dataval = dataval
        self.nextNode = nextNode

def reverseNode(node):
    if(node.nextNode):
        self.reverseNode(node.nextNode)
        node.nextNode.nextNode = node
    else:
        self.headval = node
    return node

def reverse(node):
    temp = reverseNode(node)
    temp.nextNode = None
    return temp

def middleLinkedList(node):
    if(not node):
        return None
    elif(not node.nextNode):
        return node
    else:
        node1=node.nextNode
        while(node1):
            node = node.nextNode
            node1 = node.nextNode.nextNode
        return node

def detectLoop(head):
    node = head
    if(not node):
        return False
    else:
        node1=node.nextNode
        while(node1):
            if(node == node1):
                return True
            node = node.nextNode
            node1 = node.nextNode.nextNode
        return False

def compare(node1, node2):
    if ((node1 and not node2) or (node2 and not node1)):
        return False
    if ((not node1) and (not node2)):
        return True
    if (node1 and node2) and (node1.dataval!=node2.dataval):
        return False
    else:
        return compare(node1.nextNode, node2.nextNode)


def isPalindrome(node):
    if (not node):
        return False
    elif (not node.nextNode):
        return True
    else:
        newList = SLinkedList()
        newList.headval = copyLL(node)
        newList.reverse()
        return compare(node, newList.headval)




def copyLL(node):
    if not node:
        return None
    else:
        return Node(node.dataval, copyLL(node.nextNode))

def search(node, key):
    while(node):
        if(node.dataval == key):
            return True
        node = node.nextNode

    return False

class SLinkedList:
    def __init__(self):
        self.headval = None

    def listprint(self):
        printval = self.headval
        while printval is not None:
            print (printval.dataval)
            printval = printval.nextNode

    def reverseNode(self, node):
        if(node.nextNode):
            self.reverseNode(node.nextNode)
            node.nextNode.nextNode = node
        else:
            self.headval = node
        return node

    def reverse(self):
        temp = self.reverseNode(self.headval)
        temp.nextNode = None
        return temp

    def iterReverse(self):
        temp = self.headval
        stackLinkList = []
        while(temp):
            stackLinkList.append(temp)
            temp = temp.nextNode

        if(not stackLinkList):
            return None
        else:
            newNode = stackLinkList.pop()
            self.headval = newNode
            while(newNode):
                nextNode = stackLinkList.pop() if stackLinkList else None
                newNode.nextNode = nextNode
                newNode = nextNode

    def middleLinkedList(self):
        return middleLinkedList(self.headval)


    def detectLoop(self):
        return detectLoop(self.headval)







list = SLinkedList()
e4 = Node(4, None)
e3 = Node(3, e4 )
e2 = Node(2, e3)
list.headval = Node(1, e2)

list2 = SLinkedList()

e3 = Node(7, None )
e2 = Node(6, e3)
list2.headval = Node(5, e2)


#print(" \n")
#list.listprint()
#print(" \n")
loopList = SLinkedList()

loop2 = Node(2, None)
loop1 = Node(1, loop2)
loopList.headval = loop1
loop2.nextNode = loop1
#middleNode = soloList.middleLinkedList()
#print(loopList.detectLoop())

#print(compare(list.headval, list2.headval))

# copyList = SLinkedList()
# copyList.headval = copyLL(list.headval)
# mid = middleLinkedList( list2.headval )
# print(mid.dataval)

print(isPalindrome(list2.headval))
