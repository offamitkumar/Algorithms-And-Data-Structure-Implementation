#include <iostream>
using namespace std;

template< class Object >
class Stack{

    class Node{
        Node* next;
        Object data;
        public:
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
            tail = head;
            return;
        }else{
            head = new Node{ head , obj };
        }
    }

    bool empty( void ) const {
        return head == nullptr;
    }

    const Object top( void ) const {
         return head -> data;
    }

    void pop( void ) {

        if(head == nullptr){
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
