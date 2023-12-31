#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string.h>;

void subCallback(const std_msgs::StringConstPtr& msg)
{
    std::string msg_str = msg->data;
    ROS_INFO("%s",msg_str.c_str());
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "hello_workld_sub_node");
    ros::NodeHandle node_handle;
    ros::Subscriber hello_world_sub = node_handle.subscribe("hello_world",19,subCallback);
    ros::spin();
    return 0;
}
 