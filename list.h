// Name: Rebecca Ferreira
// Assignment: Linked List 
// Date last modified: September 17
// Honor statement: I have neither given nor received any unauthorized help on this assignment.
//https://en.cppreference.com/w/cpp/language/this used this to help me with "this" pointer
//https://www.geeksforgeeks.org/constructors-c/ also used this site for refernce

#ifndef LIST_H_DEFINED
#define LIST_H_DEFINED
// Generic class representing linked list objects
template <typename T>
class List {
    // Use Node objects to build a linked list.  Do not modify this code!
    struct Node {
        T data;
        Node *prev;
        Node *next;
        Node(const T& data, Node *prev, Node *next) :
        data(data), prev(prev), next(next) {}
        Node(const T&) : Node(data, nullptr, nullptr) {}
        Node() : Node(T(), nullptr, nullptr) {}
        ~Node() {
            std::cout << "Freeing node holding " << data << '\n';
        }
    };
    
    // Add any data members required to manage the linked list
    // (Hint: It is much easier to implement the methods below
    // if you use sentinel nodes.)
    Node *head;
    Node *tail;
    int size_;
    
public:
    // Custom iterator type.  Do not modify this code!
    class list_iterator {
        Node *cursor;  // Pointer to a node in the list
    public:
        list_iterator(Node *ptr) : cursor(ptr) {}
        list_iterator operator++() {
            list_iterator temp = *this;
            cursor = cursor->next;
            return temp;
        }
        list_iterator operator++(int) {
            cursor = cursor->next;
            return *this;
        }
        T& operator*() { return cursor->data; }
        bool operator==(const list_iterator& other) { return cursor == other.cursor; }
        bool operator!=(const list_iterator& other) { return cursor != other.cursor; }
    };
    
    // A list initially is empty
    List() {
        head = new Node;
        tail = new Node;
        // Modify this constructor to initialize properly a new list object
        head->next = tail;
        tail->prev = head;
        size_ = 0;
    }
    
    // Properly cleans up the memory held by the list.
    ~List() {
        // Modify this destructor to clean up properly a list object
        auto current = head;
        auto next = head;
        while(current != tail)
        {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        
    }
    // Inserts a new item onto the back of the list.
    // Returns true if successful; otherwise, returns false.
    bool insert(const T& item) {
        if (head->data == NULL)
        {
            head->data = item;
            size_++;
        }
        else
        {
            auto temp = new Node;
            
            tail->data = item;
            tail->next = temp;
            
            temp->prev = tail;
            temp->next = new Node;
            
            tail = temp;
            size_++;
        }
        return true;
    }
    
    // Removes the first occurrence of a given item from the list.
    // Returns true if successful; otherwise, returns false.
    bool remove(const T& item) {
        auto current = head;
        if (size_ == 0)
        {
            return false;
        }
        while (current->data != item)
        {
            current = current->next;
        }
        if(current != head)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        else
        {
            head = current->next;
        }
        
        delete current;
        size_--;
        return true;
    }
    
    // Returns the number of elements the list contains
    size_t size() const {
        // Modify this code to make this method work according to its specification
        return size_;
    }
    
    // Returns an iterator to the first element of the list
    list_iterator begin() {
        // Modify this code to make this method work according to its specification
        return { head };
    }
    
    // Returns an iterator just past the last element of the list
    list_iterator end() {
        // Modify this code to make this method work according to its specification
        return { tail };
    }
};


#endif
