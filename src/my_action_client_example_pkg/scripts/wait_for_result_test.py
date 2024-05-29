#! /usr/bin/env python

import rospy
import time
import actionlib
from ardrone_as.msg import ArdroneAction, ArdroneGoal, ArdroneResult, ArdroneFeedback

nImage = 1

def feedback_callback(feedback):
    global nImage
    print('[Feedback] image n.%d received'%nImage)
    nImage += 1

if __name__ == "__main__":
    rospy.init_node('example_with_waitforresult_action_client_node')

    action_server_name = '/ardrone_action_server'
    client = actionlib.SimpleActionClient(action_server_name, ArdroneAction)

    rospy.loginfo('Waiting for Action Server ' + action_server_name)
    client.wait_for_server()
    rospy.loginfo('Action Server Found...' + action_server_name)

    goal = ArdroneGoal()
    goal.nseconds = 10

    client.send_goal(goal)
    rate = rospy.Rate(1)

    rospy.loginfo('Lets Start the Wait for the Action To finish Loop...')
    while not client.wait_for_result():
        rospy.loginfo("Doing Stuff while waiting for the Server to give a result")
        rate.sleep()
    
    rospy.loginfo("Example with WaitForResult Finished.")