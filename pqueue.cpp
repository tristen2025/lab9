
#include<iostream>
#include"pqueue.h"
#include<cassert>

#define DEBUGMODE 0
#define DEBUG(s) if(DEBUGMODE)std::cerr<<s<<std::endl;

namespace coen70_lab9{
    PriorityQueue::PriorityQueue(){
        many_nodes = 0;
        head_ptr = NULL;
    
    
    
    }
    PriorityQueue::PriorityQueue(const PriorityQueue& p){
        many_nodes = p.many_nodes;
        //node* tail_ptr = new node();
        list_copy(p.head_ptr, head_ptr);
        
        
    
    
    }
    void PriorityQueue::operator = (const PriorityQueue& p){
        if(p.head_ptr == head_ptr)return;
        list_clear(head_ptr);
        many_nodes = p.many_nodes;
       // node* tail_ptr = new node();
        list_copy(p.head_ptr, head_ptr/*, tail_ptr*/);

    
    
    
    
    
    }
    void PriorityQueue::insert(const Item& entry, unsigned int priority){
        node* cursor = list_search_priority(head_ptr,priority);
        if(size() >0){
            DEBUG("size > 0")
        
            if(cursor != NULL){
                DEBUG("cursor is not null")
                while(cursor->link() != NULL &&cursor->link()->priority() == priority)cursor = cursor->link();
                list_insert(cursor,priority,entry);
            }
            else{
                DEBUG("cursor is null")
                //list_head_insert(head_ptr,priority,entry);
                cursor = head_ptr;
                
                DEBUG(cursor->data())
                while(cursor->link() != NULL && priority <= cursor->link()->priority()){
                    /*unsigned int priA = cursor->priority();
                    Item  valA = cursor->data();
                    
                    unsigned int priB = cursor->link()->priority();
                    Item valB = cursor->link()->data();
                    
                    cursor->set_data(valB);
                    cursor->set_priority(priB);
                    
                    cursor->link()->set_data(valA);
                    cursor->link()->set_priority(priA);
                    
                    */
                    
                    DEBUG("shifging =cursor")
                    
                    cursor = cursor->link();
                
                
                }
                if(priority> cursor->priority()){
                    list_head_insert(head_ptr,priority,entry);
                    
                    
                }
                
                else{
                        DEBUG("through loop")
                        DEBUG(cursor->data())
                //if(cursor == head_ptr)list_head_insert(head_ptr,priority,entry);
                        list_insert(cursor, priority,entry);
                }
                }
        }
        else{
            DEBUG("list is empty")
            list_head_insert(head_ptr,priority,entry);
        
        
        
        }
        //std::cout<<"performed aaddionr"<< <<"\n";
        DEBUG("printing")
        //printList(head_ptr);
        
        
        
        
    
    
    
    
    }
    PriorityQueue::Item PriorityQueue::get_front(){
        assert(size( ) > 0);
        /*node* cursor = head_ptr;
        node* max = cursor;
        node* prev = NULL;
        node* max_prev = NULL;
        unsigned int max_pri = cursor->priority();
        while(cursor->link() != NULL){
            if(cursor->priority() > max_pri){
                max_pri = cursor->priority();
                max = cursor;
                max_prev = prev;
                
            
            
            }
            prev = cursor;
            cursor = cursor->link();
        
        
        }
        DEBUG("made it here ")
        list_remove(max_prev);
        Item a = max->data();
        DEBUG(a);
        //printList(head_ptr);
        return a;*/
        many_nodes--;
        Item ret = head_ptr->data();
        list_head_remove(head_ptr);
        return ret;
       //return 0;
    
    
    }
    size_t PriorityQueue::size( ) const{
        return list_length(head_ptr);
    
    
    
    
    }
    bool PriorityQueue::is_empty( ) const{
        return list_length(head_ptr) == 0;
    
    
    
    
    }
    void printList(node* head_ptr){
        node* cursor;
        //node* tail;
        list_copy(head_ptr,cursor/*, tail*/);
        while(cursor != NULL){
            //std::cout<<cursor->data()<<" "<<cursor->priority()<<"\n";
            
            cursor = cursor->link();
        
        
        
        }
    
    
    }





    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        size_t answer;
        
        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;
        
        return answer;
    }
    
    void list_head_insert(node*& head_ptr, unsigned int pri,const node::value_type& entry)
    {
        head_ptr = new node(entry, pri,head_ptr);
    }
    
    void list_insert(node*& previous_ptr, unsigned int pri,const node::value_type& entry)
    {
        node *insert_ptr;
        
        insert_ptr = new node(entry, pri,previous_ptr->link( ));
        previous_ptr->set_link(insert_ptr);
    }
    
    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
        node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        
        return NULL;
    }
    node* list_search_priority(node* head_ptr, unsigned int  target)
    // Library facilities used: cstdlib
    {
        node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->priority( ))
                return cursor;
        
        return NULL;
    }

    
    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        
        return NULL;
    }
    
    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        node *cursor;
        size_t i;
        
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        
        return cursor;
    }
    
    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        const node *cursor;
        size_t i;
        
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        
        return cursor;
    }
    
    void list_head_remove(node*& head_ptr)
    {
        node *remove_ptr;
        
        remove_ptr = head_ptr;
        head_ptr = head_ptr->link( );
        delete remove_ptr;
    }
    
    void  list_remove(node* previous_ptr)
    {
        node *remove_ptr;
        
        remove_ptr = previous_ptr->link( );
        previous_ptr->set_link( remove_ptr->link( ) );
        delete remove_ptr;
    }
    
    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }
    
    void list_copy(const node* source_ptr, node*& head_ptr/*, node*& tail_ptr*/)
    // Library facilities used: cstdlib
    {
        head_ptr = NULL;
        node* tail_ptr = NULL;
        
        // Handle the case of the empty list.
        if (source_ptr == NULL)
            return;
        
        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr,source_ptr->priority() ,source_ptr->data( ));
        tail_ptr = head_ptr;
        
        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link( );
        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->priority() ,source_ptr->data( ));
            tail_ptr = tail_ptr->link( );
            source_ptr = source_ptr->link( );
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}