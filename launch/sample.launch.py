"""Launch the cpp_code executable in this package"""
import os
from launch import LaunchDescription
import launch_ros.actions
import launch

from glob import glob
from setuptools import setup

package_name = 'mis9_sim'


#setup(
	#OTHER PARAMS (IN CASE WE NEED)
#	data_files=[
#	# incase you need other file but for nw just launch files
#	(os.path.join('share,package_name'), glob('launch/*.launch.py'))
#	])
def generate_launch_description():
	return launch.LaunchDescription([
	launch_ros.actions.Node(
		package = 'mis9_sim',
		node_executable = 'cpp_code',
		output='screen'
	),
	launch.actions.ExecuteProcess(
		cmd = ['gzserver', '--verbose', 's', '~/ros2_ws/src/mis9_sim/worlds/obst_coll.world'],
		output = 'screen'),
	])	
	
