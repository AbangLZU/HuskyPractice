//
// Created by abang on 18-4-9.
//

#pragma once

#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

namespace husky_controller{

    class HuskyController {
    public:
        HuskyController(ros::NodeHandle &node_handle);

    private:
        void LaserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg);

        ros::NodeHandle &nodeHandle_;

        ros::Subscriber laserSub_;

    };

} // namespace husky_controller

