#include <iostream>
using namespace std;

template< class Object >
class Stack{
    private:


        class Node{
            Node* next;
            Object data;
            public:

            Node():next{ nullptr } , data{ 0 } {}

            Node(Node* current , const Object &data): next{ current } , data{ data } { }

            Node(Node* current , Object && data): next{ current } , data { move(data) } {  }

            Node( Object &data ): next{ nullptr } , data{ data } {}

            Node( Object && data ): next{ nullptr } , data{ move( data ) } {}

        };

        Node* head ;
        Node* tail ;
        int theSize;
    public:

    Stack():head{ nullptr } , tail{ nullptr } , theSize{ 0 }{
    }

    ~Stack(){
        while(!empty()){
            pop();
        }
    }

    int size( void ) const {
        return theSize;
    }

    void push( Object &obj ) {
        ++theSize;

        if( head == nullptr ) {
            head = new Node{ obj };
            tail = new Node{ -1 }; // end marker 
            return;
        }else{
            head = new Node{ head , obj };
        }
    }

    bool empty( void ) const {
        return head == tail;
    }

    const Object top( void ) const {
         return head -> data;
    }

    void pop( void ) {

        if(head == tail){
            cout<<"( Empty Stack )"<<'\n';
            return ;
        }

        --theSize;

        Node *p = head;

        head = head -> next;

        delete p;
    }
    
};
int main(void){
}
