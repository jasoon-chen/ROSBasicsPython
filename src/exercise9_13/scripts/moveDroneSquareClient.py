#! /usr/bin/env python
import rospy
import time
import actionlib
from actionlib.msg import TestFeedback, TestResult, TestAction, TestGoal

def feedback_callback(feedback):
    print("Moving Drone")

rospy.init_node('moveDroneSquare_client')

client = actionlib.SimpleActionClient('/moveDroneSquareAS', TestAction)
client.wait_for_server()

client.send_goal(TestGoal(), feedback_cb=feedback_callback)

client.wait_for_result()

print('[Result] State: %d'%(client.get_state()))