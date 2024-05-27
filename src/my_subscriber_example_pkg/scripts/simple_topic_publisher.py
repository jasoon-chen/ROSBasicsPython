#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32
from nav_msgs.msg import Odometry
def cb(msg):
    print(msg)

rospy.init_node("topic_subscriber")
sub = rospy.Subscriber("/odom", Odometry, cb)
rospy.spin()