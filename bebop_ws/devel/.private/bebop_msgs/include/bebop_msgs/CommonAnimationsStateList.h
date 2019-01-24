// Generated by gencpp from file bebop_msgs/CommonAnimationsStateList.msg
// DO NOT EDIT!


#ifndef BEBOP_MSGS_MESSAGE_COMMONANIMATIONSSTATELIST_H
#define BEBOP_MSGS_MESSAGE_COMMONANIMATIONSSTATELIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace bebop_msgs
{
template <class ContainerAllocator>
struct CommonAnimationsStateList_
{
  typedef CommonAnimationsStateList_<ContainerAllocator> Type;

  CommonAnimationsStateList_()
    : header()
    , anim(0)
    , state(0)
    , error(0)  {
    }
  CommonAnimationsStateList_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , anim(0)
    , state(0)
    , error(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _anim_type;
  _anim_type anim;

   typedef uint8_t _state_type;
  _state_type state;

   typedef uint8_t _error_type;
  _error_type error;



  enum {
    anim_HEADLIGHTS_FLASH = 0u,
    anim_HEADLIGHTS_BLINK = 1u,
    anim_HEADLIGHTS_OSCILLATION = 2u,
    anim_SPIN = 3u,
    anim_TAP = 4u,
    anim_SLOW_SHAKE = 5u,
    anim_METRONOME = 6u,
    anim_ONDULATION = 7u,
    anim_SPIN_JUMP = 8u,
    anim_SPIN_TO_POSTURE = 9u,
    anim_SPIRAL = 10u,
    anim_SLALOM = 11u,
    anim_BOOST = 12u,
    anim_LOOPING = 13u,
    anim_BARREL_ROLL_180_RIGHT = 14u,
    anim_BARREL_ROLL_180_LEFT = 15u,
    anim_BACKSWAP = 16u,
    state_stopped = 0u,
    state_started = 1u,
    state_notAvailable = 2u,
    error_ok = 0u,
    error_unknown = 1u,
  };


  typedef boost::shared_ptr< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> const> ConstPtr;

}; // struct CommonAnimationsStateList_

typedef ::bebop_msgs::CommonAnimationsStateList_<std::allocator<void> > CommonAnimationsStateList;

typedef boost::shared_ptr< ::bebop_msgs::CommonAnimationsStateList > CommonAnimationsStateListPtr;
typedef boost::shared_ptr< ::bebop_msgs::CommonAnimationsStateList const> CommonAnimationsStateListConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace bebop_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'bebop_msgs': ['/home/cezar/bebop_ws/src/bebop_autonomy/bebop_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c89b289a8f935a33f0451effae3f9508";
  }

  static const char* value(const ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc89b289a8f935a33ULL;
  static const uint64_t static_value2 = 0xf0451effae3f9508ULL;
};

template<class ContainerAllocator>
struct DataType< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bebop_msgs/CommonAnimationsStateList";
  }

  static const char* value(const ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# CommonAnimationsStateList\n\
# auto-generated from up stream XML files at\n\
#   github.com/Parrot-Developers/libARCommands/tree/master/Xml\n\
# To check upstream commit hash, refer to last_build_info file\n\
# Do not modify this file by hand. Check scripts/meta folder for generator files.\n\
#\n\
# SDK Comment: Paramaterless animations state list.\n\
\n\
Header header\n\
\n\
# Animation type.\n\
uint8 anim_HEADLIGHTS_FLASH=0  # Flash headlights.\n\
uint8 anim_HEADLIGHTS_BLINK=1  # Blink headlights.\n\
uint8 anim_HEADLIGHTS_OSCILLATION=2  # Oscillating headlights.\n\
uint8 anim_SPIN=3  # Spin animation.\n\
uint8 anim_TAP=4  # Tap animation.\n\
uint8 anim_SLOW_SHAKE=5  # Slow shake animation.\n\
uint8 anim_METRONOME=6  # Metronome animation.\n\
uint8 anim_ONDULATION=7  # Standing dance animation.\n\
uint8 anim_SPIN_JUMP=8  # Spin jump animation.\n\
uint8 anim_SPIN_TO_POSTURE=9  # Spin that end in standing posture, or in jumper if it was standing animation.\n\
uint8 anim_SPIRAL=10  # Spiral animation.\n\
uint8 anim_SLALOM=11  # Slalom animation.\n\
uint8 anim_BOOST=12  # Boost animation.\n\
uint8 anim_LOOPING=13  # Make a looping. (Only for WingX)\n\
uint8 anim_BARREL_ROLL_180_RIGHT=14  # Make a barrel roll of 180 degree turning on right. (Only for WingX)\n\
uint8 anim_BARREL_ROLL_180_LEFT=15  # Make a barrel roll of 180 degree turning on left. (Only for WingX)\n\
uint8 anim_BACKSWAP=16  # Put the drone upside down. (Only for WingX)\n\
uint8 anim\n\
# State of the animation\n\
uint8 state_stopped=0  # animation is stopped\n\
uint8 state_started=1  # animation is started\n\
uint8 state_notAvailable=2  # The animation is not available\n\
uint8 state\n\
# Error to explain the state\n\
uint8 error_ok=0  # No Error\n\
uint8 error_unknown=1  # Unknown generic error\n\
uint8 error\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.anim);
      stream.next(m.state);
      stream.next(m.error);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommonAnimationsStateList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bebop_msgs::CommonAnimationsStateList_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "anim: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.anim);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
    s << indent << "error: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.error);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEBOP_MSGS_MESSAGE_COMMONANIMATIONSSTATELIST_H
