bool checkBST(Node* root) {
   return recursiveCheck(root, -1, 10001);
}

bool recursiveCheck(Node* node, int min, int max) {
    if (nullptr == node) return true;
    if (node->data <= min || node-> data >= max) return false;
    return (recursiveCheck(node->left, min, node->data) && recursiveCheck(node->right, node->data, max));  
}