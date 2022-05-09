
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSubPath = function (head, root) {
    const startNodes = [];
    storeStartNodes(startNodes, root, head.val);

    for (let node of startNodes) {
        if (isSubPathFromCurrentStartNode(node, head)) {
            return true;
        }
    }
    return false;
};

/**
 * @param {TreeNode[]} startNodes
 * @param {TreeNode} root
 * @param {number} startValue
 * @return {void}
 */
function storeStartNodes(startNodes, root, startValue) {
    if (root === null) {
        return;
    }
    if (root.val === startValue) {
        startNodes.push(root);
    }
    storeStartNodes(startNodes, root.left, startValue);
    storeStartNodes(startNodes, root.right, startValue);
}

/**
 * @param {TreeNode} root
 * @param {ListNode} head
 * @return {boolean}
 */
function isSubPathFromCurrentStartNode(root, head) {
    if (head === null) {
        return true;
    }
    if (root === null) {
        return false;
    }
    if (root.val === head.val) {
        return isSubPathFromCurrentStartNode(root.left, head.next) || isSubPathFromCurrentStartNode(root.right, head.next);
    }
    return false;
}


/*
 Functions ListNode and TreeNode are in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include these functions.
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}
