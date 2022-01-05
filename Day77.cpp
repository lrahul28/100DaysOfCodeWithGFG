// Initial Template for C++
//Shortest Range in a BST
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    public:
     int findDepth(Node *root)
    {
        if(root==NULL)
        return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
        
    }
    pair<int, int> shortestRange(Node *root) {
        // Your code goes here
        queue<Node*> q;
        q.push(root);
        int l = root->data, r = root->data;
        int d = findDepth(root);
        
        vector<vector<int>> nums(d);
        int i = 0 ;
        while(!q.empty())
        {
            int size = q.size();
   
            
            
            while(size--)
            {
            
                Node* x = q.front();
                q.pop();
                nums[i].push_back(x->data);
                
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
                
            }
         ++i;
         
        }
     
        pair<int, int> ans;
        int gap = INT_MAX;
        set<pair<int, pair<int, int>>> st;
        for (int i = 0; i < nums.size(); ++i)
        {
            st.insert({nums[i][0], {i, 0}});
        }
        while (1)
        {
            pair<int, pair<int, int>> mini = *st.begin();
            auto it = st.end();
            --it;
            pair<int, pair<int, int>> maxi = *it;

            st.erase(st.begin());
            if (maxi.first - mini.first < gap)
            {
                gap = maxi.first - mini.first;
                ans.first = mini.first;
                ans.second = maxi.first;
            }
            if (mini.second.second + 1 >= nums[mini.second.first].size())
                break;
            st.insert({nums[mini.second.first][mini.second.second + 1], {mini.second.first, mini.second.second + 1}});
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } Driver Code Ends