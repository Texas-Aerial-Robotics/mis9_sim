Repo for developing the Mission 9 Sim

To build:

colcon build --symlink-install
source install/setup.bash

^ DON'T FORGET IT!

Current model path (put in bash): 

## Setup 

run 
```
echo 'export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/ros2_ws/src/mis9_sim/models' >> ~/.bashrc
```
