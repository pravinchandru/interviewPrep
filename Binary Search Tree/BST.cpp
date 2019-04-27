//
//  BST.cpp
//  
//
//  Created by Pravin Chandru on 4/24/14.
//
//


#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// Node class
class Node {
    int data;
    Node* right;
    Node* left;
    
public:
    
    Node() {};
    
    void SetData(int aData) { data = aData; };
    void SetLeft(Node* aLeft) { left = aLeft; };
    void SetRight(Node* aRight) { right = aRight; };
    int getData() { return data; };
    Node* getRight() { return right; };
    Node* getLeft() { return left; };
    
};

// BST class
class BST {
    Node *root;
public:
    BST() { root= NULL; };
    void getRoot() { if(root) { cout << root->getData(); }};
    void inOrderPrint(Node* node);
    void postOrderPrint(Node* node);
    void preOrderPrint(Node* node);
    void levelOrderPrint(Node* node);
    
    void addNode(int data);
    void addNode(Node* node, int data);
    int minDepth();
    void minDepth(Node* node, int& level, int currentLevel);
    int depthOfTree();
    int depthOfTree(Node* node);
    int lengthOfTree();
    int lengthOfTree(Node* node, int& length);
    
    int findMin();
    void findMin(Node* node, int& minSoFar);
    
    int findMax();
    void findMax(Node* node, int& maxSoFar);
    
    bool compare(BST BST1, BST BST2);
    bool compare(Node* node1, Node* node2);
    
    BST copyBST(BST BST);
    Node* copyBST(Node* node);
    
    BST mirrorCopyBST(BST BST);
    Node* mirrorCopyBST(Node* node);
    
    bool isBST();
    bool isBST(Node* node);
    
    Node* search(int value);
    Node* search(Node* node, int value);
    
    int countLeaves();
    void countLeaves(Node* node, int& numLeaves);
    
    Node commonAncestors(int node1, int node2);
    bool commonAncestors(int node1, int node2, Node* node, Node* result);
    
    void printLeft();
    void printLeft(Node* root, bool isLeft);
    
    bool checkLeavesAtSameLevel();
    bool checkLeavesAtSameLevel(Node* node);
    
    void addGreaterValues();
    void addGreaterValues(Node* node, int& sum);
    
    void printAncestors(int data);
    void printAncestorsIter(Node* node, int data);
    bool printAncestorsRecurse(Node* node, int data);
    void printStack(stack<Node*> st);
    
    void clearStack(stack<Node*>& stacc);
    
    void calculateVerticalSum();
    void calculateVerticalSum(Node* node, map<int,int>& mapLevels, int level);
    
    void calculateHorizontialSum();
    void calculateHorizontialSum(Node* node, map<int,int>& mapLevels, int level);
    
    void printLongestPath();
    void printLongestPath(Node* node, stack<Node*>& currentPath, stack<Node*>& longestPath);
    void serialize(vector<int>& result);
    void serialize(Node* root, vector<int>& result);
    
    Node* deserialize(vector<int> result, int& index);
    
    
    
    /*void Delete(int data);
     
    
    */
    void Print();
    
};

/**
 * Print the contents of the BST
 */
void BST::Print() {

    
    //inOrderPrint(root);
    //preOrderPrint(root);
    //postOrderPrint(root);
    //levelOrderPrint(root);
}


void BST::inOrderPrint(Node* node) {
    
    if (!node) {
        return;
    }
    inOrderPrint(node->getLeft());
    cout << "data is :" << node->getData() <<endl;
    inOrderPrint(node->getRight());
}

void BST::postOrderPrint(Node* node) {
    if (!node) {
        return;
    }
    postOrderPrint(node->getLeft());
    postOrderPrint(node->getRight());
    cout << "data is :" << node->getData();
    
}

void BST::preOrderPrint(Node* node){
    if (!node) {
        return;
    }
    cout << "data is :" << node->getData();
    preOrderPrint(node->getLeft());
    preOrderPrint(node->getRight());
}


/** Level Order : 
 
 
 Use a Queue to traverse as its similar to BFS 
 
 1. Insert root into queue 
 2. while(!Q.empty())   
    {
        //For every new level
        nodesInLevel=Q.size();
        while(nodesInLevel!=0)
        {
            1. dequeue the node
            2. get its children and insert into queue
            3. nodesInLevel--
 
        }
 
    }
 
 **/
void BST::levelOrderPrint(Node* node){
    if (!node) {
        return;
    }
    
    queue<Node*> q;
    q.push(node);
    int nodeLevel=0;
    
    while (!q.empty()) {
        nodeLevel = q.size();
        while (nodeLevel>0) {
            Node* nodeFocus = q.front();
            q.pop();
            nodeLevel--;
            cout<< nodeFocus->getData() << "--> "<<endl;
            /* for nary tree for (int i=0; i<node.getChildren(); i++) {
               q.enqueue(child(i);
            }*/
            if (nodeFocus->getLeft()) {
                q.push(nodeFocus->getLeft());
            }
            if (nodeFocus->getRight()) {
                q.push(nodeFocus->getRight());
            }
            
        }
        cout<< ""<<endl;
    }
    
    
}


/**
 * Append a node to the  BST
 */
void BST::addNode(int data) {
    
    if (root) {
        addNode(root, data);
    } else {
        Node* temp = new Node();
        temp->SetLeft(nullptr);
        temp->SetRight(nullptr);
        temp->SetData(data);
        root=temp;
    }
    
    
}




void BST::addNode(Node* node, int data) {
    
    if (data <= node->getData()) {
        if (node->getLeft()) {
            addNode(node->getLeft(), data);
        } else {
            Node* temp= new Node();
            temp->SetData(data);
            temp->SetLeft(nullptr);
            temp->SetRight(nullptr);
            node->SetLeft(temp);
        }
    } else {
        if (node->getRight()) {
            addNode(node->getRight(), data);
        } else {
            
            Node* temp= new Node();
            temp->SetData(data);
            temp->SetLeft(nullptr);
            temp->SetRight(nullptr);
            node->SetRight(temp);
        }
   
    }
    
    
}



/** Depth of Tree
 
 */


int BST::depthOfTree(){
    
    return depthOfTree(root);
}


/**
 
 Height of tree
 
 1. Use recursion
 2. if null, return 0
 3. get left height , right height, return 1+Max(rightHeight, LeftHeight)
 **/

int BST::depthOfTree(Node* node){
    
    if(!node){
        return 0;
    }
    int leftDepth = depthOfTree(node->getLeft());
    int rightDepth = depthOfTree(node->getRight());
    return (1+ max(leftDepth, rightDepth));
}

/** Length of Tree
 
 */


int BST::lengthOfTree(){
    
    if(!root){
        return 0;
    }
    int length =0 ;
    lengthOfTree(root, length);
    return length;
}


int BST::minDepth(){
    int level = SHRT_MAX;
    if (!root) {
        return 0;
    }
    minDepth(root, level, 1);
    return level;
}

void BST::minDepth(Node* node, int& level, int currentLevel){
    
    if (!node) {
        return;
    }
    minDepth(node->getLeft(), level, currentLevel+1);
    if (!node->getLeft() && !node->getRight()) {
        if (currentLevel<level) {
            level=currentLevel;
        }
    }
    
    minDepth(node->getRight(), level, currentLevel+1);
    
}



int BST::lengthOfTree(Node* node, int& length){
    
    if (!node) {
        return 0;
    }
    lengthOfTree(node->getLeft(), length);
    length++;
    lengthOfTree(node->getRight(), length);
    
}


/**
 * Delete a node from the BST

void BST::Delete(int data) {
    


}


 */




/**
 * compare 2  BSTs

*/


bool BST::compare(BST BST1, BST BST2)
{
    return compare(BST1.root, BST2.root);
    
}

bool BST::compare(Node* node1, Node* node2)
{
    if (node1==nullptr && node2==nullptr) {
        return true;
    }  else if (node1==nullptr || node2==nullptr) {
        return false;
    } else {
        if (node1->getData() == node2->getData() && compare(node1->getLeft(), node2->getLeft()) && compare(node1->getRight(), node2->getRight())) {
            return true;
        }
    }
    return false;

}


/** Minimum of Tree
 
 */


int BST::findMin(){
    if(!root){
        return 0;
    }
    int minSoFar = SHRT_MAX;
    findMin(root, minSoFar);
    return minSoFar;
}


void BST::findMin(Node* node, int& minSoFar){
    
    if (!node) {
        return;
    }
    findMin(node->getLeft(), minSoFar);
    if (node->getData() < minSoFar) {
        minSoFar = node->getData();
    }
    findMin(node->getRight(), minSoFar);
    
}



/** Maximum of Tree
 
 */


int BST::findMax(){
    if(!root){
        return 0;
    }
    int maxSoFar = SHRT_MIN;
    findMax(root, maxSoFar);
    return maxSoFar;
}


void BST::findMax(Node* node, int& maxSoFar){
    
    if (!node) {
        return;
    }
    findMax(node->getLeft(), maxSoFar);
    if (node->getData() > maxSoFar) {
        maxSoFar = node->getData();
    }
    findMax(node->getRight(), maxSoFar);
    
}

 


/**
 * copy a  BST
 */

BST BST::copyBST(BST bst)
{
    BST copiedTree;
    copiedTree.root = copyBST(bst.root);
    return copiedTree;
}

Node* BST::copyBST(Node* node)
{
    if (!node) {
        return nullptr;
    }
    Node* temp =  new Node();
    temp->SetData(node->getData());
    temp->SetLeft(copyBST(node->getLeft()));
    temp->SetRight(copyBST(node->getRight()));
    return temp;
    
}



/**
 * mirror copy a  BT
 */

BST BST::mirrorCopyBST(BST bst)
{
    BST copiedTree;
    copiedTree.root = copyBST(bst.root);
    return copiedTree;
}

Node* BST::mirrorCopyBST(Node* node)
{
    if (!node) {
        return nullptr;
    }
    Node* temp =  new Node();
    temp->SetData(node->getData());
    temp->SetLeft(mirrorCopyBST(node->getRight()));
    temp->SetRight(mirrorCopyBST(node->getLeft()));
    return temp;
    
}



/* Check if its a BST
 
 
 */

bool BST::isBST()
{
    return isBST(root);
}


bool BST::isBST(Node* node)
{
    if (!node)
        return true;
    
    if(!node->getLeft() && !node->getRight())
        return true;
    
    else {
        
        if (!node->getLeft()) {
            if (! (node->getData()<node->getRight()->getData() ))
                return false;
            
        } else if(!node->getRight()) {
            if (! (node->getData()>node->getLeft()->getData()) )
                return false;
        } else
            return(isBST(node->getLeft()) && isBST(node->getRight()));
        
        return true;
        
    }
    
}


/** Search for a value*/

Node* BST::search(int value)
{
    if (!root) {
        return nullptr;
    }
    
    return search(root, value);
}

Node* BST::search(Node* node, int value)
{
    if (!node) {
        return nullptr;
    }
    if (node->getData() == value) {
        return node;
    } else if(value < node->getData())  {
        return search(node->getLeft(), value);
    } else
        return search(node->getRight(), value);
}


/** count the leaves of tree */

int BST::countLeaves()
{
    if (!root) {
        return 0;
    }
    int numLeaves=0;
    countLeaves(root, numLeaves);
    return numLeaves;
}

void BST::countLeaves(Node* node, int& numLeaves)
{
    if(!node)
        return;
    
    countLeaves(node->getLeft(), numLeaves);
    if (!node->getLeft() && !node->getRight() ) {
        numLeaves++;
    }
    countLeaves(node->getRight(), numLeaves);
}



/** Common Ancestors of 2 nodes**/

Node BST::commonAncestors(int node1, int node2)
{
    Node ancestor;
    commonAncestors(node1, node2 , root, &ancestor);
    
    cout<< "ancsestor data " << ancestor.getData() <<endl;
    return ancestor;
}




bool BST::commonAncestors(int node1, int node2, Node* node, Node* result)
{
    if (!node) {
        return false;
    }
    
    
    
    bool left = commonAncestors(node1, node2, node->getLeft(), result);
    bool right = commonAncestors(node1, node2, node->getRight(), result);
    
    
    
    
    if ( left && right )
    {
        result = node;
        cout << " inside if :" << result->getData() <<endl;
    } else if ( left || right)
    {
        
        if (node->getData() == node1 || node->getData() == node2) {
            *result = *node;
            cout << " inside else if :" << result->getData() <<endl;
        }

    }
    
    if (node->getData() == node1 || node->getData()==node2) {
        cout << "node data :" << node->getData()<<endl;
        return true;
    } else {
        return false;
    }
    
}


/** Print Left side of tree
 
 */

void BST::printLeft()
{
    printLeft(root, false);
}

void BST::printLeft(Node* node, bool isLeft)
{
    if (!node) {
        return;
    }
    
    if (isLeft) {
        cout << " left node :" << node->getData()<< endl;
    }
    
    printLeft(node->getLeft(), true);
    printLeft(node->getRight(), false);
}


/** Check leaves at same level 
 
 */

bool BST::checkLeavesAtSameLevel()
{
    return checkLeavesAtSameLevel(root);
}

bool BST::checkLeavesAtSameLevel(Node* node)
{
    if (!node) {
        return false;
    }
    int h1=depthOfTree(node->getLeft());
    int h2= depthOfTree(node->getRight());
    
    
    if ( h1==0 || h2==0 || (h1-h2) == 0) {
        return true;
    } else {
        return false;
    }
}


/** Check leaves at same level
 
 */
void BST::addGreaterValues()
{
    if (!root) {
        cout << "tree doesnot  exists" << endl;
        return;
    }
    int sum=0;
    addGreaterValues(root, sum);
}

void BST::addGreaterValues(Node* node, int& sum)
{
    if (!node) {
        return;
    }
    addGreaterValues(node->getRight(), sum);
    node->SetData(sum+=node->getData());
    /*node->SetData(sum+ node->getData());
    if (!node->getRight()) {
        sum = node->getData();
    }*/
    
    addGreaterValues(node->getLeft(), sum);
}

/**  Print Ancestors
 
 Iter
 
 Recursion
 
 **/


void BST::printAncestors(int data)
{
    /**if(!printAncestorsRecurse(root, data))
        cout << "element not found" <<endl;**/
    
    printAncestorsIter(root, data);

}

void BST::printAncestorsIter(Node* node, int data)
{
    if(!node)
        cout << "BST empty" <<endl;
    
    
    std::stack<Node*> stac;
    stac.push(node);
    
    while (!stac.empty()) {
        if (stac.top()->getData() ==  data) {
            cout << "printing ancestors path" << endl;
            printStack(stac);
            return;
        } else {
            if (!stac.top()->getLeft() && !stac.top()->getRight()) {
                stac.pop();
                if (stac.top()->getRight()) {
                    stac.push(stac.top()->getRight());
                } else {
                    stac.pop();
                }
            }
            else {
                if (stac.top()->getLeft())
                    stac.push(stac.top()->getLeft());
                 else if (stac.top()->getRight())
                    stac.push(stac.top()->getRight());
                
            }
            
        }
    }
    cout << "element not found" <<endl;
    
    
}
void BST::printStack(stack<Node*> st)
{
    while (!st.empty()) {
        cout<< st.top()->getData() << "--> " << endl;
        st.pop();
    }
}


void BST::clearStack(stack<Node*>& stacc)
{
    stack<Node*> temp;
    swap(temp,stacc);
    
}
bool BST::printAncestorsRecurse(Node* node, int data)
{
    if (!node) {
        return false;
    }
    
    if (node->getData() ==  data) {
        cout << node->getData() << "-->" << endl;
        return true;
    }
    
    if( printAncestorsRecurse(node->getLeft(), data) || printAncestorsRecurse(node->getRight(), data) )
    {
        cout << node->getData() << "-->" <<endl;
        return true;
    }
    
    return false;
    
}

/** Print vertical sum of nodes by level in BST
 */

void BST::calculateVerticalSum()
{
    map<int, int> resultMap;
    map<int, int>::iterator resultMapIter;
    calculateVerticalSum(root, resultMap, 0);
    
    for (resultMapIter=resultMap.begin(); resultMapIter!=resultMap.end(); ++resultMapIter) {
        cout << "level :" << resultMapIter->first <<endl;
        cout << "sum :" << resultMapIter->second << endl;
     }
    
}

void BST::calculateVerticalSum(Node* node, map<int, int>& mapLevels, int level)
{
    if (!node) {
        return;
    }
    
    calculateVerticalSum(node->getLeft(), mapLevels, level-1);
    mapLevels[level]=mapLevels[level]+node->getData();
    calculateVerticalSum(node->getRight(), mapLevels, level+1);
}



/** Print vertical sum of nodes by level in BST
 */

void BST::calculateHorizontialSum()
{
    map<int, int> resultMap;
    map<int, int>::iterator resultMapIter;
    calculateHorizontialSum(root, resultMap, 0);
    
    for (resultMapIter=resultMap.begin(); resultMapIter!=resultMap.end(); ++resultMapIter) {
        cout << "level :" << resultMapIter->first <<endl;
        cout << "sum :" << resultMapIter->second << endl;
    }
    
}

void BST::calculateHorizontialSum(Node* node, map<int, int>& mapLevels, int level)
{
    if (!node) {
        return;
    }

    queue<Node*> q;
    q.push(node);
    
    int sum =0;
    int nodeLevel=0;
    
    while (!q.empty()) {
        nodeLevel = q.size();
        while (nodeLevel>0) {
            Node* nodeFocus = q.front();
            q.pop();
            nodeLevel--;
            cout<< nodeFocus->getData() << "--> "<<endl;
            sum+=nodeFocus->getData();
            /* for nary tree for (int i=0; i<node.getChildren(); i++) {
             q.enqueue(child(i);
             }*/
            if (nodeFocus->getLeft()) {
                q.push(nodeFocus->getLeft());
            }
            if (nodeFocus->getRight()) {
                q.push(nodeFocus->getRight());
            }
            
        }
        
        mapLevels[level]+=sum;
        level++;
        sum=0;
        cout<< ""<<endl;
    }

    
}

void BST::printLongestPath()
{
    if (!root) {
        return;
    }
    stack<Node*> longestPath;
    stack<Node*> currentPath;
    printLongestPath(root, currentPath, longestPath);
    
    printStack(longestPath);
}

void BST::printLongestPath(Node* node, stack<Node*>& currentPath, stack<Node*>& longestPath)
{
    if (!node) {
        return;
    }
    currentPath.push(node);
    printLongestPath(node->getLeft(), currentPath, longestPath);
    printLongestPath(node->getRight(), currentPath, longestPath);
    if (!node->getLeft() && !node->getRight()) {
        if (currentPath.size() >= longestPath.size()) {
            
            longestPath=currentPath;
        }

    }
    currentPath.pop();
    
    
}


/** Serialize : write a tree to file or vector
 
 Follow pre Order to record the tree nodes in vector.
 
 **/

void BST::serialize(vector<int>& result)
{
    serialize(root, result);
}

void BST::serialize(Node* node, vector<int>& result)
{
    if (!node) {
        result.push_back(-1);
        return;
    }
    
    result.push_back(node->getData());
    serialize(node->getLeft(), result);
    serialize(node->getRight(), result);
    
}


/** Deserialize : forming a tree from file or vector
 
 Iterate through the array and follow the pre Order allocation.
 
 
 **/

Node* BST::deserialize(vector<int> result, int& index)
{
    
    if (result[index]== -1 ) {
        //index++;
        
        return nullptr;
    }
    
    
    Node* node = new Node();
    node->SetData(result[index]);
    index++;
    node->SetLeft(deserialize(result, index));
    index++;
    node->SetRight(deserialize(result, index));
    return node;
}


int main()
{
    // New BST
    BST bst;
    
    // Append nodes to the BST
    cout << "BST :" << endl;
    bst.addNode(5);
    bst.addNode(3);
    bst.addNode(2);
    bst.addNode(4);
    
    bst.addNode(7);
    bst.addNode(6);
    bst.addNode(8);
    bst.addNode(9);
    cout << "nodes added " <<endl;
    /*bst.addNode(400);
    bst.addNode(800);
    bst.addNode(900);
    bst.getRoot();
    bst.Print();*/
    /*
    BST bst1;
    bst1.addNode(300);
    bst1.addNode(200);
    bst1.addNode(100);

    
    //cout << " depth of tree :" << bst.depthOfTree() <<endl;
    
    //cout << " length of tree :" << bst.lengthOfTree()<<endl;

    
    if (bst.compare(bst, bst1)) {
        cout << "trees are same " << endl;
    } else {
        cout << "trees are different " << endl;
    }
    
    cout << "min element in tree is " << bst.findMin();
    cout << "max element in tree is " << bst.findMax();

    
    BST bst2;
    bst2=bst2.copyBST(bst);
    cout << "Copied binary tree" << endl;
    bst.Print();
    
    if (bst.isBST()) {
        cout << "yes it is a BST" << endl;
    } else {
        cout << "no it is not a BST" << endl;
    }
    
    bst.Print();
    Node* searchResult;
    searchResult = bst.search(400);
    if(searchResult)
        cout << "search node is available" << searchResult->getData();
    else
        cout << "element not there in BST " << endl;
   
    
    cout << "leaves in the tree :" << bst.countLeaves() <<endl ;
    bst.Print();
    bst.commonAncestors(1, 400);
    
    
    bst.printLeft();
    if (bst.checkLeavesAtSameLevel()) {
        cout << " leaves are at same level " << endl;
    } else {
        cout << " leaves are at different level " << endl;
        
    }
    bst.Print();
    
    bst.addGreaterValues();
    
    bst.Print();
    
    bst.printAncestors(400);
    
    
    
    bst.Print();
    bst.calculateVerticalSum();
    bst.calculateHorizontialSum();
    bst.printLongestPath();
    
    
    vector<int> nodesVector;
    bst.serialize(nodesVector);
    cout << "serialized " << nodesVector.size()<<endl;
    
    
    Node newRoot;
    int index=0;
    
    
    Node* temp=bst.deserialize(nodesVector, index);;
    bst.preOrderPrint(temp);*/
    
    
    //bst.Print();
    
    cout << " the min depth is " << bst.minDepth() <<endl;
    
}