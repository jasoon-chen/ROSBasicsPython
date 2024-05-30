# ROS Basics in 5 Days (Python)
This is to help people self learn ROS through [The Construct](https://www.theconstruct.ai/). Even though all of the tutorials and lessons are already on the website, this repository is meant to upload all of my solutions and also some hints while working through the project as some of them may not be clear. Feel free to create a github pull request or issue if you want to add onto this repository.

# 4 - Understanding ROS Topics - Publishers
For Exercise 3.1, it is recommended that you read the documentation for what a Twist message is. https://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/Twist.html The `Twist Message` has 2 instance members within itself which are both `geometry_msgs/Vector3 linear` and `geometry_msgs/Vector3 angular`. `Vector3` has instance variables of x, y, and z which are all float64. I am not 100% sure, however I'm pretty sure that the conventional coordinate system used on the Twist Message is Euler. For different coordinate systems, I'm not too sure how would be able to specific it. Possibly you would create your own SRV Message? For the Twist Message, the table below describes how you can interpret each of the components:

| Twist Message Components   | Meaning |
| -------- | ------- |
| linear.x  |  translational velocity along the x-axis    |
| linear.y | translational velocity along the y-axis     |
| linear.z | translational velocity along the z-axis     |
| angular.x    |  rotational velocity about the x-axis    |
| angular.y    | rotational velocity about the y-axis    |
| angular.z    | rotational velocity about the z-axis    |

For this project, you should use `linear.x` to move forward and `angular.z` to rotate. For the other values, you can leave it as the default value of 0.

**NOTE:** All linear translational velocities are in m/s while rotational velocities are in rads/s.

# 7 - Understanding ROS Services - Server
For Exercise 6.3, the lesson is not clear on utilizing `MyCustomServiceMessageRequest` when creating your own message for services. Here is a short explanation of each of the MyCustomService... datatypes.

`MyCustomServiceMessage` is used to define the datatype of your message. More specifically, that your service message is going to be a custom one. Examples of where you would use this would be like:
```py
move_client = rospy.ServiceProxy('/move_bb8_in_circle_custom', MyCustomServiceMessage)
```
This connects to the service proxy with the message type or more formally service class MyCustomService Message. However, we haven't defined any data attributes into this. This is where you would use `MyCustomServiceMessageRequest()` to input all of your attributes. For example, if your custom srv message was 
```
int32 duration
---
bool success
```
then you could use 
```py
move_request = MyCustomServiceMessageRequest()
move_request.duration = 2
```
to define the attributes of your Message Request. To send the message you would something like 
```py
result = move_client(move_request)
```
**NOTE:** Make sure you import the correct classes when you use this. Example: `from my_custom_srv_msg_pkg.srv import MyCustomServiceMessage, MyCustomServiceMessageRequest `

When you type rosservice call `/your_service_name_here [TAB]+[TAB]` and you don't get anything, this means that you are custom SRV message is not compiled. Try running `source devel/setup.bash` to solve the problem.

# 10 - Understanding ROS Actions - Servers
While this lesson is really clear in how you can make your own Action Server and utilizing Action Client, I think it lacks clarity in some of the important aspects you need for a Action Server.
1. Make sure when you are connecting to a publisher, you ensure that you wait until you are fully connected to the Publisher. There seems to be long latency between when you write `rospy.Publisher(...)` to when you actually connect to the publisher. One way that I have been using to fix this issue is to do
```py
while self._pubTakeOff.get_num_connections() < 1:
            pass
```
This makes sure that the the publisher has at least one connection. I'm not sure if this would work in real world environment or industry, but this is the way that I have found that works the best.

2. Make sure you check whether the user has decided to cancel the action. If you do not check for this, the action will just run until it finishes. One way that you can check for this is:
```py
if self._actionServer.is_preempt_requested():
                rospy.loginfo("Moving Drone In a Square has been requested to be cancelled")
                self._actionServer.set_preempted()
                success = False
                break
```
This checks if the actionServer has been cancelled by the user, if so then you need to make sure you do any necessary cleanup code to finish the Action. 

3. Make sure you also remember to publish your feedback message. This is important so that the client is able to retrieve any necessary information from the server. 
```py
self._feedback.feedback = x # Your information here
self._actionServer.publish_feedback(self._feedback)
```

4. Ultimately, make sure that once your action is successful you set the action as succeeded through `self._actionServer.set_succeeded(TestResult())`
# Side Notes
When you create a new package, it seems like best practice is to run `catkin_make` or `catkin build` whichever one your ROS is setup to use. For this course, `catkin_make` is typically used. Now, you only need to do this to one shell for the entire ROS. But you also need to make sure you run `source devel/setup.bash` in __**EACH**__ shell. Not sure why but it seems to be said so [here](https://get-help.theconstruct.ai/t/error-cannot-load-message-class-for-package-message-are-your-messages-built/55)
