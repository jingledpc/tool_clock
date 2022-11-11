# 应对rosbag的时间和msg的时间戳不一致，导致rviz等显示错误的问题。

1.rosbag play xxx.bag

2.roslauch 文件中设置
```
<param name="/use_sim_time" value="true" />
```

3. 运行此包
```
roslaunch roslaunch clock_tools pubClockFromImu.launch
```