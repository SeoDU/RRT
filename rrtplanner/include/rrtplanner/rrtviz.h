#ifndef RRTVIZ_H
#define RRTVIZ_H

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <rrtplanner/rrtAction.h>


class Rrtviz
{

public:
  Rrtviz(ros::NodeHandle& nh);
  void rvizCallback (const geometry_msgs::PoseStamped& pose);
  void odomCallback (const nav_msgs::Odometry& pose);
  nav_msgs::Odometry pose_now;

private:
  ros::NodeHandle nh;
  ros::Subscriber odomClient;
  ros::Subscriber rvizClient;

  actionlib::SimpleActionClient<rrtplanner::rrtAction> ac;
};


#endif // RRTVIZ_H
