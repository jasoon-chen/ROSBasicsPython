#! /usr/bin/env python

import rospy
from std_srvs.srv import Empty, EmptyRequest

print("called client")
rospy.init_node('bb8_move_service_client')
rospy.wait_for_service('/move_bb8_in_circle')
move_client = rospy.ServiceProxy('/move_bb8_in_circle', Empty)
move_request = EmptyRequest()

result = move_client(move_request)
print(result)