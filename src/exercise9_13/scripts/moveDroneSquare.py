#! /usr/bin/env python
import rospy
import actionlib
import time

from geometry_msgs.msg import Twist
from actionlib.msg import TestFeedback, TestResult, TestAction
from std_msgs.msg import Empty
import math

class MoveDroneSquare(object):
    _feedback = TestFeedback()
    _result = TestResult()

    def __init__(self):
        self._actionServer = actionlib.SimpleActionServer("moveDroneSquareAS", TestAction, self.cb, False)
        self._actionServer.start()
        self._pubTakeOff = rospy.Publisher("/drone/takeoff", Empty, queue_size=1)
        self._pubLand = rospy.Publisher("/drone/land", Empty, queue_size=1)
        self._pubCmdVelocity = rospy.Publisher("/cmd_vel", Twist, queue_size=1)
        self._move = Twist()
    
    def cb(self, goal):
        rospy.loginfo("Action Server Called")
        success = True
        rate = rospy.Rate(1)
        
        # Takeoff the Drone
        while self._pubTakeOff.get_num_connections() < 1:
            pass
        self._pubTakeOff.publish(Empty())
        rate.sleep()
        
        # Go in a square
        for x in range(4):
            # Check if the Action has been requested to be Cancelled
            if self._actionServer.is_preempt_requested():
                rospy.loginfo("Moving Drone In a Square has been requested to be cancelled")
                self._actionServer.set_preempted()
                success = False
                break
            self.moveStraight()
            time.sleep(2)
            self.turn()
            time.sleep(2)

            # Publish the feedback message
            self._feedback.feedback = x
            self._actionServer.publish_feedback(self._feedback)
            rate.sleep()
        
        # Action is Successful
        if success:
            self._actionServer.set_succeeded(TestResult())
        self.stop()
        rospy.loginfo("Action is Successful")
        
    
    def moveStraight(self):
        rospy.loginfo("Moving Straight")
        self._move.linear.x = 1
        self._move.angular.z = 0
        self._pubCmdVelocity.publish(self._move)
    
    def turn(self):
        rospy.loginfo("Turning")
        self._move.linear.x = 0
        self._move.angular.z = 1
        self._pubCmdVelocity.publish(self._move)
    
    def stop(self):
        rospy.loginfo("Stopping")
        self._move.linear.x = 0
        self._move.angular.z = 0
        self._pubCmdVelocity.publish(self._move)

if __name__ == "__main__":
    rospy.init_node("movedronesquare_node")
    MoveDroneSquare()
    rospy.spin()