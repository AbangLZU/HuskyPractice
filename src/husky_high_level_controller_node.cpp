#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
#include "husky_high_level_controller/husky_controller.hpp"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
    ros::init(argc, argv, "laser_listener");

    ros::NodeHandle node_handle;
    husky_controller::HuskyController test(node_handle);

    return 0;

}