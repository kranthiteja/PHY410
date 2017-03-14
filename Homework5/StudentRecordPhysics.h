
  #ifndef StudentRecordPhyscis_h
  #define StudentRecordPhysics_h
  
  #include "StudentRecord.h"
  using namespace std;
  
  class StudentRecordPhysics : public StudentRecord {
  
    
  
   public:
    
    StudentRecordPhysics();
    ~StudentRecordPhysics();
    virtual void print( ostream & out = cout ) const;
  
    virtual bool input(istream & in );
  };
  #endif