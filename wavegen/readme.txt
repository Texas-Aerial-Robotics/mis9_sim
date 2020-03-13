TEXAS AERIAL ROBOTICS
MISSION 9 SIMULATION

----------------------------------------------------
Mast Rotation Simulator, Wave Generator
----------------------------------------------------

The wave generator is used to simulate semi-random motion of the command mast as will be experienced during
the competition. This folder contains functions to generate a series of sinusoidal waves with varying period
and amplitude which will assigned to the pitch and roll movements of the command mast.

The files 'wavefunctions.cpp' and 'vectorfunctions.cpp' are responsible for generating the individual waves
and calculating each successive value for the period and amplitude.

'main.cpp' demonstrates an implimentation of these functions to generate a single wave set with varying
amplitude.

The successive generated have the following properties for their amplitude:

Range: 0-2.8
Maximum movement in one step: 25% of the range

The period is not changed in this example, but would be implimented by duplicating the next function and
assigning its output to the period input in line 16.

----------------------------------------------------
CHANGELOG:
----------------------------------------------------

-------------------- 3/12/19 --------------------

1) 'main.cpp' replaced with 'sim.cpp' which more accurately represents the intended implimentation within
the simulator. This function demonstrates how both PERIOD and AMPLITUDE will be varied by calling the
'next' function twice, and then demonstrates the iterative application of these variables to the
'wave' function. Boundary parameters are based on those specified in the game manual.

2) 'sim_user.cpp' added which allows parameters to be input from the command line at time execution.
'sim_user.cpp' also demonstrates how parameters can be adjusted to give various results.