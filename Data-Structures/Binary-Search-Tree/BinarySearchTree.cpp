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
                insert ( move( x ) , t -> right );

            else
                ; // element repeated ; do nothing 
        }

        void remove( const Comparable & x, BinaryNode * & t ) {
            
            if ( t == nullptr ) {
                return ; // item not found ; do nothing
            }
            
            if( isLessThan( x , t -> left )) {

                remove (x , t -> left);

            } else if( isLessThan( t->left , x ) ) {

                remove ( x , t -> right );

            } else if( t -> left != nullptr and t -> right != nullptr  ) {

                t -> element = findMin( t -> right ) -> element; // we will set the min node here

                remove ( t -> element , t -> right ); // now delete the min node 

            } else {

                BinaryNode *oldNode = t;

                t = (t -> left != nullptr ) ? t -> left : t ->right ;

                delete oldNode;

            }
        }
        
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
        
        void makeEmpty( BinaryNode * & t) {

            if( t != nullptr ) {

                makeEmpty( t -> left );

                makeEmpty( t -> right );

                delete t;

            }

            t = nullptr;
        }

        void printTree( BinaryNode *t , ostream & out = cout ) const {
            if( t == nullptr ) {
                return ;
            }
            std::cout << t -> element << ' ';
            if( t -> left != nullptr ) {
                printTree( t -> left );
            }else if ( t -> right != nullptr ) {
                printTree( t -> right );
            }
        }

        BinaryNode * clone( BinaryNode *t ) const {

            if( t == nullptr ) {

                return nullptr;

            } else {

                return new BinaryNode{ t -> element , clone( t-> left ) , clone( t -> right ) };

            }
        }
            
    public:

        BinarySearchTree() = default;
        BinarySearchTree( const BinarySearchTree &rhs ) : root { nullptr } {
            root = clone ( rhs.root );
        }
        BinarySearchTree( BinarySearchTree && rhs ) = default;
        ~BinarySearchTree( ) {
            makeEmpty( );
        }

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

        bool isEmpty() const {
            return root == nullptr;
        }

        void printTree( ostream & out = cout ) const {
            printTree( root );
        }

        void makeEmpty(){
            makeEmpty( root );
        }

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
