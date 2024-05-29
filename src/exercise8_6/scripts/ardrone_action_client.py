#! /usr/bin/env python

import rospy
import time
import actionlib
from ardrone_as.msg import ArdroneAction, ArdroneGoal, ArdroneResult, ArdroneFeedback
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
import random

# States of the Drone
PENDING = 0
ACTIVE = 1
DONE = 2
WARN = 3
ERROR = 4

# Feedback of the Drone
nImage = 1

def cb(feedback):
    global nImage 
    print("Number of Images: " + str(nImage))
    nImage += 1

if __name__ == "__main__":
    # Initialize the Nodes
    rospy.init_node('exercise_8_6_action_server_node')
    action = actionlib.SimpleActionClient('/ardrone_action_server', ArdroneAction)
    action.wait_for_server()
    rospy.loginfo("Successfully initialized action server library")

    # Start sending the Goals
    goal = ArdroneGoal()
    goal.nseconds = 10

    action.send_goal(goal, feedback_cb=cb)

    # Takeoff the Drone - https://get-help.theconstruct.ai/t/how-to-publish-once-only-one-message-into-a-topic-and-get-it-to-work/346
    pubTakeOff = rospy.Publisher("/drone/takeoff", Empty, queue_size=10)
    while pubTakeOff.get_num_connections() < 1:
        pass
    pubTakeOff.publish(Empty())
    rospy.loginfo("Successfully taken off")

    # Get the results of the action
    result = action.get_state()
    rate = rospy.Rate(1)

    rate.sleep()   

    # Randomly Move the Drone

    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=1)
    move = Twist()

    while result < DONE:
        rospy.loginfo("Moving in a random direction")

        move.linear.x = random.random()
        move.linear.y = random.random()
        move.linear.z = random.random()

        move.angular.x = random.random()
        move.angular.y = random.random()
        move.angular.z = random.random()
        pub.publish(move)
        rate.sleep()

        result = action.get_state()

    # Drone Finished Moving
    rospy.loginfo("Stopping Movement")

    move.linear.x = 0
    move.linear.y = 0
    move.linear.z = 0

    move.angular.x = 0
    move.angular.y = 0
    move.angular.z = 0
    pub.publish(move)
    rate.sleep()

    pubLand = rospy.Publisher("/drone/land", Empty, queue_size=1)
    while pubLand.get_num_connections() < 1:
        pass
    pubLand.publish(Empty())
    rospy.loginfo("Successfully landed")

