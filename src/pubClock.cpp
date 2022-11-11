#include <ros/ros.h>
#include<sensor_msgs/Imu.h>
#include<rosgraph_msgs/Clock.h>

std::string imuTopic="/imu_raw";
double float_secs;
ros::Publisher pubData;

void imuCallback(sensor_msgs::ImuConstPtr msg){
    float_secs = msg->header.stamp.toSec();
    rosgraph_msgs::Clock pubClock;
    pubClock.clock.sec = int(float_secs);
    pubClock.clock.nsec = int((float_secs - pubClock.clock.sec) * 1000000000);
    pubData.publish(pubClock);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "OdomIntegrate2MapTools");
    ros::NodeHandle nh;
    ros::NodeHandle nhPrivate = ros::NodeHandle("~");

    nhPrivate.getParam("imuTopic", imuTopic);

    ros::Subscriber subOdometryMap = nh.subscribe<sensor_msgs::Imu> (imuTopic, 5, imuCallback);
    pubData = nh.advertise<rosgraph_msgs::Clock>("/clock",5);
    ros::spin();
    return 0;
}
