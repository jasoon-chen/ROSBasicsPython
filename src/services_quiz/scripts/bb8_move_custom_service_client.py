#! /usr/bin/env python

import rospy
from bb8_custom_service_message.srv import BB8CustomServiceMessage, BB8CustomServiceMessageRequest

print("called client")
rospy.init_node('move_bb8_in_square_custom_client')
rospy.wait_for_service('/move_bb8_in_square_custom')
move_client = rospy.ServiceProxy('/move_bb8_in_square_custom', BB8CustomServiceMessage)
move_request = BB8CustomServiceMessageRequest()
move_request.side = 1
move_request.repetitions = 1

result = move_client(move_request)
print(result)