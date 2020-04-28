#include <algorithm>

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

        explicit Vector( int initSize , int defaultValue): theSize{ initSize } , theCapacity{ initSize + SPARE_CAPACITY }{
            Object *tempArray = new Object[ theCapacity ];
            for(int i=0; i < theSize; ++i){
                tempArray[ i ] = defaultValue;
            }
            std::swap(objects , tempArray);
        }

        // copy constructor 
        Vector( Vector & rhs ):theSize{ rhs.theSize } , theCapacity{ rhs.theCapacity } , objects{ nullptr }{
            objects = new Object[ theCapacity ];
            // Never assign values in assignment list , as it will do a deep copy 
            for( int i{ 0 }; i < theSize; ++i ){
                objects[ i ] = rhs.objects[ i ]; // shallow copy 
            }
        }

        // operator = 
        Vector &operator= ( Vector &rhs ) {
            Vector<Object> copy = rhs;  // calling the copy constructor 
            std::swap( *this , copy );
            return *this;

        }


        // destructor 
        ~Vector() {
            delete []objects;
        }

        // copy constructor 
        Vector ( Vector && rhs ): theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity } , objects{ rhs.objects }{
            // We can do deep copy here as it is r-value reference 
            rhs.objects = nullptr;
            rhs.theSize = 0;
            rhs.theCapacity = 0;
        }


        // operator =  // for r-value reference 
        Vector &operator= ( Vector &&rhs ) {
            std::swap( theSize , rhs.theSize );
            std::swap( theCapacity, rhs.theCapacity );
            std::swap( objects , rhs.objects );
            return *this;

        }

        
        void resize( int newSize ) {
            if( newSize > theCapacity ) {
                reserve( newSize * 2 ); // vector always double the memory storage 
            }
            theSize = newSize;
        }


        void assign( int newSize , int defaultValue=0 ) {
            if(newSize > theCapacity){
                reserve(newSize*2 , true);
            }
            for(int i{0}; i < newSize; ++i){
                objects[i] = defaultValue;
            }
        }

        void reserve( int newCapacity ,bool isDefaultValueGiven = false) {
            if( newCapacity < theSize ) {
                return ;
            }

            Object *newArray = new Object[ newCapacity ]; 
            theCapacity = newCapacity;
            std::swap( objects , newArray ); // now object have a different size 

            if(isDefaultValueGiven==false){
                for( int i{0}; i < theSize; ++i ) {
                    newArray[ i ] =  std::move( objects[ i ] );
                }
            }

            delete []newArray; // delete the temporary array which is storing the values from previous stage

        }

        Object& operator[] (int index ) {
            return objects[ index ];
        }

        const Object& operator[] (int index ) const {
            return objects[ index ];
        }

        bool empty( void  ) const {
            return size() == 0;
        }


        bool size( void ) const {
            return theSize;
        }

        void push_back(const Object &x ) {
            if( theSize == theCapacity ) {
                reserve( 2 * theCapacity + 1 );
            }
            objects[ theSize++ ] = x;
        }

        void push_back( const Object &&x ) {
            if( theSize == theCapacity ) {
                reserve( 2 * theCapacity +1 );
            }
            objects[ theSize++ ] = std::move( x );
        }

        void pop_back( void ) {
            theSize--;
        }

        const Object & back( void  ) const {
            return objects[ theSize - 1 ];
        }

        typedef Object* iterator;

        typedef const Object* const_iterator;

        iterator begin( ) {
            return &objects[ 0 ];
        }

        const_iterator begin( ) const {
            return &objects[ 0 ];
        }

        iterator end( ) {
            return &objects[ size() ];
        } 

        const_iterator end( ) const {
            return &objects[ size() ];
        }
};

int main(int argc , char* argv[]){
    return 0;
}
