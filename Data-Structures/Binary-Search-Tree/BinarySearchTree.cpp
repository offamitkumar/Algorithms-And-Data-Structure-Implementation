#include <iostream>

using namespace std;

template< typename Comparable , typename Comparator=less<Comparable> >
class BinarySearchTree{
    private:
        struct BinaryNode{
            Comparable element;
            BinaryNode *leftChild;
            BinaryNode *rightChild;

            BinaryNode( const Comparable & theElement , BinaryNode *leftTree , BinaryNode *rightTree )
                : element{ theElement } , leftChild{ leftTree } , rightChild{ rightTree }{  }

            BinaryNode( Comparable && theElement , BinaryNode *leftTree , BinaryNode *rightTree )
                : element{ move( theElement ) } , leftChild{ leftTree } , rightChild{ rightChild } { };
        };

        BinaryNode *root;
        Comparator isLessThan;

        void insert( const Comparable & x, BinaryNode * & t ) {

            if( t == nullptr )
                t = new BinaryNode{ x , nullptr , nullptr };
            
            else if( isLessThan( x , t -> element ) )
                insert( x , t -> left );

            else if( isLessThan( t -> element , x ) )
                insert( x , t -> right );
            else
                ; // Duplicate element , do nothing 

        }
        void insert( Comparable && x, BinaryNode * & t ) {
            
            if( t == nullptr )
                t = new BinaryNode{ move( x ) , nullptr , nullptr };

            else if( isLessThan( move( x ) , t -> element ) ) 
                insert ( move( x ) , t -> left );

            else if( isLessThan( t -> element , move( x ) ) )
                insert ( t -> left , move( x ) );

            else
                ; // element repeated ; do nothing 
        }

        void remove( const Comparable & x, BinaryNode * & t );
        
        BinaryNode * findMin( BinaryNode *t ) const{

            // this function is implemented in recursive way
            
            if( t == nullptr ) 
                return nullptr;

            if( t -> left == nullptr )
                return t;

            return findMin( t -> leftChild );

        }
        BinaryNode * findMax( BinaryNode *t ) const{
            
            // this function implemented in non-recursive way
            if( t != nullptr  )
                while ( t -> rightChild != nullptr )
                    t = t -> rightChild;

            return t;
        }

        /*
         * x is value to be searched.
         * t is root of sub-tree
         */
        bool contains( const Comparable &x , BinaryNode *t ) const {

            if( t == nullptr ) 
                return false;

            else if ( isLessThan( x, t->element ) ) 
                return contains( x, t->leftChild );

            else if ( isLessThan( t->element, x ) )
                return contains( x, t->rightChild );

            else
                return true;

        }
        
        void makeEmpty( BinaryNode * & t);
        void printTree( BinaryNode *t , ostream & out ) const;

        BinaryNode * clone( BinaryNode *t ) const;
            
    public:

        BinarySearchTree();
        BinarySearchTree( const BinarySearchTree &rhs );
        BinarySearchTree( BinarySearchTree && rhs );
        ~BinarySearchTree( );

        const Comparable & findMin( ) const {

            BinaryNode *t = findMin( root );
            if( t != nullptr )
                return t -> value;
            else 
                return -1;

        }
        const Comparable & findMax( ) const {

            BinaryNode *t = findMax( root );
            if( t != nullptr )
                return t -> value;
            else 
                return -1;

        }

        bool contains( const Comparable &x ) const {
            return contains( x , root ) ;
        }
        bool isEmpty() const;
        void printTree( ostream & out = cout ) const;

        void makeEmpty();
        void insert( const Comparable & x ) {
            insert( x , root );
        }
        void insert( Comparable && x );
        void remove( const Comparable & x ) {
            remove (x , root );
        }

        BinarySearchTree & operator= ( const BinarySearchTree &rhs );
        BinarySearchTree & operator= ( BinarySearchTree && rhs );
};

int main(void){
    return 0;
}
