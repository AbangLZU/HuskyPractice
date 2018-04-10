//
// Created by abang on 18-4-9.
//

#include "husky_high_level_controller/husky_controller.hpp"


namespace husky_controller{


    HuskyController::HuskyController(ros::NodeHandle &node_handle):nodeHandle_(node_handle) {
        std::string topic;
        if(!nodeHandle_.getParam("/laser_listener/laser_topic", topic)){
            ROS_ERROR("Load the laser scan topic param fail!!");
        } else{
            HuskyController::laserSub_ = nodeHandle_.subscribe(topic, 1, &HuskyController::LaserCallBack, this);

            ros::spin();
        }
    }


    void HuskyController::LaserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg) {

        unsigned long len = msg->ranges.size();
        std::vector<float> filtered_scan;
        for (int i = 0; i < len; ++i) {
            if(std::isnormal(msg->ranges[i])){
                filtered_scan.push_back(msg->ranges[i]);
            }
        }
        for (int j = 0; j < filtered_scan.size(); ++j) {
            ROS_INFO_STREAM(filtered_scan[j]);
        }
    }

} //namespace husky_controller