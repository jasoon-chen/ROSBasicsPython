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

# Side Notes
When you create a new package, it seems like best practice is to run `catkin_make` or `catkin build` whichever one your ROS is setup to use. For this course, `catkin_make` is typically used. Now, you only need to do this to one shell for the entire ROS. But you also need to make sure you run `source devel/setup.bash` in __**EACH**__ shell. Not sure why but it seems to be said so [here](https://get-help.theconstruct.ai/t/error-cannot-load-message-class-for-package-message-are-your-messages-built/55)