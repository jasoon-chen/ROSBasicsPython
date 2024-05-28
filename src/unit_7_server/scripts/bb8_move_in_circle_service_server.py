#! /usr/bin/env python

import rospy
from std_srvs.srv import Empty, EmptyResponse
from geometry_msgs.msg import Twist

def cb(request):
    print("callback called")
    move.linear.x = 0.5
    move.angular.z = 0.5
    pub.publish(move)
    return EmptyResponse()

rospy.init_node('move_in_circle_service')
service = rospy.Service("/move_bb8_in_circle", Empty, cb)
pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
move = Twist()
rospy.spin()