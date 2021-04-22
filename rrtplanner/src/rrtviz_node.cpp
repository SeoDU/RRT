#include <rrtplanner/rrtviz.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rrtviz");
  ros::NodeHandle nh;

  Rrtviz rrt(nh);

  ros::spin();
  return 0;
}
