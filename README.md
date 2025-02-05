# Voxel Game Engine
![NetEngine GITHUB GIF](https://github.com/user-attachments/assets/71102885-45ec-4028-85ea-6c81e4fd2922)

A modern C++ game engine featuring voxel-based rendering, physics simulation, and modular architecture. This engine was going to be a voxel based renderer and is now being expanded into a full blown rendering engine.

## 🎮 Core Features

### Rendering System
- OpenGL-based rendering pipeline with support for:
  - Voxel-based terrain generation and rendering
  - Dynamic mesh generation and optimization
  - Multi-shader support (cube, terrain, skybox, player, lighting)
  - Texture atlas integration
  - Custom camera systems with free movement

### Input Management
- Dual-mode input system:
  - Camera mode for 3D navigation
  - UI mode for interface interaction
- Configurable key bindings
- Event-driven input handling
- Mouse capture and movement tracking
- Smooth camera controls (WASD + mouse look)

### Physics System
- Bullet Physics integration offering:
  - Rigid body dynamics
  - Collision detection and response
  - Primitive shape support (boxes, planes)
  - Debug rendering capabilities
  - Custom physics configurations per object

### Resource Management
- Robust resource handling system for:
  - Textures
  - Shaders
  - Models
  - Memory optimization
  - Resource lifetime management

### Chunk System
- Voxel-based chunk management:
  - 16x16x16 chunk size
  - Multiple block types (Air, Dirt, Grass, Stone)
  - Efficient face culling
  - Dynamic mesh generation
  - UV mapping for texture atlas

### Primitive System
- Support for basic 3D primitives:
  - Cubes
  - Planes
  - Dynamic primitive creation
  - Physics integration
  - Transform manipulation

## 🛠️ Technical Architecture

### Manager Template System
```cpp
template <typename Derived, typename T>
class Manager
```
- Singleton pattern implementation
- Type-safe resource management
- Dynamic object creation and deletion
- Thread-safe instance handling

### Event System
- Event dispatcher for system-wide communication
- Support for:
  - Key events
  - Mouse events
  - Input mode changes
  - Custom event types

## 🚀 Getting Started

### Prerequisites
- Modern C++ compiler (C++17 or later)
- OpenGL 4.0+
- Bullet Physics library
- GLM math library
- GLFW window management library

### Building the Project
1. Open .sln file using visual studio
2. Execute code in Debug or Release.

CMake configuration coming soon!

## 🤝 Contributing

Feel free to contribute to this project. Please follow these steps:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙏 Acknowledgments

- Bullet Physics for the physics engine
- OpenGL for rendering capabilities
- GLFW for window management
- GLM for mathematics utilities
