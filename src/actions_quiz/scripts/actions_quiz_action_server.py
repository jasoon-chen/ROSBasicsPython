#! /usr/bin/env python
import rospy
import actionlib
import time

from geometry_msgs.msg import Twist
from actions_quiz.msg import CustomActionMsgFeedback, CustomActionMsgResult, CustomActionMsgAction
from std_msgs.msg import Empty
import math

class CustomActionsObject(object):
    _feedback = CustomActionMsgFeedback()
    _result = CustomActionMsgResult()

    def __init__(self):
        self._actionServer = actionlib.SimpleActionServer("action_custom_msg_as", CustomActionMsgAction, self.cb, False)
        self._actionServer.start()
        self._pubTakeOff = rospy.Publisher("/drone/takeoff", Empty, queue_size=1)
        self._pubLand = rospy.Publisher("/drone/land", Empty, queue_size=1)
    
    def cb(self, goal):
        rospy.loginfo("Action Server Called")
        success = True
        currentState = "TAKEOFF"
        rate = rospy.Rate(1)
    
        # Check if the Action has been requested to be Cancelled
        if self._actionServer.is_preempt_requested():
            rospy.loginfo("Moving Drone In a Square has been requested to be cancelled")
            self._actionServer.set_preempted()
            success = False
        print(goal.goal.data)
        # Check if the goal is to takeoff
        if goal.goal.data == "TAKEOFF":
            # Takeoff the Drone
            print("Taking off the drone")
            while self._pubTakeOff.get_num_connections() < 1:
                pass
            self._pubTakeOff.publish(Empty())
            rate.sleep()
            currentState = "taking off"
        elif goal.goal.data == "LAND":
            # Takeoff the Drone
            print("Landing the drone")
            while self._pubLand.get_num_connections() < 1:
                pass
            self._pubLand.publish(Empty())
            rate.sleep()
            currentState = "landing"
        
        # Return the Feedback
        self._feedback.feedback = currentState
        self._actionServer.publish_feedback(self._feedback)
        rate.sleep()
    
        # Action is Successful
        if success:
            self._actionServer.set_succeeded(CustomActionMsgResult())
        rospy.loginfo("Action is Successful")

if __name__ == "__main__":
    rospy.init_node("CustomActionNode")
    CustomActionsObject()
    rospy.spin()