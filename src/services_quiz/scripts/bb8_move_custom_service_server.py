#! /usr/bin/env python

import rospy
from bb8_custom_service_message.srv import BB8CustomServiceMessage, BB8CustomServiceMessageResponse
from geometry_msgs.msg import Twist
import math

def cb(request):
    print("Service Callback called")
    for x in range(request.repetitions):
        for y in range(4): 
            move_straight(request)
            turn()

    move.linear.x = 0
    move.angular.z = 0
    pub.publish(move)

    response = BB8CustomServiceMessageResponse()
    response.success = True
    return response

def move_straight(request):
    rospy.loginfo(f"Moving straight with side factor: {request.side}")

    move.linear.x = 0.5
    move.angular.z = 0.0

    move_duration = 1 / move.linear.x * request.side
    end_time = rospy.Time.now() + rospy.Duration(move_duration)
    rate = rospy.Rate(10)

    while rospy.Time.now() < end_time and not rospy.is_shutdown():
        pub.publish(move)
        rate.sleep()
    
    return not rospy.is_shutdown()

def turn():
    rospy.loginfo(f"Turning 90 Degrees")   

    move.linear.x = 0.0
    move.angular.z = 0.5

    move_duration = (math.pi / 2) / move.angular.z
    end_time = rospy.Time.now() + rospy.Duration(move_duration)
    rate = rospy.Rate(10)

    while rospy.Time.now() < end_time and not rospy.is_shutdown():
        pub.publish(move)
        rate.sleep()
    
    return not rospy.is_shutdown()

rospy.init_node('move_bb8_in_square_custom_server')
service = rospy.Service("/move_bb8_in_square_custom", BB8CustomServiceMessage, cb)
pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
move = Twist()
rospy.spin()