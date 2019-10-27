"""Launch the cpp_code executable in this package"""

from launch import LaunchDescription
import launch_ros.actions
import launch

def generate_launch_description():
	gzserver = launch.actions.ExecuteProcess(
		cmd = ['gzserver', '--verbose', 's', '/mis9_sim/worlds/protosim.world'],
		output = 'screen'
	)	
	return launch.LaunchDescription([gzserver])
