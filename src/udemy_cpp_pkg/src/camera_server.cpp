#include "ros/ros.h"
#include "udemy_cpp_pkg/Camera.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <string.h>
#include <filesystem>
namespace fs = std::filesystem;
std::string image_dir;
 
bool getCameraView(udemy_cpp_pkg::Camera::Request &req,
                        udemy_cpp_pkg::Camera::Response &res)
                        {
                            std::string image_path = std::to_string(req.angle) +".png";
                            std::string full_path = image_dir + image_path;

                            cv::Mat image = cv::imread(full_path, 1);

                            if (!image.empty())
                            {
                                // Convert the OpenCV image to ROS image message
                                sensor_msgs::ImagePtr image_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
        
                                // Set the response image
                                res.camera_image = *image_msg;
                                return true;
                            } else{
                                ROS_WARN("Camera could not capture the angle : %d", req.angle);
                                return false;
                            }
                        
                        }
int main(int argc, char **argv)
{
    std::string exe_dir;
    // Get the executable's directory using <filesystem>
    fs::path exe_path = fs::canonical(argv[0]);
    exe_dir = exe_path.parent_path().string();
    // Construct the workspace and image directories
    image_dir = exe_dir + "/images/";
    std::cout <<"Executable Directory: " <<exe_dir<<std::endl;
    std::cout <<"Image Directory: " <<image_dir<<std::endl;
    
    ros::init(argc,argv, "camera_service");
    ros::NodeHandle node_handle;
    ros::ServiceServer service = node_handle.advertiseService("camera_service", getCameraView);
    ROS_INFO("camera_service started");
    ros::spin();
    return 0;
}
