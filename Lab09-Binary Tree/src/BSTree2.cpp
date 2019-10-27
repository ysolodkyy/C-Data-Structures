
#include "BSTree.h"
#include "show9.cpp"
using namespace std;

//
// Binary Search Tree Function Implementations /////////////////////////////////
//


template<typename DataType, class KeyType>
BSTree<DataType,KeyType>& BSTree<DataType,KeyType>::operator=(const BSTree<DataType,KeyType>& other)
{
	if(*this == &other)
		return *this;
	clear();
	copyHelper(root, other.root);
	return *this;
}


template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::copyHelper(BSTreeNode *&tree, BSTreeNode* other)
{
	if(other != NULL)
	{
		BSTreeNode *left = NULL;
		BSTreeNode *right = NULL;

		copyHelper(left, other->left);  //Copy left branch
		copyHelper(right, other-right); //Copy right branch
		tree = new BSTreeNode(other->dataItem, left, right); //Reached leaf
	}
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::insert(const DataType &newDataItem)
{
	insertHelper(newDataItem, root);
}


template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::insertHelper(const DataType &newDataItem, BSTreeNode *& node)
{

	if(node == NULL)
		// either the tree is empty or reached the end binary search without finding a key
	{
		node = new BSTreeNode(newDataItem, NULL, NULL);
	}
	else
	{
		//new data item key is less than node key -- go left
		if(newDataItem.getKey() < (node->dataItem).getKey())
			insertHelper(newDataItem, node->left);

		//new data item key is greater than node key -- go right
		else if(newDataItem.getKey() > (node->dataItem).getKey())
			insertHelper(newDataItem, node->right);

		else //key match found : ((tree->dataItem).getKey() == newDataItem.getKey())
			node->dataItem = newDataItem; // update data
	}
}
// DONE
//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::retrieve(const KeyType &searchKey, DataType &searchDataItem) const
{
	return retrieveHelper(searchKey, searchDataItem, root);
}

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::retrieveHelper(const KeyType &searchKey, DataType &searchDataItem, BSTreeNode *node) const
{
	if(node == NULL)
		return false; // base case -- key not found or tree is empty
	else
	{
		if (searchKey < (node->dataItem).getKey()) //search key less than. search left subtree
			return retrieveHelper(searchKey, searchDataItem, node->left);

		else if(searchKey > (node->dataItem).getKey()) //Key is greater than. search right subtree
			return retrieveHelper(searchKey, searchDataItem, node->right);

		else // search key match -- update the data & return true
		{
			searchDataItem = node->dataItem;
			return true;
		}
	}
}
// DONE
//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::remove(const KeyType &deleteKey)
{
	return removeHelper(deleteKey, root);
}

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::removeHelper(const KeyType &deleteKey, BSTreeNode *&node)
{
	if(node == NULL) // tree is empty, or reached end of binary search with no key found
		return false;
	else
	{
		//Delete key is less than the current node, go left subtree
		if(deleteKey < (node->dataItem).getKey())
			return removeHelper(deleteKey, node->left);

		//Delete key is greater than the current node, go right subtree
		else if(deleteKey > (node->dataItem).getKey())
			return removeHelper(deleteKey, node->right);

		else
			//Delete key found
		{
			//Node has no children -- simply delete the node
			if(node->left == NULL && node->right == NULL)
			{
				delete node;
				node = NULL;
			}

			//Node only has right child, swap child with parent
			else if(node->left == NULL)
			{
				BSTreeNode* temp = node;
				node = node->right;
				delete temp;
			}
			//Node only has left child, swap child with parent
			else if(node->right == NULL)
			{
				BSTreeNode* temp = node;
				node = node->left;
				delete temp;
			}
			//Node has both children, find the node that is directly before the
			//node in sorted order, delete that one from the tree, and place
			//its data into the original node
			else
			{
				//Go left one node
				BSTreeNode* temp = node->left;
				//Go right as far as you can
				while(temp->right != NULL)
					temp = temp->right;
				//Temp should now be the node before it in sorted orrder
				//Swap the data items
				node->dataItem = temp->dataItem;
				//Remove the temp node in the tree
				removeHelper((temp->dataItem).getKey(), node->left);
			}
			return true;
		}
	}

}

//--------------------------------------------------------------------------------------------------------------


template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::writeKeys() const
{
	writeKeysHelper(root);
	cout << endl;
}

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::writeKeysHelper(BSTreeNode *node) const
{
	if(node != NULL)
	{
		//To write in ascending order, go left, print, then go right
		writeKeysHelper(node->left);
		cout << (node->dataItem).getKey() << " ";
		writeKeysHelper(node->right);
	}
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::clear()
{
	clearHelper(root);
}

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::clearHelper(BSTreeNode *&node)
{
	if(node != NULL)
	{
		//Clear left branch
		clearHelper(node->left);
		//Clear right branch
		clearHelper(node->right);
		//Can't go left or right, so delete self
		delete node;
		//Set all to NULL
		if(node->left != NULL)
			node->left = NULL;
		if(node->right != NULL)
			node->right = NULL;
		node = NULL;
	}
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::isEmpty() const
{
	//If the root is NULL, then obviously the tree doesn't have anything in it
	return (root == NULL);
}


template<typename DataType, class KeyType>
int BSTree<DataType,KeyType>::getHeight() const
{
	return getHeightHelper(root, 0);
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
int BSTree<DataType,KeyType>::getHeightHelper(BSTreeNode *node, int currentLevel) const
{
	static int maxLevel = 0;
	//If the node is null, then check the current level with the max level
	if(node == NULL)
	{
		if(currentLevel > maxLevel)
			maxLevel = currentLevel;
	}
	//Continue left and right
	else
	{
		getHeightHelper(node->left, currentLevel + 1);
		getHeightHelper(node->right, currentLevel + 1);
	}
	return maxLevel;
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
int BSTree<DataType,KeyType>::getCount() const
{
	return getCountHelper(root);
}

template<typename DataType, class KeyType>
int BSTree<DataType,KeyType>::getCountHelper(BSTreeNode *node) const
{
	//Base case, no node so don't add
	if(node == NULL)
		return 0;
	//Add 1 and go left and go right
	else
		return 1 + getCountHelper(node->left) + getCountHelper(node->right);
}

//--------------------------------------------------------------------------------------------------------------

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::writeLessThan(const KeyType& searchKey) const
{
	writeLessThanHelper(searchKey,root);
}

template<typename DataType, class KeyType>
void BSTree<DataType,KeyType>::writeLessThanHelper(const KeyType& searchKey, BSTreeNode *node) const
{
	if(node != NULL)
	{
		if(searchKey <= (node->dataItem).getKey())
		{
			writeLessThanHelper(searchKey,node->left);
		}
		else
		{
			//To write in ascending order, go left, print, then go right
			writeLessThanHelper(searchKey,node->left);
			cout << (node->dataItem).getKey() << " ";
			writeLessThanHelper(searchKey,node->right);
		}
	}
}
