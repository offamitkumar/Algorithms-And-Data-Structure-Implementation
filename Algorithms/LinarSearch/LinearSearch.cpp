#include <algorithm>

/**
 *  Time Complexity : O(N)
 *  Space Complexity :  O(1)
 **/

template<class InputIterator , class T>
InputIterator linearSearch( InputIterator start , InputIterator end , const T& value ) {
    while( start != end ) {
        if( *start == value )
            return start;
        ++start;
    }
    return end;
}
