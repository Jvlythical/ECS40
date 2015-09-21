// Proxy class Interface definition.

class Implementation; // forward class declaration required by line 15

class Interface 
{
public:
   Interface( int ); 
   void setValue( int );
   int getValue() const;
   ~Interface();

private:
   // requires previous forward declaration on line 3
   Implementation *ptr;   
};
