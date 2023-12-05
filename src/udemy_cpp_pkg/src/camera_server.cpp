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
 

//  bool determineOddEven(udemy_cpp_pkg::OddEvenCheck::Request &req,
//                         udemy_cpp_pkg::OddEvenCheck::Response &res)
//                         {
//                             int remainder = req.number % 2;
//                             if (remainder==0)
//                             {
//                                 res.answer ="Even";
//                                 }

//                             else if(remainder ==1)
//                             {
//                                 res.answer ="Odd";
//                             }
//                             else{
//                                 return false;
//                             }
//                             return true;
//                         }

bool getCameraView(udemy_cpp_pkg::Camera::Request &req,
                        udemy_cpp_pkg::Camera::Response &res)
                        {
                            std::string image_path = std::to_string(req.angle) +".png";
                            
                            std::string full_path = image_dir + image_path;
                            std::cout <<"Image fullPath: " <<full_path<<std::endl;
                            cv::Mat image = cv::imread(full_path, 1);

                            if (!image.empty())
                            {
                                // Convert the OpenCV image to ROS image message
                                sensor_msgs::ImagePtr image_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
                                std::cout <<"Image fullPath: " <<full_path<<std::endl;
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
    exe_dir = exe_path.parent_path();
    fs::path temp_dir = fs::canonical(exe_dir);
    for (int i=0; i<3 ;++i)
    {
        temp_dir = temp_dir.parent_path();
        std::cout <<"Temp Directory: "<< std::to_string(i) <<" "<<temp_dir<<std::endl;
    }
    // Construct the workspace and image directories
    image_dir = temp_dir.string() + "/Images/";
    std::cout <<"Executable Directory: " <<exe_dir<<std::endl;
    std::cout <<"Image Directory: " <<image_dir<<std::endl;
    
    ros::init(argc,argv, "camera_service");
    ros::NodeHandle node_handle;
    ros::ServiceServer service = node_handle.advertiseService("camera_service", getCameraView);
    ROS_INFO("camera_service started");
    ros::spin();
    return 0;
}
