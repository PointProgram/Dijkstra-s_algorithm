#include <iostream>
#include <vector>
#include <cstddef> //std::site_t
#include <algorithm> // std::copy

using std::cout;
using std::endl;
using std::size_t;


class dumb_array {
public:

    // (default) constructor
    dumb_array(size_t size = 0)
        : mSize(size),
          mArray(mSize ? new int[mSize]() : nullptr)
          {
          }

    dumb_array(const dumb_array& other)
        : mSize(other.mSize),
          mArray(mSize ? new int[mSize] : nullptr)
          {
              std::copy(other.mArray, other.mArray + mSize, mArray);
          }

    //naive implementaion
    //dumb_array& operator=(const dumb_array& other) {
        //self-assignemnts test to prevent from running needless code
        //prevent from subtel bugs - delete and copy the same array
        //In other cases, it is rather a waste of time
        //if (this != &other) {
            //get rid of the old data...
            
            //The second is that it only provides a basic exception guarantee. 
            //If new int[mSize] fails, *this will have been modified. 
            //(Namely, the size is wrong and the data is gone!)
            /*delete [] mArray;
            mArray = nullptr;

            mSize = other.mSize;
            mArray = mSize ? new int[mSize] : nullptr;

            std::copy(other.mArray, other.mArray + mSize, mArray);
            */
            
            //code duplication problem
            /*
            //get the new data before we replace the old
            size_t newSize = other.mSize;
            int * newArray = newSize ? new int[newSize]() : nullptr;
            std::copy(other.mArray, other.mArray + newSize, newArray);

            //replace the old data (all are non-throwing)
            delete [] mArray;
            mSize = newSize;
            mArray = newArray; */
        //}

    dumb_array& operator=(dumb_array other) {
        swap(*this, other);
        //swap(other);
        return *this;
    }

    friend void swap(dumb_array& first, dumb_array& second) {
        using std::swap;

        swap(first.mSize, second.mSize);
        swap(first.mArray, second.mArray);
    }

    ~dumb_array() {
        delete [] mArray;
    }


private:
    size_t mSize;
    int *mArray;
};

std::ostream& operator<<(std::ostream& os, const Node& obj)
{
  // write obj to stream

  return os;
}

std::istream& operator>>(std::istream& is, Node& obj)
{
  // read obj from stream

  //if( /* no valid object of T found in stream */ )
    is.setstate(std::ios::failbit);

  return is;
}

class Node {
public:
    double getx() { return x; };
    void setx(double v) {x = v;}

    Node operator+ (const Node& n) {
        Node node_copy;
        node_copy.x = this->x + n.x;
        node_copy.y = this->y + n.y;
        return node_copy;
    }


private:
    double x, y;

};




int main() {

    cout << "Hello World" << endl;
    return 0;
}