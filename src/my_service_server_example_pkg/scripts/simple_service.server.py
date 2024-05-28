#! /usr/bin/env python

import rospy 
from std_srvs.srv import Empty, EmptyResponse

def cb(request):
    print("callback has been called")
    return EmptyResponse()

rospy.init_node("service_server")
my_service = rospy.Service("/my_service", Empty, cb)
rospy.spin()