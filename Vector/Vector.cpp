#include <algorithm>
using namespace std;
template<typename Object> 
class Vector{
    private:
        int theSize;
        int theCapacity;
        Object * objects;

    public:

        static const int SPARE_CAPACITY = 16;

        // constructor 
        explicit Vector( int initSize = 0 ): theSize{ initSize } , theCapacity{ initSize + SPARE_CAPACITY }{
            objects = new Object[ theCapacity ];
        }

        // constructor 
        Vector( Vector & rhs ):theSize{ rhs.theSize } , theCapacity{ rhs.theCapacity } , objects{ nullptr }{
            objects = new Object[ theCapacity ];
            for( int i{ 0 }; i < theSize; ++i ){
                objects[ i ] = rhs.objects[ i ];
            }
        }

        // operator = 
        Vector &operator= ( const Vector &rhs ) {
            Vector copy = rhs;
            std::swap( *this , copy );
            return *this;
        }


        // destructor 
        ~Vector() {
            delete []objects;
        }
};


/***********************main function*********************************/
int main(void){
    return 0;
}
