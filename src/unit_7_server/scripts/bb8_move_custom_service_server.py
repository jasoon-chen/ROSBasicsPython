#! /usr/bin/env python

import rospy
from my_custom_srv_msg_pkg.srv import MyCustomServiceMessage, MyCustomServiceMessageResponse 
from geometry_msgs.msg import Twist

def cb(request):
    print("callback called")
    move.linear.x = 0.5
    move.angular.z = 0.5
    pub.publish(move)
    rospy.sleep(request.duration)
    move.linear.x = 0
    move.angular.z = 0
    pub.publish(move)

    my_response = MyCustomServiceMessageResponse()
    my_response.success = True
    return my_response

rospy.init_node('move_in_custom_circle_service')
service = rospy.Service("/move_bb8_in_circle_custom", MyCustomServiceMessage, cb)
pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
move = Twist()
rospy.spin()