#! /usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

def cb(msg):
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
    frontRange = msg.ranges[int(len(msg.ranges)/2)]
    rightRange = msg.ranges[0]
    leftRange = msg.ranges[len(msg.ranges)-1]
    
    move = Twist()
    move.linear.x = 0
    move.angular.z = 0

    if frontRange > 1:
        move.linear.x = 0.5
    elif frontRange < 1:
        move.angular.z = 0.5

    if rightRange < 1:
        move.angular.z = 0.5
    
    if leftRange < 1:
        move.angular.z = -0.5

    pub.publish(move)

rospy.init_node("topics_quiz_node")
sub = rospy.Subscriber("/kobuki/laser/scan", LaserScan, cb)
rospy.spin()