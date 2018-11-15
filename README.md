# action_test_case2
Reproduction code: [SimpleActionClient sometimes not subscribe result topic](https://github.com/ros/actionlib/issues/119, "ros/actionlib/issues/119")

This test case tries action client launch and exit only loop, as keep launching action server.
I tested this and the issue was reproduced twice in 8,609 tries.
Reconnection of the action client is assumed to occur occasionally. For example, it may be due to the respawn option of launch file.

[![Build Status](https://travis-ci.org/k-sawa/action_test_case2.svg?branch=master)](https://travis-ci.org/k-sawa/action_test_case2)

Note: On the Travis CI environment, reproduction test may not be running well because of a timeout. Please execute on your local PC.

```
$ roslaunch action_test loop_test.launch
```
