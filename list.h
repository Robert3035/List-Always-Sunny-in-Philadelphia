struct Node{
    char val;
    Node* next;

    Node(){
        val = 0;
        next = nullptr;
    }
    Node(char v){
        val = v;
        next = nullptr;
    }
    Node(char v, Node n){
        val = v;
        next = &n;
    }
};

class List{
    private:
        Node* front; //points to the front of list
        Node* it; //points to the current node
        int size; // gives size
        bool empty;
    public:
        List(){
            front = nullptr;
            it = nullptr;
            size = 0;
        }
        List(char v){
            Node n(v);
            front = &n;
            it = &n;
            size = 1;
        }
        char get_iterator(){//Return the value at the iterator
            if(it == nullptr){
                return '[';
            }
            else
                return it->val;
        }
        bool isEmpty(){//Checks whether the list is empty and returns a boolean
            if(front == nullptr){
                return true;
            }
        }
        void begin(){//Moves the iterator to the front of the list
            it = front;
        }
        void end(){//Moves the iterator to the end of the list
            while(it->next != nullptr){
                it = it -> next;
            }
        }
        char getFront(){//Returns the value that front is pointing at
            return front -> val;
        }
        void push_front(char x){//Creates a new node at the beginning of the list
            Node temp(x, *front);
            front = &temp;
            size++;
        }
        void pop_front(){//Clears the node at the front of the list
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        void insert_after(char x){
            //Created new node, and temp pointer to help us insert it
            if(front == nullptr){
                Node temp(x);
                it = &temp;
                front = &temp;
            }
            else{
                Node toInsert(x);
                Node * temp = &toInsert;
                it->next = temp;
                it = temp;
                delete temp;
            }
            size++;
        }
        void clear(){//Clears the list
            front = nullptr;
            it = nullptr;
            //front and the iterator don't point at anything, losing all of the nodes and clearing the list
        }
        void move_up(){//Moves the iterator up in the list
            it = it -> next;
        }
};