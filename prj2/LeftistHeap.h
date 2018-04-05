
#ifndef LeftistHeap_H
#define LeftistHeap_H

#ifndef nullptr
#define nullptr 0
#endif
#include "HeapException.h"
#include "LeftistNode.h"
//#include "HeapException.h"

template <typename Type>
class LeftistHeap {
	private:
		LeftistNode<Type> *root_node;
		int heap_size;

	public:
		LeftistHeap(); ////
		LeftistHeap(LeftistHeap const &);///
		~LeftistHeap();////

		void swap( LeftistHeap &heap ); ////
		LeftistHeap &operator=(LeftistHeap); /////

		bool empty() const;/////
		int size() const;/////
		int null_path_length() const;///
		Type top() const ;/////
		int count(Type const &) const;///

		void push(Type const &);/////
		Type pop();/////
		void clear();////

	// Friends

	template <typename T>
	friend std::ostream &operator<<(std::ostream &, LeftistHeap<T> const&);
};



    template <typename Type>
LeftistHeap<Type>::LeftistHeap():
root_node(nullptr),
heap_size(0){}

    template <typename Type>
LeftistHeap<Type>::LeftistHeap(LeftistHeap const &heap):
root_node(nullptr),
heap_size(0)
{
    LeftistNode<Type>* nodeOrder = heap.root_node;
    
	// Traverses through the argument heap and pushes the entries
	
    std::stack<LeftistNode<Type>*> stackVar; // stack from stander  boys
    do
    {
        if(nodeOrder != NULL)
        {
            stackVar.push(nodeOrder); //adds to the stack
            
            nodeOrder = nodeOrder->left(); // left side assign
        }
        else
        {
            nodeOrder = stackVar.top(); // takes top  of stack
            
            stackVar.pop();
            push(nodeOrder->retrieve()); // access element
            
            nodeOrder = nodeOrder->right(); // right tree access and assign to the heep of nodes
        }
        
    }while ((nodeOrder != NULL) || !empty()); // go throught the loop to travers
    
}

    template <typename Type>
LeftistHeap<Type>::~LeftistHeap()
{
	this->clear(); /// emptys people
}

    template <typename Type>
void LeftistHeap<Type>::swap(LeftistHeap<Type> &heap)
{
	std::swap( root_node, heap.root_node );
	std::swap( heap_size, heap.heap_size );
}

    template <typename Type>
LeftistHeap<Type> &LeftistHeap<Type>::operator=(LeftistHeap<Type> rhs)
{
	swap( rhs );

	return *this;
}

    template <typename Type>
int LeftistHeap<Type>::null_path_length()const
{
    return root_node->null_path_length(); // null length just given of root
}


    template <typename Type>
void LeftistHeap<Type>::push( Type const &e )
{
    if (empty()) /// checks if empty
    {
        root_node = new LeftistNode<Type>(e); // creates the new node of to root
        heap_size = 1;
        return;
    }
     heap_size++;
    
    root_node->push(new LeftistNode<Type>(e), root_node); // adds if it not empty with the push to merge
   
}



    template <typename Type>
Type LeftistHeap<Type>::pop() // take the last node and pops it
{
    if (empty())
    {
       throw HeapUnderflow(); // if empty excetion
    }
    
    LeftistNode<Type> *pastNode = root_node;
    
    Type elemNode = root_node->retrieve(); // creates the node elemnet
    
    if ( size() == 1 )
    {
        heap_size = 0;
        
        delete root_node; // deletes the root
        
        root_node = NULL; // nulls it
      
        return elemNode; // return
    }
   
    
    if (root_node->left() == NULL|| root_node->right() ==
        NULL) // when the trees are null on both sides
    {
        root_node = (root_node->left() != NULL) ? root_node->left() : root_node->right(); //send a conditions statement and makes it to the  root with the trees
    
    }
    else {
        
        LeftistNode<Type>  *newNodes;
        
        if  (root_node->left()->retrieve() <= root_node->right()->retrieve())// nodes from root to right  when from left ard small
        {
            
            newNodes = root_node->right(); //assigns right tree to new node
            root_node = root_node->left(); // get
        }
        else {
            
            newNodes = root_node->left();// moveing the node down with root left
            root_node = root_node->right();//
        }
        
        newNodes->push( newNodes, root_node ); // merges the new node
    }
     heap_size--; // decrement the heep size
    
        delete pastNode; //kicks the node  in delete
   
    return elemNode; // sends ne element node
}
    template <typename Type>
int LeftistHeap<Type>::count(Type const & e) const
{
    int addUpIn = 0;
    
    for (int num = 0; num < heap_size; num++) // easy count up of stuff
    {
        addUpIn++; // adds up elemnets
    }
    
    return addUpIn; // set num
}

template <typename Type>
Type LeftistHeap<Type>::top() const
{
    if (empty()) // throws exception
    {
         throw HeapUnderflow();
    }
    
    return root_node->retrieve();
}

template <typename Type>
void LeftistHeap<Type>::clear()
{
    if (!empty()) // not empty
    {
        root_node->clear();
        root_node = NULL;
        heap_size = NULL; // return null
    }
}

    template <typename Type>
bool LeftistHeap<Type>::empty() const
{
    return heap_size == nullptr; // if empty
}

    template <typename Type>
int LeftistHeap<Type>::size() const
{
    return heap_size; // size of
}



    template <typename T>
std::ostream &operator<<( std::ostream &out, LeftistHeap<T> const &heap )
{
    
	return out;
}



#endif
