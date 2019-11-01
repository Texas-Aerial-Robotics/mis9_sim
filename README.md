Repo for developing the Mission 9 Sim

To build:

colcon build --symlink-install
source install/setup.bash
^ DON'T FORGET IT!

Current model path (put in bash): 
export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/gazebo_ws/gazebo_models

Plugin path TBD