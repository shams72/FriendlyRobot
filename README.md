
# Friendly Robot - Project Overview

**Friendly Robot** is a simple yet engaging robot designed using OpenGL as part of the "Visual Computing" module. The project demonstrates foundational concepts in computer graphics, such as vertex manipulation and rotation matrices.

## Design Details

- **Robot Body**: The robot's body is created by manipulating a cube, with each part of the robot designed and updated using a vertex shader.
- **Limb Rotation**: The arms and legs of the robot rotate using a rotation matrix in OpenGL ('rotateAroundPoint').

## How to Interact with Friendly Robot

- **Rotate the Robot**: Press `"R"` to rotate the robot.
- **Move the Robot**: 
  - To move the robot forward or backward, the camera's position relative to the origin is manipulated using `glm::lookAt`.
  - Press `"S"` to move the camera back and `"W"` to adjust forward.

## Setup Instructions

1. **Install CLion**: Ensure CLion is installed on your system.
2. **Clone the Project**: Clone the repository containing the Friendly Robot project.
3. **Import the Project**: Open CLion and import the cloned project.
4. **Run the Project**: Simply hit the "Run" button in CLion to start interacting with the Friendly Robot.
