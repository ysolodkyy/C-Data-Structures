//--------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
//--------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
  public:

    // Constructors
    BSTree ()                        // Default constructor
  {
    	root = NULL;
  }

    BSTree ( const BSTree<DataType,KeyType>& other )   // Copy constructor
    {
    	 *this = other;
    }

    // overload operator
    BSTree& operator= ( const BSTree<DataType,KeyType>& other ); // Overloaded assignment operator


    // Destructor
    ~BSTree ()
    {
    	clear();
    }

    // Binary search tree manipulation operations
    void insert ( const DataType& newDataItem );  // Insert data item
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const;
                                                  // Retrieve data item
    bool remove ( const KeyType& deleteKey );            // Remove data item
    void writeKeys () const;                      // Output keys
    void clear ();                                // Clear tree

    // Binary search tree status operations
    bool isEmpty () const;                        // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    int getHeight () const;                       // Height of tree
    int getCount () const;			  // Number of nodes in tree
    void writeLessThan ( const KeyType& searchKey ) const; // Output keys < searchKey

  protected:

    class BSTreeNode                  // Inner class: facilitator for the BSTree class
    {
      public:
    
        // Constructor
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
      {
        	dataItem = nodeDataItem;
        	left = leftPtr;
        	right = rightPtr;
      }

        // Data members
        DataType dataItem;         // Binary search tree data item
        BSTreeNode *left,    // Pointer to the left child
                   *right;   // Pointer to the right child
    };

    // Recursive helpers for the public member functions -- insert prototypes of these functions here.

    void showHelper      ( BSTreeNode *p, int level ) const;

    void copyHelper(BSTreeNode *& tree, BSTreeNode *other);

    void insertHelper(const DataType &newDataItem, BSTreeNode *&tree);
    bool retrieveHelper(const KeyType &searchKey, DataType &searchDataItem, BSTreeNode *tree) const;
    bool removeHelper(const KeyType &deleteKey, BSTreeNode *&tree);
    void writeKeysHelper(BSTreeNode *tree) const;
    void clearHelper(BSTreeNode *&tree);
    int getHeightHelper(BSTreeNode *tree, int currentLevel) const;

    void writeLessThanHelper(const KeyType& searchKey, BSTreeNode *node) const;

    int getCountHelper(BSTreeNode *tree) const;
    // Data member
    BSTreeNode *root;   // Pointer to the root node
};

#endif	// define BSTREE_H

