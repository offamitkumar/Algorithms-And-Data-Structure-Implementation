#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace std;

// CONSTRUCTION: zero parameter
//
// ******************OPERATIONS SUPPORTED*********************
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

template<typename Comparable>
class AvlTree{
    public:
        AvlTree( ) : root { nullptr } 
        { }
        
        AvlTree( AvlTree && rhs ) : root{ rhs.root } {
            rhs.root = nullptr; // whenever this object is going deleted
            // we don't want our newly created object to affected 
        }

        ~AvlTree( ) {
            makeEmpty ( ); 
        }
        /**
         * Make a Deep Copy 
         **/
        AvlTree &operator=( const AvlTree & rhs ) {
            AvlTree copy = rhs;
            std::swap( *this , copy );
            return *this;
        }
        
        /**
         * Move
         **/
        AvlTree &operator=( AvlTree && rhs ) { 
            std::swap(root , rhs.root);
        }
         
        /**
         * find smallest item in the tree.
         * return INT_MAX if tree is empty.
         **/
        const Comparable & findMind( ) const {
            if( isEmpty() ) 
                throw length_error{"Underflow: Tree is Empty"};
            return findMin( root  ) -> element;
        }
        
        const Comparable & findMax( ) const {
            if( isEmpty() )
                throw length_error{"Underflow: Tree is Empty"};
            return findMax( root ) -> element;
        }

        /**
         * Return True if x is found in the tree.
         **/
        bool contains( const Comparable &x ) const {
            return contains( x, root );
        }

        
        /**
         * Return true if empty , false otherwise
         **/
        bool isEmpty( ) const {
            return root == nullptr;
        }

        /**
         * Print tree contents in sorted Order
         **/
        void printTree( ) const {
            if( isEmpty() ) 
                cout<<"Tree is Empty!" <<'\n';
            else
                printTree(root);
        }
        
        /**
         * Make Tree Empty 
         **/
        void makeEmpty() {
            makeEmpty( root ); 
        }

        /**
         * Insert x into the tree
         * Duplicated are ignored
         **/
        void insert( const Comparable &x ) {
            insert( x, root );
        }

        void insert( Comparable && x ) {
            insert( std::move( x ), root );
        }

        /**
         * Remove x from the tree
         * No change will be made if the tree is already empty
         **/
        void remove( const Comparable & x ) {
            remove( x, root ); 
        }
        
        void remove( const Comparable && x ) {
            remove( std::move( x ) , root );
        }

    private:

        static const int ALLOWED_IMBALANCE = 1;

        struct AvlNode{
            Comparable element;
            AvlNode *leftNode;
            AvlNode *rightNode;
            int height;

            AvlNode( const Comparable& element , AvlNode* leftTree , AvlNode *rightTree , int h = 0 ) 
                : element{ element } , leftNode{ leftTree } , rightNode{ rightTree } , height{ h } { }

            AvlNode( Comparable&& element , AvlNode* leftTree , AvlNode *rightTree , int h = 0 ) 
                : element{ element } , leftNode{ leftTree } , rightNode{ rightTree } , height{ h } { }
        };

        AvlNode *root;

        void insert( const Comparable &x , AvlNode* &t ) {
            if( t == nullptr )
                t = new AvlNode{ x , nullptr , nullptr  };
            else if( x < t -> element )
                insert( x , t -> left );
            else if( t -> element < x )
                insert( x , t -> right );
            
            balance( t );
        }


        void insert( Comparable &&x , AvlNode* &t ) {
            if( t == nullptr )
                t = new AvlNode{ std::move( x ) , nullptr , nullptr  };
            else if( x < t -> element )
                insert( std::move( x ) , t -> left );
            else if( t -> element < x )
                insert( std::move( x ) , t -> right );
            
            balance( t );
        }

        void remove( const Comparable& x , AvlNode * &t ) {
            if( t == nullptr ) 
                return ;
            else if ( x < t -> element )
                remove( x , t ->right );
            else if ( x > t -> element ) 
                remove( x , t -> left );
            else if ( t->left != nullptr and t ->right != nullptr ){ // current node have 2 children
                t -> element = findMin( t->right ) ->element;
                remove( t->element , t->right );
            }else{
                AvlNode* oldNode = t;
                t = (t ->left != nullptr)?t->left : t->right;
                delete oldNode;
            }
        }
};
