// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Valentine sum
struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
public:
int sum_at_distK(Node* root, int target, int k)
    {
        // Your code goes here
        //convert tree into graph problem, making adj lsit and complete with bfs/dfs
        //instead of making again adj_list, just excess store parent to traverse up
        //strore parent for each node
        unordered_map<Node*,pair<Node*,int>> hmap;// stores <parent,vis> for every node in tree
        // unordered_map<Node*,int> vis;//use this for bfs, included this in hmap only
        Node *par = nullptr;//-1
        Node *targetNode = nullptr;
        //do dfs
        dfs(root,par,targetNode,target,hmap);
        
        //do bfs
        queue<Node*> q;
        long long int sum = 0;
        if(targetNode == nullptr){
            return sum;
        }
        q.push(targetNode);
        int level = 0;
        while(!q.empty() && level <= k){
            int q_size = q.size();
            while(q_size-- > 0){
                Node *node = q.front();
                q.pop();
                hmap[node].second = 1;//mark as visited
                sum += node->data;
                if(hmap[node].first != nullptr && !hmap[hmap[node].first].second){//careful with root as parent is NULL
                    q.push(hmap[node].first);//pushing parent[node]
                }
                if(node->left != nullptr && !hmap[node->left].second){ //instead using another hmap for visited array
                    q.push(node->left);//pushing left child
                }
                if(node->right != nullptr && !hmap[node->right].second){
                    q.push(node->right);//pusing right child
                }
            }
            level += 1;
        }
        return sum;
    }
    void dfs(Node *root,Node *par,Node *&targetNode,int target,unordered_map<Node*,pair<Node*,int>> &hmap){
        if(root == nullptr){
            return;
        }
        if(root->data == target){
            //for getting targetNode to do bfs from it
            targetNode = root;
        }
        hmap[root]  = make_pair(par,0);
        dfs(root->left,root,targetNode,target,hmap);
        dfs(root->right,root,targetNode,target,hmap);
    }


};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends