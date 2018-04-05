
#ifndef LEFTISTNODE_H
#define LEFTISTNODE_H

#include <algorithm>
#include <cassert>
#include <ostream>
#include <stack>


#ifndef nullptr
#define nullptr 0
#endif

template <typename Type>
class LeftistNode {
	private:
		Type element;
		LeftistNode *left_tree;
		LeftistNode *right_tree;///
		int heap_null_path_length; ///
        int num;
	public:
		LeftistNode( Type const & );/// constuct

		Type retrieve() const;//// gets vals
		bool empty() const;/// empty check
		LeftistNode *left() const;/// left side
		LeftistNode *right() const; /// other
		int count( Type const & ) const; /// amount acess
		int null_path_length() const; ////  null number

		void push( LeftistNode * nodePoint, LeftistNode *& );///
		void clear();////
};

    template <typename Type>
LeftistNode<Type>::LeftistNode(Type const &obj):
element(obj),
left_tree(nullptr),
right_tree(nullptr),
heap_null_path_length(0)
{
	
}
template <typename Type>
int LeftistNode<Type>::null_path_length() const
{
    return  (this == NULL) ? -1 : heap_null_path_length; // conditonal return
    // if null give neg 1 but if not give val
}

    template <typename Type>
bool LeftistNode<Type>::empty() const
{
	return (this == NULL); // is empty check return
}

    template <typename Type>
int LeftistNode<Type>::count(Type const & elmnetNew) const
{
  if (empty())
  {
      return 0;
  }
    int addUpIn = 0;
    do {
        addUpIn += 1; // adds up elemnets
    }
    while(element==elmnetNew); // chesk valid answers
    
    return addUpIn;
}
    template <typename Type>
void LeftistNode<Type>::clear()
{
    if (left_tree != NULL) // if null empty thid side
    {
        left_tree->clear();
    }
    
    if (right_tree != NULL) // if null empty thid side
    {
        right_tree->clear(); // cut out
    }
    
    delete this; // leaves the Heep
}


    template <typename Type>
Type LeftistNode<Type>::retrieve() const
{
    return this->element; // gives elemnt access
}

template <typename Type>
LeftistNode<Type> * LeftistNode<Type>::left()const
{
    return left_tree; //  left side
}

    template <typename Type>
LeftistNode<Type>* LeftistNode<Type>::right() const
{
    return right_tree; // right side
}

    template <typename Type>
void LeftistNode<Type>::push( LeftistNode *  nodePoint, LeftistNode * &nodePointThis ) // add a push to the  heep
{
    if (nodePoint == NULL)
    {
        return;  // next return
    }
    
    if (nodePointThis == NULL)
    {
        nodePointThis = nodePoint;  // declare the curr node
    }
    
    if (this->element > nodePoint->element) // if the el is bigger  merge the heep
    {
        nodePointThis = nodePoint;
        nodePoint->push(this, nodePointThis); // pushes to the node
        return;
    }
    
    if (this->right_tree == NULL)
    {
        this->right_tree = nodePoint;  // move the tree  the right when empty
    }
    else
    {
        right_tree->push(nodePoint, right_tree); // pushes to the node and merges the tree
    }
    
    heap_null_path_length = std::min( 1 + left_tree->null_path_length(), 1 + right_tree->null_path_length() ); // getting the min in the heep for this val update
    
    
    if (left_tree->null_path_length() < right_tree->null_path_length()) // swap of the trees
        //when left length is smaller
    {
        LeftistNode *nextCurrentLeft = right_tree; //
        
        right_tree = left_tree; // reassign
        
        left_tree = nextCurrentLeft; // switch
    }
    
}


#endif
