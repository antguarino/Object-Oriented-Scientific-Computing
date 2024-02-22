/** Interface file for the function to calculate Information relating to
 * Projectiles
 *
 * \file Projectile.h
 *
 * \author Anthony Guarino, (ag4933@rit.edu)
 * \date 11 February 2024
 *
 * \copyright Copyright © 2024, Rochester Institute of Technology
 *
 * \version 1.0.0
 *
 * \details
 *    This will allow you to create a projectile object with associated inputs
 * for Initial Velocity, Launch Angle, and Initial Height. You can get and set
 * these inputs with the functions: InitialVelocity(), LaunchAngle(), and
 * InitialHeight(). Member functions for Velocity, Horizontal Displacement,
 * Vertical Displacement, Magnitude of Displacement, Time of Flight, Maximum
 * Height, and Horizontal Distance are created in this file but have no function
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk. Its free
 * so you get what you pay for.
 *
 */

#include <cmath>
#include <numbers>

// Namespace for physics
namespace physics {

class Projectile {
 public:
  // Projector Constructor
  Projectile();

  Projectile(const double& initial_velocity, const double& launch_angle,
             const double& initial_height);

  // Getters and Setters
  // Initial Velocity Getter
  double InitialVelocity() const { return initial_velocity_; }

  // Initial Velocity Setter
  void InitialVelocity(const double& initial_velocity) {
    initial_velocity_ = initial_velocity;
  }

  // Launch Angle Getter
  double LaunchAngle() const { return launch_angle_; }

  // Launch Angle Setter [IN RADIANS] - Converted from degrees to radians
  void LaunchAngle(const double& launch_angle) {
    launch_angle_ = launch_angle * (std::numbers::pi / 180);
  }

  // Initial Height Getter
  double InitialHeight() const { return initial_height_; }

  // Initial Height Setter
  void InitialHeight(const double& initial_height) {
    initial_height_ = initial_height;
  }

  // Member Function to Calculate Velocity at a given time.
  const double Velocity(const double& time) const;

  // Member Function to Calculate the Horizontal Displacement at a given time
  const double HorizontalDisplacement(const double& time) const;

  // Member Function to Calculate the Vertical Displacement at a given time
  const double VerticalDisplacement(const double& time) const;

  // Member Function to Calculate the magnitude of the displacement at a given
  // time
  const double Displacement(const double& time) const;

  // Member Function to Calculate the total time of fligh assuming a flat
  // surface is given
  const double TimeOfFlight(const double& time) const;

  // Member Function to Calculate the maximum height achieved above the surface
  const double MaximumHeight(const double& time) const;

  // Member Function to Calculate the total horizontal distance traveled
  const double HorizontalDistance(const double& time) const;

 private:
  // Defining Private Variables
  double initial_velocity_;  // meters/seconds
  double launch_angle_;      // degrees
  double initial_height_;    // meters
};
}  // namespace physics
