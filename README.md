# OpenRaven
Robotic Assistant for Versatile Everyday Needs

Raven is an open-source home assistant robot with a 5-DOF robotic arm and a differential drive base. It's currently teleoperated, with plans to add full autonomy soon.

> 🚧 This project is in early stages. The arm is functional via LeRobot, and the base runs on simple firmware + a ROS 2 node. Autonomy stack (SLAM, Nav2, perception) coming soon.

---

## Components

- **Arm:** Built using [LeRobot](https://github.com/huggingface/lerobot)  
  → Follow their instructions to set up arm teleop.

- **Chassis:** Basic firmware on an Arduino Uno + ROS 2 Jazzy node for `cmd_vel` + odometry

---

## Contributing

This is a WIP. If you’re interested in helping, join the Discord and let’s build together:  
[→ Join the community](https://discord.gg/2hJphAAZ3J)

---

## Credits

- Robot arm powered by [LeRobot](https://github.com/huggingface/lerobot)  
- Built during the Localhost India Fellowship

---

*More docs, autonomy stack, and setup guides coming soon.*



