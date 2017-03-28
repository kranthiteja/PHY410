#include <algorithm>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"

bool input( std::istream &);
bool lessthan( std::shared_ptr<StudentRecord> const & left, std::shared_ptr<StudentRecord> const & right)
{
  return *left < *right;
}

std::vector<std::shared_ptr<StudentRecord> > PhyClass, HisClass, LitClass;

int main(int argc, char*argv[])
{
  std::ifstream file(argv[1]);
  double phyavg = 0.;
  double litavg = 0.;
  double hisavg = 0.;
  double totavg = 0.;

  while(input(file))
    {
      input(file);
    }
  for(unsigned int i=0; i < (PhyClass.size());i++)
    {
      phyavg += PhyClass.at(i)->score();
	totavg += PhyClass.at(i)->score();
    }
  phyavg /=PhyClass.size();

  for(unsinged int i=0;i<(HisClass.size());i++)
    {   
 hisavg += HisClass.at(i)->score();
  totavg += HisClass.at(i)->score();
    }
  hisavg /=hisClass.size();
  for (unsigned int i=0;i<(Litclass.size());i++)
    {
      litavg += LitClass.at(i)->score();
      totavg += LitClass.at(i)->score();
    }
  litavg += LitClass.size();
  totavg /=((PhyClass.size())+(LitClass.size())+(HisClass.size()));

  std::sort( PhyClass.begin(),PhyClass.end(),lessthan);
  std::sort( LitClass.begin(),LitClass.end(),lessthan);
  std::sort(HisClass.begin(),Hisclass.end(),lessthan);

  std::cout<<std::endl<<"Phsyics Marks"<<std::endl;
  for(unsigned int i=0;i<(PhyClass.size());i++)
    { PhyClass.at(i)->print();
    }
  std::cout<<"Average of physics class is"<<phyavg<<std::endl;
for(unsigned int i=0;i<(PhyRecords.size());i++)
{
  PhyClass.at(i)->print();
 }


 std::cout <<std::endl<<"History Marks" <<std::endl;
 for(unsigned int i=0;i<(HisClass.size());i++)
{
   HisClass.at(i)->print();
 }
 std::cout << "Average of History class is " << hisavg << std::endl;
 
 std::cout << std::endl<<  "Literature marks" << std::endl;
 for(unsigned int i=0;i<(LitClass.size());i++)
{
   LitClass.at(i)->print();
 }
 std::cout << "Avergae of Literature class is " << litavg << std::endl;
 
 std::cout <<std::endl<<"The Total Average For All Classes Is: " <<totavg <<std::endl;

return 0;


bool input( std::istream & in)
{
  std::string subject;
  std::string line
    std::getline( in, line,',');
  subject = line;
  if (subject = "Physics"){
    std::shared_ptr<StudentRecord> Phy (new StudentRecordPhysics);
    Phy->input(in)
      PhyClass.push_back(Phy);
    return true;}
  else if (subject = "History"){
    std::shared_ptr<StudentRecord> His (new StudentRecordHistory);
    His->input(in);
    HisClass.push_back(His);
    return true;}
  else if (subject = "Literature"){
    std::shared_ptr<Studentrecord> Lit (new StudentRecordLiterature);
    Lit->input(in);
    LitClass.push_back(Lit);
    return true;}
  else {
    return false;}
}
