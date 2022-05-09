
import java.util.ArrayList;
import java.util.List;

public class Solution {

    public boolean isSubPath(ListNode head, TreeNode root) {

        List<TreeNode> startNodes = new ArrayList<>();
        storeStartNodes(startNodes, root, head.val);

        for (TreeNode node : startNodes) {
            if (isSubPathFromCurrentStartNode(node, head)) {
                return true;
            }
        }
        return false;
    }

    private void storeStartNodes(List<TreeNode> startNodes, TreeNode root, int startValue) {
        if (root == null) {
            return;
        }
        if (root.val == startValue) {
            startNodes.add(root);
        }
        storeStartNodes(startNodes, root.left, startValue);
        storeStartNodes(startNodes, root.right, startValue);
    }

    private boolean isSubPathFromCurrentStartNode(TreeNode root, ListNode head) {
        if (head == null) {
            return true;
        }
        if (root == null) {
            return false;
        }
        if (root.val == head.val) {
            return isSubPathFromCurrentStartNode(root.left, head.next) || isSubPathFromCurrentStartNode(root.right, head.next);
        }
        return false;
    }

}

/*
Classes ListNode and TreeNode are in-built in the solution file on leetcode.com. 
When running the code on the website, do not include these classes.
 */
class ListNode {

    int val;
    ListNode next;

    ListNode(){}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(){}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
