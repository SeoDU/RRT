#include <rrtplanner/rrtviz.h>

Rrtviz::Rrtviz(ros::NodeHandle& nh)
  : nh(nh)
  , ac("rrt",true)
  , odomClient(nh.subscribe("/odom", 100, &Rrtviz::odomCallback, this))
  , rvizClient(nh.subscribe("/move_base_simple/goal", 10, &Rrtviz::rvizCallback, this))
{
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time
}
void Rrtviz::rvizCallback(const geometry_msgs::PoseStamped& pose)
{
  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  rrtplanner::rrtGoal goal;
  goal.start.header = pose_now.header;
  goal.start.pose = pose_now.pose.pose;

  geometry_msgs::Pose new_pose = pose.pose;
  new_pose.position.z += goal.start.pose.position.z; // 2D 인것을 감안
  goal.goal_poses.header = pose.header;
  goal.goal_poses.poses.push_back(new_pose);

  ac.sendGoal(goal);
  bool finished_before_timeout = ac.waitForResult(ros::Duration(60.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("RRT finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("RRT did not finish before the time out.");
}


void Rrtviz::odomCallback(const nav_msgs::Odometry& pose)
{
  pose_now = pose;
}



