  #ifndef StudentRecordHistory_h
  #define StudentRecordHistory_h
  
  #include "StudentRecord.h"
  using namespace std;
  
  class StudentRecordHistory : public StudentRecord {
    
   public:
    
  
    StudentRecordHistory();
    ~StudentRecordHistory();
    
    
    virtual void print( ostream & out = std::cout) const;
    virtual bool input(istream & in);
  };
  #endif