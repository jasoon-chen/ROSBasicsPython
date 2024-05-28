#! /usr/bin/env python

import rospkg
import rospy
# from execute_trajectory_srv.srv import ExecTraj
from iri_wam_reproduce_trajectory.srv import ExecTraj, ExecTrajRequest
import sys

rospy.init_node('unit_5_services')
rospy.wait_for_service('/execute_trajectory')
traj_by_name_service = rospy.ServiceProxy('/execute_trajectory', ExecTraj)
execute_trajectory_request_object = ExecTrajRequest()

rospack = rospkg.RosPack()
traj = rospack.get_path('iri_wam_reproduce_trajectory') + "/config/get_food.txt"
result = traj_by_name_service(traj)
print(result)