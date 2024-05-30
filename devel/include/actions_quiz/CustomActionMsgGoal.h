// Generated by gencpp from file actions_quiz/CustomActionMsgGoal.msg
// DO NOT EDIT!


#ifndef ACTIONS_QUIZ_MESSAGE_CUSTOMACTIONMSGGOAL_H
#define ACTIONS_QUIZ_MESSAGE_CUSTOMACTIONMSGGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>

namespace actions_quiz
{
template <class ContainerAllocator>
struct CustomActionMsgGoal_
{
  typedef CustomActionMsgGoal_<ContainerAllocator> Type;

  CustomActionMsgGoal_()
    : goal()  {
    }
  CustomActionMsgGoal_(const ContainerAllocator& _alloc)
    : goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::String_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> const> ConstPtr;

}; // struct CustomActionMsgGoal_

typedef ::actions_quiz::CustomActionMsgGoal_<std::allocator<void> > CustomActionMsgGoal;

typedef boost::shared_ptr< ::actions_quiz::CustomActionMsgGoal > CustomActionMsgGoalPtr;
typedef boost::shared_ptr< ::actions_quiz::CustomActionMsgGoal const> CustomActionMsgGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator1> & lhs, const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator2> & rhs)
{
  return lhs.goal == rhs.goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator1> & lhs, const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace actions_quiz

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "08a998acc62f6e46d584d02104d1b4e4";
  }

  static const char* value(const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x08a998acc62f6e46ULL;
  static const uint64_t static_value2 = 0xd584d02104d1b4e4ULL;
};

template<class ContainerAllocator>
struct DataType< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "actions_quiz/CustomActionMsgGoal";
  }

  static const char* value(const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#goal\n"
"std_msgs/String goal\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
;
  }

  static const char* value(const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CustomActionMsgGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::actions_quiz::CustomActionMsgGoal_<ContainerAllocator>& v)
  {
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ACTIONS_QUIZ_MESSAGE_CUSTOMACTIONMSGGOAL_H
