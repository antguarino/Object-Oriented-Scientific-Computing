#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>

// Include Agregate Header File - physics.h
#include "physics.h"

using namespace std;

namespace physics {
// Projector Constructors
// Blank Constructor
Projectile::Projectile() {
  Projectile::InitialVelocity(0);
  Projectile::LaunchAngle(0);
  Projectile::InitialHeight(0);
}
// Constructor with inputs for Initial Velocity, Launch Angle, and Initial
// Height
Projectile::Projectile(const double& initial_velocity,
                       const double& launch_angle,
                       const double& initial_height) {
  Projectile::InitialVelocity(initial_velocity);
  Projectile::LaunchAngle(
      launch_angle);  // Launch Angle in converted from degrees to radians
  Projectile::InitialHeight(initial_height);
}
// Member Function to Calculate Velocity at a given time.
const double Projectile::Velocity(const double& time) const {
  // Instantiate Variable for Gravity
  const double kGravity = 9.80665;  // meters per second squared
  double velocity_x = Projectile::InitialVelocity() * cos(LaunchAngle());
  double velocity_y =
      Projectile::InitialVelocity() * sin(LaunchAngle()) - kGravity * time;
  return sqrt(velocity_x * velocity_x + velocity_y * velocity_y);
}

// Member Function to Calculate the Horizontal Displacement at a given time
const double Projectile::HorizontalDisplacement(const double& time) const {
  return InitialVelocity() * cos(LaunchAngle()) * time;
}

// Member Function to Calculate the Vertical Displacement at a given time
const double Projectile::VerticalDisplacement(const double& time) const {
  const double kGravity = 9.80665;  // meters per second squared
  return (InitialVelocity() * sin(LaunchAngle()) * time) -
         (0.5 * kGravity * time * time) + InitialHeight();
}

// Member Function to Calculate the magnitude of the displacement at a given
// time
const double Projectile::Displacement(const double& time) const {
  double horizontal_displacement = HorizontalDisplacement(time);
  double vertical_displacement = VerticalDisplacement(time);
  return sqrt(abs((horizontal_displacement * horizontal_displacement +
                   vertical_displacement * vertical_displacement)));
}

// Member Function to Calculate the total time of fligh assuming a flat surface
// is given
const double Projectile::TimeOfFlight(const double& time) const {
  const double kGravity = 9.80665;  // meters per second squared
  return (InitialVelocity() * sin(LaunchAngle()) +
          sqrt(InitialVelocity() * InitialVelocity() * sin(LaunchAngle()) *
                   sin(LaunchAngle()) +
               2 * kGravity * InitialHeight())) /
         kGravity;
}

// Member Function to Calculate the maximum height achieved above the surface
const double Projectile::MaximumHeight(const double& time) const {
  const double kGravity = 9.80665;  // meters per second squared
  return InitialVelocity() * InitialVelocity() * sin(LaunchAngle()) *
             sin(LaunchAngle()) / (2 * kGravity) +
         InitialHeight();
}

// Member Function to Calculate the total horizontal distance traveled
const double Projectile::HorizontalDistance(const double& time) const {
  return InitialVelocity() * cos(LaunchAngle()) * TimeOfFlight(time);
}
}  // namespace physics