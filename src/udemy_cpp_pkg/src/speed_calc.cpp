#include "ros/ros.h"
// #include "std_msgs/String.h"
#include "std_msgs/Float32.h"

// #include <string.h>;
#include <float.h>;

ros::Publisher speed_pub;
 float Wheel_Radius ;//meters
void subCallback(const std_msgs::Float32::ConstPtr& rpm)
{

    ros::NodeHandle callback_node_handle;
    if (callback_node_handle.getParam("wheel_radius",Wheel_Radius))
    {
        std_msgs::Float32 speed_msg;
        // speed_msg.data = (2 * 3.14 * Wheel_Radius * (rpm->data / 60)); //m/s
        speed_msg.data =Wheel_Radius * 2 * 3.14 * (rpm->data)/60; //m/s
        speed_pub.publish(speed_msg);
    }
    else
    {
        ROS_WARN("No value set for wheel_radius parameter"); 
    }
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "speed_calc_node");
    ros::NodeHandle node_handle;
    speed_pub = node_handle.advertise<std_msgs::Float32>("Speed",10);
    ros::Subscriber RPM_sub = node_handle.subscribe("RPM",10,subCallback);
    ros::spin();
    return 0;
}
 