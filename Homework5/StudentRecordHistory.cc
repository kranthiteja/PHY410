 #include "StudentRecordHistory.h"
 using namespace std;

 StudentRecordHistory::StudentRecordHistory(){};
 StudentRecordHistory::~StudentRecordHistory(){};
 
void StudentRecordHistory::print( ostream & out ) const  {
   out << "Score: " << lastname_ << "," << firstname_ << ", exam1 score: "<< scores_[0] << ", exam2 score: " << scores_[1] << ", Total: " << score() << endl;
 }
 
 
 bool StudentRecordHistory::input(istream & in ) {
    double temp1 = 0.0;
    double temp2 = 0.0;
    string line;
    getline(in,line,',');
      lastname_=line;
      getline(in,line,',');
      firstname_=line;
      getline(in,line,',');
      e1 = atof( line.c_str() );
      getline( in, line);
      temp2 = atof( line.c_str() );
      if (temp1 >= temp2) {
        temp1=.6*temp1;
        temp2=.4*temp2; }
      else {
        temp2=.6*temp2;
        temp1=.4*temp1;}
      scores_.push_back(temp1);
      scores_.push_back(temp2);
      if( line == "")
        return false;
      else {
        compute_score();
  
        return true;
      }
  }