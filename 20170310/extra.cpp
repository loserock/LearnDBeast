/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

   The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
 */

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//TWO LINE:
//it works!

bool checkRepeated(Node* subroot, int odata, bool lessOr)
{
	return (subroot->left ? ((lessOr ? (subroot->left->data < odata) : (subroot->left->data > odata)) && checkRepeated(subroot->left, odata, lessOr)) : true) &&
	       (subroot->right ? ((lessOr ? (subroot->right->data < odata) : (subroot->right->data > odata)) && checkRepeated(subroot->right, odata, lessOr)) : true);
}

bool checkBST(Node* root)
{
	return (root->left ? ((root->left->data < root->data) && checkBST(root->left) && checkRepeated(root->left, root->data, true)) : true) &&
	       (root->right ? ((root->right->data > root->data) && checkBST(root->right) && checkRepeated(root->right, root->data, false)) : true);
}

//ONE LINE:
//currently not completed

bool checkBST(Node* root, bool isRoot = true, int odata = -1, bool lessOr = true)
{
	return isRoot
	       ?
	       (
	        (root->left ? ((root->left->data < root->data) && checkBST(root->left, false, root->data, true)) : true) &&
	        (root->right ? ((root->right->data > root->data) && checkBST(root->right, false, root->data, false)) : true)
	       )
		   :
	       (
	        (root->left ? ((lessOr ? (root->left->data < odata) : (root->left->data > odata)) && checkBST(root->left, false, odata, lessOr) && checkBST(root->left, false, root->data, true)) : true) &&
	        (root->right ? ((lessOr ? (root->right->data < odata) : (root->right->data > odata)) && checkBST(root->right, false, odata, lessOr) && checkBST(root->right, false, root->data, false)) : true)
	       );

}
