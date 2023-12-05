#include "ros/ros.h"
#include "udemy_cpp_pkg/Camera.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>

int main(int argc, char **argv)
{
    ros::init(argc,argv, "camera_service_client_node");
    ros::NodeHandle node_handle;
    ros::ServiceClient client = node_handle.serviceClient<udemy_cpp_pkg::Camera>("camera_service");

    udemy_cpp_pkg::Camera camera_srv;
    int input_num;

    std::cout << "Type '0' to quit" <<std::endl;
    while(ros::ok())
    {
        std::cout << "Enter camera angle: ";
        std::cin >> input_num;

        camera_srv.request.angle = input_num;

        if (input_num == 0)
        {
            ROS_INFO("Exiting application...");
            return 0;
        }   
        std::cout << "tania: ";
        std::cout << std::to_string(client.call(camera_srv))<<std::endl;
        if (client.call(camera_srv))
        {
            cv_bridge::CvImagePtr cv_ptr;
            cv_ptr = cv_bridge::toCvCopy(camera_srv.response.camera_image,sensor_msgs::image_encodings::BGR8);
            cv::imshow("Robot Camera Image", cv_ptr->image);
            cv::waitKey(1000);
        }
        else
        {
            ROS_ERROR("Service call failed");
            return 1;
        }
        std::cin.clear();
    }

}

