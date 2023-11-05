## Installation guide

### Ubuntu and other Debian based distributions

```sudo apt install cmake make libopengl-dev libbullet-dev libfreetype6-dev libstb-dev libglfw3-dev libglm-dev ```

### RHEL, Fedora, and CentOS based distributions

```sudo dnf install cmake make mesa-libGL-devel bullet-devel freetype-devel stb-devel glfw-devel glm-devel```

## After completing the OS guide

```cmake -S . -B build```
```cd build && make```