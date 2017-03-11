
// FILE: pqueue.h
// CLASS PROVIDED: PriorityQueue (a priority queue of items)
//
// TYPEDEF for the PriorityQueue class:
//   typedef _____ Item
//     The type Item is the data type of the items in the Priority Queue.
//     It may be any of the C++ built-in types (int, char, etc.), or a class
//     with a default constructor, a copy constructor, and assignment operator.
//
// CONSTRUCTOR for the PriorityQueue class:
//   PriorityQueue( )
//     Postcondition: The PriorityQueue has been initialized with no Items.
//
// MODIFICATION MEMBER FUNCTIONS for the PriorityQueue class:
//   void insert(const Item& entry, unsigned int priority)
//     Postcondition: A new copy of entry has been inserted with the specified
//     priority.
//
//   Item get_front( )
//     Precondition: size( ) > 0.
//     Postcondition: The highest priority item has been returned and has been
//     removed from the PriorityQueue. (If several items have equal priority,
//     then the one that entered first will come out first.)
//
// CONSTANT MEMBER FUNCTIONS for the PriorityQueue class:
//   size_t size( ) const
//     Postcondition: Return value is the total number of items in the
//     PriorityQueue.
//
//   bool is_empty( ) const
//     Postcondition: Return value is true if the PriorityQueue is empty.
//
// VALUE SEMANTICS for the PriorityQueue class:
//   Assignments and the copy constructor may be used with
//   PriorityQueue objects



// Class: node
// PROVIDES: A class for a node in a linked list
//
// TYPEDEF for the node class:
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined as node::value_type in a
//     typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const value_type& init_data = value_type(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*).
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_priority(unsigned int new_priority)
//     Postcondition: The node now contains the specified new priority
//
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this node.
//
//   unsigned int priority() const
//     Postcondition: The return value is the priority from this node.
//
//   const node* link( ) const <----- const version
//   node* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//

#ifndef PQUEUE_H
#define PQUEUE_H
#include <cstdlib> // Provides size_t

namespace coen70_lab9
{
    class node
    {
    public:
        // TYPEDEF
        typedef double value_type;
        
        // CONSTRUCTOR
        node(const value_type& init_data = value_type( ), unsigned int init_priority = 0, node* init_link = NULL)
        {
            data_field = init_data;
            priority_field = init_priority;
            link_field = init_link;
        }
        
        // Member functions to set the data,priority,and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_priority(unsigned int new_priority) {priority_field = new_priority;}
        void set_link(node* new_link) { link_field = new_link; }
        
        // Constant member function to retrieve the current data:
        value_type data( ) const { return data_field; }
        
        // Constant member function to retrieve the current priority:
        unsigned int priority() const {return priority_field;}
        
        // Two slightly different member functions to retreive
        // the current link:
        const node* link( ) const { return link_field; }
        node* link( ) { return link_field; }
        
    private:
        value_type data_field;
        unsigned int priority_field;
        node* link_field;
    };
        std::size_t list_length(const node* head_ptr);
    void list_head_insert(node*& head_ptr, unsigned int pri,const node::value_type& entry);
    void list_insert(node* previous_ptr,unsigned int pri ,const node::value_type& entry);
    node* list_search(node* head_ptr, const node::value_type& target);
    node* list_search_priority(node* head_ptr, unsigned int  target);
    const node* list_search
    (const node* head_ptr, const node::value_type& target);
    node* list_locate(node* head_ptr, std::size_t position);
    const node* list_locate(const node* head_ptr, std::size_t position);
    void list_head_remove(node*& head_ptr);
    void list_remove(node* previous_ptr);
    void list_clear(node*& head_ptr);
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
    void printList(node* head_ptr);

    
    
    
    class PriorityQueue
    {
    public:
        typedef int Item;
        //-- student must list all the prototypes here including
        //-- the copy constructor, assignment operator, and destructor
        PriorityQueue();
        PriorityQueue (const PriorityQueue& p);
        ~PriorityQueue(){
            list_clear(head_ptr);
        
        }
        void operator = (const PriorityQueue& p);
        void insert(const Item& entry, unsigned int priority);
        Item get_front();
               size_t size( ) const;
        bool is_empty( ) const;


    private:
        // Note: head_ptr is the head pointer for a linked list that
        // contains the items along with their priorities. These nodes are
        // kept in order from highest priority (at the head of the list)
        // to lowest priority (at the tail of the list). The private member
        // variable, many_nodes, indicates how many nodes are on the list.
        // The data type Node is completely defined below.
        size_t many_nodes;

        node *head_ptr;
       
    };
    
}



#endif
