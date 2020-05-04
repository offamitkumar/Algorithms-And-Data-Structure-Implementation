#include <iostream>
using namespace std;

template< class Object >
class Stack{

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
    public:

    Stack():head{ nullptr } , tail{ nullptr }{
    }

    ~Stack(){
        while(!empty()){
            pop();
        }
    }

    void push( Object &obj ) {
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

        Node *p = head;

        head = head -> next;

        delete p;
    }
    
};
int main(void){
}
