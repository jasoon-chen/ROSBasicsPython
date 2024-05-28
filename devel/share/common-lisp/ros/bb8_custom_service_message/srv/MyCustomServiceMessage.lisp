; Auto-generated. Do not edit!


(cl:in-package bb8_custom_service_message-srv)


;//! \htmlinclude MyCustomServiceMessage-request.msg.html

(cl:defclass <MyCustomServiceMessage-request> (roslisp-msg-protocol:ros-message)
  ((side
    :reader side
    :initarg :side
    :type cl:float
    :initform 0.0)
   (repetitions
    :reader repetitions
    :initarg :repetitions
    :type cl:integer
    :initform 0))
)

(cl:defclass MyCustomServiceMessage-request (<MyCustomServiceMessage-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MyCustomServiceMessage-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MyCustomServiceMessage-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bb8_custom_service_message-srv:<MyCustomServiceMessage-request> is deprecated: use bb8_custom_service_message-srv:MyCustomServiceMessage-request instead.")))

(cl:ensure-generic-function 'side-val :lambda-list '(m))
(cl:defmethod side-val ((m <MyCustomServiceMessage-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bb8_custom_service_message-srv:side-val is deprecated.  Use bb8_custom_service_message-srv:side instead.")
  (side m))

(cl:ensure-generic-function 'repetitions-val :lambda-list '(m))
(cl:defmethod repetitions-val ((m <MyCustomServiceMessage-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bb8_custom_service_message-srv:repetitions-val is deprecated.  Use bb8_custom_service_message-srv:repetitions instead.")
  (repetitions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MyCustomServiceMessage-request>) ostream)
  "Serializes a message object of type '<MyCustomServiceMessage-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'side))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'repetitions)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MyCustomServiceMessage-request>) istream)
  "Deserializes a message object of type '<MyCustomServiceMessage-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'side) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'repetitions) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MyCustomServiceMessage-request>)))
  "Returns string type for a service object of type '<MyCustomServiceMessage-request>"
  "bb8_custom_service_message/MyCustomServiceMessageRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyCustomServiceMessage-request)))
  "Returns string type for a service object of type 'MyCustomServiceMessage-request"
  "bb8_custom_service_message/MyCustomServiceMessageRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MyCustomServiceMessage-request>)))
  "Returns md5sum for a message object of type '<MyCustomServiceMessage-request>"
  "b78c0d1a37ffcec6adef7714dda05daa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MyCustomServiceMessage-request)))
  "Returns md5sum for a message object of type 'MyCustomServiceMessage-request"
  "b78c0d1a37ffcec6adef7714dda05daa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MyCustomServiceMessage-request>)))
  "Returns full string definition for message of type '<MyCustomServiceMessage-request>"
  (cl:format cl:nil "float64 side         # The distance of each side of the square~%int32 repetitions    # The number of times BB-8 has to execute the square movement when the service is called~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MyCustomServiceMessage-request)))
  "Returns full string definition for message of type 'MyCustomServiceMessage-request"
  (cl:format cl:nil "float64 side         # The distance of each side of the square~%int32 repetitions    # The number of times BB-8 has to execute the square movement when the service is called~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MyCustomServiceMessage-request>))
  (cl:+ 0
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MyCustomServiceMessage-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MyCustomServiceMessage-request
    (cl:cons ':side (side msg))
    (cl:cons ':repetitions (repetitions msg))
))
;//! \htmlinclude MyCustomServiceMessage-response.msg.html

(cl:defclass <MyCustomServiceMessage-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MyCustomServiceMessage-response (<MyCustomServiceMessage-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MyCustomServiceMessage-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MyCustomServiceMessage-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bb8_custom_service_message-srv:<MyCustomServiceMessage-response> is deprecated: use bb8_custom_service_message-srv:MyCustomServiceMessage-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <MyCustomServiceMessage-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bb8_custom_service_message-srv:success-val is deprecated.  Use bb8_custom_service_message-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MyCustomServiceMessage-response>) ostream)
  "Serializes a message object of type '<MyCustomServiceMessage-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MyCustomServiceMessage-response>) istream)
  "Deserializes a message object of type '<MyCustomServiceMessage-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MyCustomServiceMessage-response>)))
  "Returns string type for a service object of type '<MyCustomServiceMessage-response>"
  "bb8_custom_service_message/MyCustomServiceMessageResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyCustomServiceMessage-response)))
  "Returns string type for a service object of type 'MyCustomServiceMessage-response"
  "bb8_custom_service_message/MyCustomServiceMessageResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MyCustomServiceMessage-response>)))
  "Returns md5sum for a message object of type '<MyCustomServiceMessage-response>"
  "b78c0d1a37ffcec6adef7714dda05daa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MyCustomServiceMessage-response)))
  "Returns md5sum for a message object of type 'MyCustomServiceMessage-response"
  "b78c0d1a37ffcec6adef7714dda05daa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MyCustomServiceMessage-response>)))
  "Returns full string definition for message of type '<MyCustomServiceMessage-response>"
  (cl:format cl:nil "bool success         # Did it achieve it?~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MyCustomServiceMessage-response)))
  "Returns full string definition for message of type 'MyCustomServiceMessage-response"
  (cl:format cl:nil "bool success         # Did it achieve it?~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MyCustomServiceMessage-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MyCustomServiceMessage-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MyCustomServiceMessage-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MyCustomServiceMessage)))
  'MyCustomServiceMessage-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MyCustomServiceMessage)))
  'MyCustomServiceMessage-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyCustomServiceMessage)))
  "Returns string type for a service object of type '<MyCustomServiceMessage>"
  "bb8_custom_service_message/MyCustomServiceMessage")