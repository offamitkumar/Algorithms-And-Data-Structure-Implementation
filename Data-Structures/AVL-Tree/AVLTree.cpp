#include <bits/stdc++.h>
using namespace std;

class AvlTree{
    private:

        static int const ALLOWED_IMBALANCE = 1;

        struct AvlNode{

            Comparable  element;
            AvlNode     *left;
            AvlNode     *right;
            int         height; 

            AvlNode( const Comparable & ele , AvlNode * lt , AvlNode * rt , int h = 0 )
                : element{ ele } , left{ lt } , right{ rt } , height{ h } { }

            AvlNode( const Comparable && ele , AvlNode * lt , AvlNode * rt , int h = 0 ) 
                : element{ move( ele ) } , left{ lt  } , right{ rt } , height{ h } {}
        };




    public:


        /*
         *   return height of AVL Tree , -1 if nullptr
         */
        int height( AvlNode *t ) const {


            return ( t == nullptr ) ? -1 : t -> height;

        }
};


int main(void){
    return 0;
}
