
  #include "StudentRecordLiterature.h"

  using namespace std;
  
  StudentRecordLiterature::StudentRecordLiterature(){};
  StudentRecordLiterature::~StudentRecordLiterature(){};
  
  void StudentRecordLiterature::print(ostream & out) const {
    out << "Score : " << lastname_ << "," << firstname_ << "," << "analytic score(out of 40%): "<< scores_[0] << ", creative score(out of 40%): " << scores_[1] << ", commentary score(out of 20%): " << scores_[2] << ", Total: " << score() <<endl;
  }
  
  
  
  bool StudentRecordLiterature::input(istream & in ) {
    double analytic=0;
    double creative=0;
    double commentary=0;
    string line;
    getline( in, line, ',');
    lastname_=line;
    getline(in,line,',');
    firstname_=line;
    getline(in,line,',');
    scores_.push_back(atof( line.c_str())*0.4);
    getline(in,line,',');
    scores_.push_back(atof( line.c_str())*0.4);
    getline(in,line);
    scores_.push_back(atof( line.c_str())*0.2);
    if ( line== "")
      return false;
    else {
      compute_score();
  
      return true;
    }
  }