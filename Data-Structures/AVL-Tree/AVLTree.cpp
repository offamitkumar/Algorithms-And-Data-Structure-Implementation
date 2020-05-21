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
        
        void balance( AvlNode * &t ) {
            if( t == nullptr ){
                return ;
            }

            if(height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE){
                if( height( t-> left -> left ) >= height( t-> left -> right ) ) {
                    rotateWithLeftChild( t );
                }else{
                    doubleWithLeftChild( t );
                }
            }else if( height( t->right ) - height( t-left ) > ALLOWED_IMBALANCE ){
                if(height( t->right->right ) >= height( t->right -> left )){
                    rotateWithRightChild( t );
                }else{
                    doubleWithRightChild( t );
                }
            }
            t ->height = max( height( t->left ) , height( t->right ) ) + 1;
        }

        AvlNode* findMin( AvlNode *t ) const{
            if(t == nullptr){
                return nullptr;
            }
            if(t->left == nullptr){
                return t;
            }else{
                return findMin(t->left);
            }
        }

        AvlNode* findMax( AvlNode*t ) const{
            if(t == nullptr){
                return nullptr;
            }
            if(t->right == nullptr){
                return t;
            }else{
                return findMax(t -> right);
            }
        }

        bool contains( const Comparable& x , AvlNode *t ) const{
            if(t == nullptr){
                return false;
            }else if( x <  t -> element){
                return contains( x , t -> left );
            }else if( t->element < x ){
                return contains( x , t -> right );
            }else
                return true;
        }
        
        void makeEmpty(AvlNode* &t){
            if( t != nullptr ){
                makeEmpty( t->left );
                makeEmpty( t->right );
                delete t;
            }
            t = nullptr;
        }

        void printTree( AvlNode* t ) const {
            if( t != nullptr ){
                printTree( t->left );
                cout<< t -> element << '\n'; 
                printTree( t->right );
            }
        }

        AvlNode *clone( AvlNode*t ) const {
            if(t == nullptr){
                return nullptr;
            }else{
                return new AvlNode{ t->element , clone( t->left ) , clone(t->right) , t->height };
            }
        }

        int height( AvlNode *t ) const {
            return t == nullptr ? -1 : t->height;
        }

        int max( int lhs , int rhs ) const {
            return lhs > rhs ? lhs : rhs;
        }

        void rotateWithLeftChild( AvlNode *& k2 ){
            AvlNode* k1 = k2 -> left;
            k2 -> left = k1 ->right;
            k1 -> right = k2; 
            k2 -> height = max( height( k2->left ) , height(k2->right) )+1;
            k1 -> height = max( height( k1->left ) , k2 -> height )+1;
            k2 = k1;
        }

        void rotateWithRightChild( AvlNode* &k1 ) {
            AvlNode*k2 = k1 -> right;
            k1 -> right = k2 -> left;
            k2 -> left = k1;
            k1 -> height = max( height(k1->left) , height(k1->right) )+1;
            k2 -> height = max( height(k2->right) , k1->height ) +1;
            k1 = k2;
        }

        void doubleWithLeftChild(AvlNode* &k3){
            rotateWithRightChild(k3 -> left);
            rotateWithLeftChild(k3 -> right);
        }

        void doubleWithRightChild( AvlNode*& k1 ){
            rotateWithLeftChild(k1->right);
            rotateWithRightChild(k1);
        }

};
