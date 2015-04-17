// Purpose.  Composite design pattern - multiple container classes

#include <iostream>
#include <vector>
using namespace std;

class Component { public: virtual void traverse() = 0; };

class Primitive : public Component {
   int value;
public:
   Primitive( int val ) { value = val; }
   void traverse()      { cout << value << "  "; }
};

class Composite : public Component {
   vector<Component*> children;
   int                value;
public:
   Composite( int val )     { value = val; }
   void add( Component* c ) { children.push_back( c ); }
   void traverse() {
      cout << value << "  ";
      for (int i=0; i < children.size(); i++)
          children[i]->traverse();
}  };

class Row : public Composite { public:     // Two different kinds of "con-
   Row( int val ) : Composite( val ) { }   // tainer" classes.  Most of the
   void traverse() {                       // "meat" is in the Composite
      cout << "Row";                       // base class.
      Composite::traverse();
}  };

class Column : public Composite { public:
   Column( int val ) : Composite( val ) { }
   void traverse() {
      cout << "Col";
      Composite::traverse();
}  };

int main( void ) {
      Row    first( 1 );                     // Row1
      Column second( 2 );                    //   |
      Column third( 3 );                     //   +-- Col2
      Row    fourth( 4 );                    //   |     |
      Row    fifth( 5 );                     //   |     +-- 7
      first.add( &second );                  //   +-- Col3
      first.add( &third  );                  //   |     |
      third.add( &fourth );                  //   |     +-- Row4
      third.add( &fifth  );                  //   |     |     |
      first.add(  new Primitive( 6 ) );         //   |     |     +-- 9
      second.add( new Primitive( 7 ) );         //   |     +-- Row5
      third.add(  new Primitive( 8 ) );         //   |     |     |
      fourth.add( new Primitive( 9 ) );         //   |     |     +-- 10
      fifth.add(  new Primitive(10 ) );         //   |     +-- 8
      first.traverse();  cout << '\n';       //   +-- 6
}

// Row1  Col2  7  Col3  Row4  9  Row5  10  8  6


