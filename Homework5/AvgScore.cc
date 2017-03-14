  #include <iostream>
  #include <fstream>
  #include <string>
  #include <vector>
  #include <cstdlib>
  #include <memory>
  #include "StudentRecord.h"
  #include "StudentRecordPhysics.h"
  #include "StudentRecordLiterature.h"
  #include "StudentRecordHistory.h"
  

  using namespace std;
  
  bool insert(istream &)
  {
      string Class;
      string line;
      getline( in,line,',');
      Class = line;
      if (Class == "Physics") {
        shared_ptr<StudentRecord> phy (new StudentRecordPhysics);
        phy->input(in);
        phy->print();
        Records_Physics.push_back(phy);
        return true; }
      else if (Class == "History") {
      shared_ptr<StudentRecord> his (new StudentRecordHistory);
        his->input(in);
        his->print();
        Records_History.push_back(his);
        return true; }
      else if (Class == "Literature") {
       shared_ptr<StudentRecord> lit (new StudentRecordLiterature);
        lit->input(in);
        lit->print();
        Records_Literature.push_back(lit);
        return true; }
        
      else {
        return false;
      }
  }
  
  
  
  vector<shared_ptr<StudentRecord> > Records_Physics, Records_History, Records_Literature;
  
  
  
 
  
  int main(int argc, char ** argv) {
    
   
    ifstream in(argv[1]);
    while(insert(in))
      insert(in); 
    
   
     double Physics_average=0.;
     double History_average=0.;
     double Literature_average=0.;
  

  
     for(int i=0;i<(Records_Physics.size());i  ){
       Physics_average  = Records_Physics.at(i)->score();   
     }
     Physics_average /=Records_Physics.size();
     for(int i=0;i<(Records_History.size());i  ){
     History_average  = Records_History.at(i)->score();   
     }
     History_average /= Records_History.size();
      for(int i=0;i<(Records_Literature.size());i  ){
       Literature_average  = Records_Literature.at(i)->score();   
       }
      Literature_average /= Records_Literature.size();
  
      
   
  
  cout << "Avg score for the Physics class is  " << Physics_average << endl;
  cout << "Avg score for the History class is" << History_average << endl;
  cout << "Avg score for the Literature class is" << Literature_average << endl;
    return 0;
  }
  
