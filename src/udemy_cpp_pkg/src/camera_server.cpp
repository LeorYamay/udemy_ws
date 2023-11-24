#include "ros/ros.h"
#include "udemy_cpp_pkg/Camera.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <string.h>

bool getCameraView(udemy_cpp_pkg::Camera::Request &req,
                        udemy_cpp_pkg::Camera::Response &res)
                        {
                            std::string image_path = std::to_string(req.angle) +".png";
                            std::string full_path = "/home/leory/udemy_ws/images/" + image_path;

                            cv::Mat image = cv::imread(full_path, 1);

                            if (!image.empty())
                            {
                                // Convert the OpenCV image to ROS image message
                                sensor_msgs::ImagePtr image_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
        
                                // Set the response image
                                res.image = *image_msg;

                            } else{
                                ROS_WARN("Camera could not capture the angle : %d", req.angle)
                                return false;
                            }
                        }
                        return true
int main(int argc, char **argv)
{
    ros::init(argc,argv, "camera_service");
    ros::NodeHandle node_handle;
    ros::ServiceServer service = node_handle.advertiseService("camera_service", getCameraView);
    ROS_INFO("camera_service started");
    ros::spin();
    return 0;
}
