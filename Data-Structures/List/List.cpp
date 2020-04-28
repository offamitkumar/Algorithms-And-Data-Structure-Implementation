#include <algorithm>

template< typename Object >
class List{

    private:

        struct Node{ 

            Object data;
            Node* prev;
            Node* next;

            Node( const Object &d = Object{ } ,  Node* p = { nullptr } , Node* n = { nullptr } )
                : data{ d } , prev{ p } , next{ n } {  }

            Node( Object &&d , Node* p = { nullptr } , Node* n = { nullptr } )
                : data{ std::move( d ) } , prev{ p } , next{ n } { }
        };

    public:

        class const_iterator{

            protected:

                Node* current; // class iterator will need this so instead of making it
                // private we can make it protected so that inherited classes can use it

                Object& retrieve ( ) const {
                    return current -> data;
                }

                const_iterator ( Node* p ) : current{ p } {  } // function is used to implement begin & end 

                friend class List< Object >; // List class need some of implementation of this class 
                // but we also can't expose them to all of the other classes so we need to make 
                // List class a friend of const_iterator class

            public:

                const_iterator( ) : current{ nullptr } { }

                const Object& operator* ( ) {
                    return retrieve();
                }

                const_iterator& operator++( ) {
                    current = current -> next;
                    return *this;
                } 

                const_iterator& operator++( int ) {
                    const_iterator oldNode = *this;
                    ++( *this );
                    return oldNode;
                }

                bool operator== ( const const_iterator& rhs ) const {
                    return current == rhs.current;
                }

                bool operator!= ( const const_iterator& rhs ) const {
                    return current != rhs.current;
                }

        };

        class iterator : public const_iterator {

            protected:

                iterator ( Node* p ) : const_iterator{ p } { }

                friend class List< Object >;

            public:

                iterator ( ) = default;

                Object& operator* ( ) {
                    return const_iterator::retrieve(); // can be done as retrieve is protected
                }

                const Object& operator* ( ) const {
                    return const_iterator::operator*( );
                }

                iterator& operator++ ( ) {
                    this -> current = this -> current -> next;
                    return *this;
                }

                iterator operator++ ( int  ) {
                    iterator old = *this;
                    ++( *this );
                    return old;
                }

        };

};


int main(void){
    return 0;
}
