#include "ros/ros.h"
#include "udemy_cpp_pkg/OddEvenCheck.h"

int main(int argc, char **argv)
{
    ros::init(argc,argv, "odd_even_service_client_node");
    ros::NodeHandle node_handle;
    ros::ServiceClient client = node_handle.serviceClient<udemy_cpp_pkg::OddEvenCheck>("odd_even_check");

    udemy_cpp_pkg::OddEvenCheck odd_even_check_srv;
    int input_num;

    std::cout << "Type '0' to quit" <<std::endl;
    while(ros::ok())
    {
        std::cout << "Enter a Integer: ";
        std::cin >> input_num;

        odd_even_check_srv.request.number = input_num;

        if (input_num == 0)
        {
            ROS_INFO("Exiting application...");
            return 0;
        }

        if (client.call(odd_even_check_srv))
        {
            std::string resp;
            resp =  odd_even_check_srv.response.answer;
            std::cout << "the numver is " << resp <<std :: endl;
        }
        else
        {
            ROS_ERROR("Service call failed");
            return 1;
        }
        std::cin.clear();
    }

}
