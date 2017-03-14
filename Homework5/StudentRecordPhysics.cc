  #include "StudentRecordPhysics.h"
  
  using namespace std; 

  StudentRecordPhysics::StudentRecordPhysics() {};
  StudentRecordPhysics::~StudentRecordPhysics() {};
  
  void StudentRecordPhysics::print( ostream & out ) const{
    out << "Score : " << lastname_ << "," << firstname_ << ", Homework score: " << scores_[0] << ", Lab score: " << scores_[1] << ", Total: " << score() << endl;
  }
  
  
  
  bool StudentRecordPhysics::input( istream & in )  {
    double homework = 0.0;
    double lab = 0.0;
    
    string line;
    getline( in,line, ',');
    lastname_=line;
    getline( in,line, ',');
    firstname_=line;
    getline(in,line,',');
    scores_.push_back(atof( line.c_str())*0.8);
    getline(in,line);
    scores_.push_back(atof(line.c_str())*0.2);
    if (line == "")
      return false;
    else{
      compute_score();
      return true;
    }
  }
