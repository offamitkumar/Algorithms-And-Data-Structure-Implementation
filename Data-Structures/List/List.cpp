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

        
        Node *head;
        Node *tail;
        int theSize;

        void init ( ) {

            theSize = 0;
            head = new Node;
            tail = new Node;

            head->next = tail;
            tail->prev = head;
        }

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

                const Object& operator* ( ) const {
                    return retrieve();
                }

                const const_iterator& operator++( ) const {
                    current = current -> next;
                    return *this;
                } 

                const const_iterator& operator++( int ) const {
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
                    return const_iterator::retrieve(); // return reference 
                }

                const Object& operator* ( ) const {
                    return const_iterator::operator*( ); // return constant reference 
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

        List ( ) {
            init ();
        }

        ~List( ) {
            clear( );
            delete head;
            delete tail;
        }

        List ( const List &rhs ) {
            init( );
            for( auto &itr : rhs ){
                push_back( itr );
            }
        }

        List & operator= ( const List &rhs ) {
            List copy = rhs;
            std::swap( *this , copy );
            return *this;
        }

        List( List &&rhs ): theSize{ rhs.theSize } , head{ rhs.head } , tail{ rhs.tail }{
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }

        List & operator= ( List && rhs ) {
            std::swap( theSize , rhs.theSize );
            std::swap( head , rhs.head );
            std::swap( tail , rhs.tail );
            return *this;
        }

        iterator begin( ) {
            return { head ->next }; // call the iterator constructor , which will further call const_iterator constructor
        }

        const_iterator begin( ) const{
            return { head-> next }; // List call is friend of const_iterator class
        }

        iterator end( ) {
            return { tail };
        }

        const_iterator end( ) const {
            return { tail }; 
        }

        int size( ) const{
            return theSize;
        }

        bool empty( ) const{
            return size() == 0;
        }

        void clear ( ) {
            while( !empty()) {
                //pop_front();
            }
        }

        Object & front( ) {
            return *begin();
        }

        const Object & front( ) const {
            return *begin();
        }

        Object & back( ){
            return *--end();
        }

        const Object & back( ) const {
            return *--end();
        }

        void push_front( const Object &x ){
            insert( begin() , x );  // to be implemented
        }

        void push_front( Object && x ) {
            insert( begin(), std::move( x ) ); // to be implemented
        }

        void push_back( const Object &x ) {
            insert( end() , x ); // to be implemented

        }

        void push_back( Object && x ) {
            insert( end() , std::move( x ) ); // to be implemented

        }

        void pop_front( ) {
            erase( begin( ) ); // to be implemented

        } 

        void pop_back( ){
            erase( --end( ) ); // to be implemented 
        }
        
};


int main(void){
    List<int>l;
    int x = l.front();
    List<int>::iterator itr = l.begin();
    return 0;
}
