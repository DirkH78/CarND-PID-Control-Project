#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double MaxIn) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  ITerm = 0;
  Max = MaxIn;
}

void PID::UpdateError(double cte) {
  d_error = cte - d_error;
  p_error = cte;
  i_error += cte;
  if(i_error > Max) i_error = Max;
  else if(i_error < (-Max)) i_error = (-Max);
  // DEBUG
  //std::cout << "p_error: " << p_error << " i_error: " << i_error << " d_error: " << d_error << std::endl;
}

double PID::TotalError() {
  double total_error = (Kp * p_error + Ki * i_error + Kd * d_error);
  //if(total_error > Max) total_error = Max;
  //else if(total_error < (-Max)) total_error = (-Max);
  std::cout << "p_Term: " << Kp * p_error << " i_Term: " << Ki * i_error << " d_Term: " << Kd * d_error << " TotalError: " << total_error << std::endl;
  return total_error;
}

