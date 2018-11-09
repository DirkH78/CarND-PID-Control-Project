#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double MaxIn) {
  // initiate controller parameters
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  // set initial errors to zero
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  // initiate I-maximum
  Max = MaxIn;
}

void PID::UpdateError(double cte) {
  // update error parts
  d_error = cte - d_error;
  p_error = cte;
  i_error += cte;
  // limit I-error
  if(i_error > Max) i_error = Max;
  else if(i_error < (-Max)) i_error = (-Max);
  // DEBUG
  //std::cout << "p_error: " << p_error << " i_error: " << i_error << " d_error: " << d_error << std::endl;
}

double PID::TotalError() {
  // calculate controller output
  double total_error = (Kp * p_error + Ki * i_error + Kd * d_error);
  std::cout << "p_Term: " << Kp * p_error << " i_Term: " << Ki * i_error << " d_Term: " << Kd * d_error << " TotalError: " << total_error << std::endl;
  return total_error;
}

