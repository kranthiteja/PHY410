#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "nonlin.hpp"
#include "diffeq.hpp"

using namespace std;
using namespace cpt;

//setting up unnessacary Lorenz function just to follow as is done for the
// pendulum
class LorenzFunction {
public : 
  LorenzFunction( double sigma = 10., double rho = 28., double beta = 2.66667 ) :
    s(sigma), q( rho ),b(beta)
  {
  }
  
  protected : 
  double s;                //sigma       
  double q;                //rho
  double b;                //beta     
  
};


//setting up the lorenzdiffeq class where the Lorenz model is stored
class LorenzDiffEq : LorenzFunction {
public : 
  //setting the defualts for our equation for our HW settings
  LorenzDiffEq( double sigma = 10, double rho = 28, double beta = 2.66667 ) : 
    LorenzFunction( sigma, rho, beta) {}
  
  //Creating our Diff equation matrix

  Matrix<double,1> operator()( Matrix<double,1> const & p) const {
    double x = p[1], y = p[2], z = p[3], t=p[0];
    
      Matrix<double,1> out(4);
      out[0] = 1;
      out[1] = s*(y-x);
      out[2] = x*(q-z)-y;
      out[3] = x*y-b*z;
   
    return out;
  }
};

//starting the main function

int main() {
  //declaring all our variables off the back
  double rho = 28.;
  double sigma = 10.;
  double beta = 8./3.;

  //should give us the lorenz model
  LorenzDiffEq lorenzDiffEq(sigma, rho,beta);

  //Setting initial time step and dt's for adaptive method
  double tau = 0.1;
  double tau2 = 0.1;
  double dt_min = tau;
  double dt_max = tau;
  double dt_min2 = tau2;
  double dt_max2 = tau2;

  //setting up number of steps we want to take and our accuracy
  int nStep = 1000;
  double accuracy = 1e-6;
  //allowing user to select which numerical method they would like to use, right now no matter what you choose you get RK4
  cout<< "Choose a numerical method: RK4 (1), or ARK4(2):";
  int method; cin >> method;

  //allow user to pick intial x, y, and z
  cout << "choose first initial x value" << endl;
  double x; cin >> x;
  cout << "choose first initial y value" << endl;
  double y; cin >> y;
  cout << "choose first initial z value" << endl;
  double z; cin >> z;
   //allow user to pick intial x, y, and z
  cout << "choose second initial x value" << endl;
  double x2; cin >> x2;
  cout << "choose second initial y value" << endl;
  double y2; cin >> y2;
  cout << "choose second initial z value" << endl;
  double z2; cin >> z2;
  double time = 0;
  double time_old;
  

  // setting up our position vector, with initial components 
  Matrix<double,1> xv(4);
  Matrix<double,1> xv2(4);
  
 xv[0] = time;
 xv[1] = x;
 xv[2] = y;
 xv[3] = z;
 
 xv2[0] = time;
 xv2[1] = x2;
 xv2[2] = y2;
 xv2[3] = z2;
 
 //Setting up the plotting vectors
 std::vector<double> t_plot;
 std::vector<double> x_plot;
 std::vector<double> y_plot;
 std::vector<double> z_plot;

 //Time to start the main solving of our question
 for(int iStep=0; iStep<nStep; iStep++ ) {  



   // record all data points for our vectors
   t_plot.push_back((xv2[0]+xv[0])/2);
   x_plot.push_back(xv[1]-xv2[1] );
   y_plot.push_back(xv[2]-xv2[2] );  
   z_plot.push_back(xv[3]-xv2[3] );
   //method testing
   if( method == 1 ) {
     cpt::RK4_step( xv, tau, lorenzDiffEq );
     cpt::RK4_step( xv2, tau, lorenzDiffEq); 
   } else if ( method == 2) {
     
     tau = cpt::RK4_adaptive_step(xv, tau, lorenzDiffEq, accuracy);
     dt_min = min(tau, dt_min);
     dt_max = max(tau, dt_max);
     tau2 = cpt::RK4_adaptive_step(xv2, tau, lorenzDiffEq, accuracy);
     dt_min2 = min(tau2, dt_min2);
     dt_max2 = max(tau2, dt_max2);
     
   }
  
    
   
 }
   ofstream plotOut("butterflydifference_plot.txt");
    for( int i=0; i< x_plot.size(); i++ ) {
      plotOut <<t_plot[i] << " " <<  x_plot[i] << " "  << y_plot[i] << " " << z_plot[i] << endl;
    }
    plotOut.close();

    
  return 0;
}
