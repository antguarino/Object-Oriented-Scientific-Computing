#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>

// Include Agregate Header File - physics.h
#include "physics.h"

using namespace std;

int main() {
  double time = 10;
  physics::Projectile p(10, 60, 0);  // Create Projectile
  cout << "For a projectile with the properties: " << endl;
  cout << "Initial Velocity = " << p.InitialVelocity() << " [m/s]"
       << endl;  // Print The Initial Velocity for p
  cout << "Launch Angle = " << p.LaunchAngle() * (180/std::numbers::pi) << " [deg]"
       << endl;  // Print The Launch Angle for p
  cout << "Initial Height = " << p.InitialHeight() << " [m]"
       << endl;  // Print The Initial Height for p
  cout << endl;
  cout << "Velocity at " << time << " [s] is " << p.Velocity(time)
       << " [m/s] (in open space)"
       << endl;  // Print The Velocity at a given time
  cout << "Horizontal displacement at " << time << " [s] is "
       << p.HorizontalDisplacement(time) << " [m] (in open space)"
       << endl;  // Print The Horizontal Displacement at a given time
  cout << "Vertical displacement at " << time << " [s] is "
       << p.VerticalDisplacement(time) << " [m] (in open space)"
       << endl;  // Print The Vertical Displacement at a given time
  cout << "Displacement Magnitude at " << time << " [s] is "
       << p.Displacement(time) << " [m] (in open space)"
       << endl;  // Print The Displacement Magnitude at a given time
  cout << endl;
  cout << "Time of Flight is " << p.TimeOfFlight(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Time of Flight
  cout << "Maximum Height is " << p.MaximumHeight(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Maximum Height
  cout << "Maximum Distance is " << p.HorizontalDistance(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Max Horizontal Distance
  cout << endl;

  p.InitialHeight(2);  // Set new Initial Height
  cout << "Using the modified projectile properties: " << endl;
  cout << "Initial height = " << p.InitialHeight() << " [m]"
       << endl;  // Print New Initial Height
  cout << endl;
  cout << "Time of Flight is " << p.TimeOfFlight(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Time of Flight
  cout << "Maximum Height is " << p.MaximumHeight(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Maximum Height
  cout << "Maximum Distance is " << p.HorizontalDistance(time)
       << " with y0 = " << p.InitialHeight()
       << endl;  // Print The Max Horizontal Distance
}