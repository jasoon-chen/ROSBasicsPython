// Generated by gencpp from file bb8_custom_service_message/MyCustomServiceMessageResponse.msg
// DO NOT EDIT!


#ifndef BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGERESPONSE_H
#define BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace bb8_custom_service_message
{
template <class ContainerAllocator>
struct MyCustomServiceMessageResponse_
{
  typedef MyCustomServiceMessageResponse_<ContainerAllocator> Type;

  MyCustomServiceMessageResponse_()
    : success(false)  {
    }
  MyCustomServiceMessageResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MyCustomServiceMessageResponse_

typedef ::bb8_custom_service_message::MyCustomServiceMessageResponse_<std::allocator<void> > MyCustomServiceMessageResponse;

typedef boost::shared_ptr< ::bb8_custom_service_message::MyCustomServiceMessageResponse > MyCustomServiceMessageResponsePtr;
typedef boost::shared_ptr< ::bb8_custom_service_message::MyCustomServiceMessageResponse const> MyCustomServiceMessageResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator1> & lhs, const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator1> & lhs, const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace bb8_custom_service_message

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bb8_custom_service_message/MyCustomServiceMessageResponse";
  }

  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success         # Did it achieve it?\n"
;
  }

  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MyCustomServiceMessageResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bb8_custom_service_message::MyCustomServiceMessageResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGERESPONSE_H
