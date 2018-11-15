#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "TestClient");

  actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac("follow_joint_trajectory_action", true);
  ac.waitForServer();

  control_msgs::FollowJointTrajectoryGoal goal;

  ac.sendGoal(goal);

  if (!ac.waitForResult(ros::Duration(5.0)))
  {
    ROS_ERROR("waitForResult timeout");
    while (1);
  }

  ros::shutdown();

  return 0;
}
