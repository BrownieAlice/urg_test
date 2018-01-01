#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

namespace
{
  void laser_callback(const sensor_msgs::LaserScan &msg)
  {
    if (msg.ranges.empty())
    {
      ROS_WARN_STREAM("URG data is empty.");
      return;
    }
    
    const auto posi = msg.ranges.size() / 2;
    const auto length = msg.ranges.at(posi);
    const auto intensity = msg.intensities.at(posi);
    ROS_INFO_STREAM("ranges[" << posi << "]:" << length << ", intensities[" << posi << "]:" << intensity);
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "urg_test");
  ros::NodeHandle n;
  ros::Subscriber laser = n.subscribe("scan", 1, laser_callback);
  ros::Rate loop_rate(1);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
  
}
