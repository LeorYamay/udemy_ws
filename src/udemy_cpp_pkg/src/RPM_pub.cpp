#include "ros/ros.h"
// #include "std_msgs/String.h"
#include "std_msgs/Float32.h"

#include <string.h>;
#include <float.h>;

const float RPM =60;
int main(int argc, char ** argv)
{
    ros::init(argc, argv, "RPM_pub_node");
    ros::NodeHandle nod_handle;

    ros::Publisher RPM_pub = nod_handle.advertise<std_msgs::Float32>("RPM",10);
    ros::Rate pub_rate(5); //refresh rate
    ROS_INFO("Publishing RPM"); //to terminal
    while(ros::ok())
    {
        std_msgs::Float32 msg;
        msg.data = RPM;
        RPM_pub.publish(msg);
        pub_rate.sleep();
    }

}