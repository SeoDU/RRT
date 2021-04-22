# RRT(Updating)

The original code is from https://github.com/mseln/aeplanner

After creating several paths using RRT(Rapidly exploring Random Tree),
The best path is selected. Random samples are chosen within the known rectangular map.
The path can also expand to gradual increasing/decreasing hills.


<img width="60%" src="https://user-images.githubusercontent.com/47074271/115717447-26c84800-a3b5-11eb-85da-ed947776eba0.png" />

## Development environment
 - Ubuntu 18.04
 - ROS melodic
 - catkin tools

## Prerequisites
1. catkin simple

'''
cd ~/catkin_ws/src
git clone https://github.com/catkin/catkin_simple.git
'''

2. Octomap

'''
sudo apt-get install "ros-kinetic-octomap-*
'''


## Configuration

rrt/min_nodes: Iteration numbers of creating valid nodes.
system/bbx/r: The cylinder radius for detecting collision
system/bbx/overshoot: Overshoot of the cylinder height for detecting collision
tree/extension_range: Height of cylinder. (or node step length)
boundary/min , boundary/max : Only z value is meaningful. x,y ranges are set automatically.


<img width="20%" src="https://user-images.githubusercontent.com/47074271/115719109-bf12fc80-a3b6-11eb-93cb-efcd59a27573.gif" />

