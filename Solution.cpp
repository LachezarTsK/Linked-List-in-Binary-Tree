
#include <vector>
using namespace std;

/*
Structs ListNode and TreeNode are in-built in the solution file on leetcode.com. 
When running the code on the website, do not include these structs.
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution {
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> startNodes;
        storeStartNodes(startNodes, root, head->val);

        for (const auto& node : startNodes) {
            if (isSubPathFromCurrentStartNode(node, head)) {
                return true;
            }
        }
        return false;
    }
    
private:
    void storeStartNodes(vector<TreeNode*>& startNodes, TreeNode* root, int startValue) {
        if (root == nullptr) {
            return;
        }
        if (root->val == startValue) {
            startNodes.push_back(root);
        }
        storeStartNodes(startNodes, root->left, startValue);
        storeStartNodes(startNodes, root->right, startValue);
    }

    bool isSubPathFromCurrentStartNode(TreeNode* root, ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        if (root->val == head->val) {
            return isSubPathFromCurrentStartNode(root->left, head->next) || isSubPathFromCurrentStartNode(root->right, head->next);
        }
        return false;
    }
};
