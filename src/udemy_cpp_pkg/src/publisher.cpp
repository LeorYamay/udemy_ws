#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string.h>;

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "hello_workld_pub_node");
    ros::NodeHandle nod_handle;

    ros::Publisher hello_world_pub = nod_handle.advertise<std_msgs::String>("hello_world",10);
    int counter =0;
    ros::Rate pub_rate(5); //refresh rate
    ROS_INFO("Publisher Node Started"); //to terminal
    while(ros::ok())
    {
        std_msgs::String msg;
        msg.data = "hello world " + std::to_string(counter);
        hello_world_pub.publish(msg);
        counter++;
        pub_rate.sleep();
    }

}