// Generated by gencpp from file bb8_custom_service_message/MyCustomServiceMessage.msg
// DO NOT EDIT!


#ifndef BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGE_H
#define BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGE_H

#include <ros/service_traits.h>


#include <bb8_custom_service_message/MyCustomServiceMessageRequest.h>
#include <bb8_custom_service_message/MyCustomServiceMessageResponse.h>


namespace bb8_custom_service_message
{

struct MyCustomServiceMessage
{

typedef MyCustomServiceMessageRequest Request;
typedef MyCustomServiceMessageResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MyCustomServiceMessage
} // namespace bb8_custom_service_message


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessage > {
  static const char* value()
  {
    return "b78c0d1a37ffcec6adef7714dda05daa";
  }

  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessage&) { return value(); }
};

template<>
struct DataType< ::bb8_custom_service_message::MyCustomServiceMessage > {
  static const char* value()
  {
    return "bb8_custom_service_message/MyCustomServiceMessage";
  }

  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessage&) { return value(); }
};


// service_traits::MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessageRequest> should match
// service_traits::MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessage >
template<>
struct MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessageRequest>
{
  static const char* value()
  {
    return MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessage >::value();
  }
  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::bb8_custom_service_message::MyCustomServiceMessageRequest> should match
// service_traits::DataType< ::bb8_custom_service_message::MyCustomServiceMessage >
template<>
struct DataType< ::bb8_custom_service_message::MyCustomServiceMessageRequest>
{
  static const char* value()
  {
    return DataType< ::bb8_custom_service_message::MyCustomServiceMessage >::value();
  }
  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessageResponse> should match
// service_traits::MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessage >
template<>
struct MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessageResponse>
{
  static const char* value()
  {
    return MD5Sum< ::bb8_custom_service_message::MyCustomServiceMessage >::value();
  }
  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::bb8_custom_service_message::MyCustomServiceMessageResponse> should match
// service_traits::DataType< ::bb8_custom_service_message::MyCustomServiceMessage >
template<>
struct DataType< ::bb8_custom_service_message::MyCustomServiceMessageResponse>
{
  static const char* value()
  {
    return DataType< ::bb8_custom_service_message::MyCustomServiceMessage >::value();
  }
  static const char* value(const ::bb8_custom_service_message::MyCustomServiceMessageResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // BB8_CUSTOM_SERVICE_MESSAGE_MESSAGE_MYCUSTOMSERVICEMESSAGE_H
