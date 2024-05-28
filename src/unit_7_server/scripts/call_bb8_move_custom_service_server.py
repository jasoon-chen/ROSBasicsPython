#! /usr/bin/env python

import rospy
from my_custom_srv_msg_pkg.srv import MyCustomServiceMessage, MyCustomServiceMessageRequest 

print("called client")
rospy.init_node('bb8_custom_move_service_client')
rospy.wait_for_service('/move_bb8_in_circle_custom')

move_client = rospy.ServiceProxy('/move_bb8_in_circle_custom', MyCustomServiceMessage)
move_request = MyCustomServiceMessageRequest()
move_request.duration = 2

result = move_client(move_request)
print(result)