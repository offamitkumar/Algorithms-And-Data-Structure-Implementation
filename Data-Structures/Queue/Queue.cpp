#include <iostream>
using namespace std;

template< class Object >
class Queue{
    private:
        class Node{
            private:
                Object data;
                Node* next;
            public:
                Node():next{ nullptr } , data{ 0 } {}

                Node(Node* current , const Object &data): next{ current } , data{ data } { }

                Node(Node* current , Object && data): next{ current } , data { move(data) } {  }

                Node( Object &data ): next{ nullptr } , data{ data } {}

                Node( Object && data ): next{ nullptr } , data{ move( data ) } {}

                friend class Queue< Object >;
        };

        Node* head;
        Node* tail;
        int theSize;

    public:

        Queue():head{ nullptr } , tail{ nullptr }{
            
        }

        ~Queue() {
            while(!empty()){
                pop();
            }
        }

        int size(void) const {
            return theSize;
        }

        void push( Object &obj ){
            if(head == nullptr){
                head = new Node{ obj };
                head = new Node{ -1 };
            }else{
                tail = tail->next = new Node{ obj };
            }
            ++theSize;
        }

        bool empty( void ) const {
            return head == tail;
        }

        void pop( void ) {
            if( head == tail ) {
                cout<<" ( Empty Queue )" << '\n';
                return ;
            }
            --theSize;
            Node *p = head ;
            head = head -> next;

            delete p;
        }

        Object front( void ) const {
            return head -> data;
        }
};

int main(void){

    return 0;
}
