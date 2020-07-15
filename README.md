# Texas Aerial Robotics Mission 9 Sim

This repository contains ROS 2 and Gazebo files for building TAR's Mission 9 Sim.

## Table of Contents
* [File and Directory Descriptions](#file-directory-descriptions)
* [Dependencies](#dependencies)
* [Setup - Create a ROS 2 workspace](#setup---create-a-ros-2-workspace)
* [Building the ROS 2 packages](#building-the-ros-2-packages)
* [Gazebo stuff idk yet](#gazebo-stuff-idk-yet)

## File and Directory Descriptions
```
mis9_sim
├── launch - Gazebo/ROS launch files
├── models - Model files used in the world files
│   ├── commsmod - Model data for communications module
│   ├── drone_new - Model data for our drone
│   ├── mast - Model data for mast
│   └── pylon - Model data for pylon markers
├── scripts - Gazebo set up scripts
├── src - Source code for ROS nodes
├── wavegen - idk ask Matt
├── worlds - .world files for Gazebo sim
│   └──mis9.world - Sim for Mission 9
├── CMakeLists.txt - Package file for colcon build
└── package.xml - Package file for colcon build
```

## Dependencies

**Note**: The following instructions are for Ubuntu. Your mileage may vary with other operating systems. The basic steps should be pretty similar, but the exact commands will vary.

- [ROS 2](https://index.ros.org/doc/ros2/Installation/) (not sure which distro yet)
    - Robot Operating System 2, used on the actual drone so needs to be used in the sim.
    - Use Debian packages to do a full desktop install
    - Running the following command puts the quoted command into your .bashrc file, which is basically a config file for bash. This means you won't have to manually source ROS every time you open a new terminal.
```
echo 'source /opt/ros/<distro>/setup.bash' >> ~/.bashrc
```

- [Colcon Build Tool](https://design.ros2.org/articles/build_tool.html)
    - Used to build ROS packages
    - Install with the following command
```
sudo apt install python3-colcon-common-extensions
```

- [Gazebo Sim](http://gazebosim.org/tutorials?tut=install_ubuntu&cat=install)
    - The actual simulation software

## Setup - Create a ROS 2 workspace

Make a new folder, aka directory (`mkdir` = make directory), called `ros2_ws` (ROS 2 workspace) in your home directory (abbreviated as `~`). `~/ros2_ws/` will be the root of your ROS 2 workspace. In the root of your workspace, make another directory called `src`. Navigate into `ros2_ws/src`. Or you can just copy paste this command.
```
mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
```


Next we're going to clone this repository into your ROS 2 workspace. Click the green 'Code' button at the top right of this repository and copy the link that comes up. Run the following command, where `<link>` is the link you copied
```
git clone <link>
```

Congrats, you're done setting up the ROS 2 workspace! [Background info for nerds.](https://index.ros.org/doc/ros2/Tutorials/Workspace/Creating-A-Workspace/)

## Building the ROS 2 packages

Each directory in `~/ros2_ws/src` is known as a package, and these packages are built into executables with colcon. You probably only have one package, `mis9_sim`. **Always build packages in the root of your ROS 2 workspace (`~/ros2_ws`)**.

Source ROS's setup script now if you didn't put it in your .bashrc. Run the following to make sure you aren't missing any dependencies:
```
rosdep install -i --from-path src --rosdistro <distro> -y
```
Build:
```
colcon build --symlink-install
```
Assuming a successful build, open a new terminal window (important) and source ROS's setup script again if needed. Navigate into the root of your workspace and run the following:
```
source install/setup.bash
```
Now you can run and test the different nodes with the following format:
```
ros2 run <package_name> <executable_name>
```
[More details for nerds.](https://index.ros.org/doc/ros2/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber/)

## Gazebo stuff idk yet
run
```
echo 'export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/ros2_ws/src/mis9_sim/models' >> ~/.bashrc
```
