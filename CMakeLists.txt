cmake_minimum_required(VERSION 3.1)
project(WorbleRay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    AmbientLight.cpp
    AmbientLight.h
    Camera.cpp
    Camera.h
    Color.cpp
    Color.h
    Framebuffer.cpp
    Framebuffer.h
    Intersection.cpp
    Intersection.h
    GeometricObject.cpp
    GeometricObject.h
    LambertMaterial.cpp
    LambertMaterial.h
    Light.cpp
    Light.h
    main.cpp
    Material.h
    OrthographicCamera.cpp
    OrthographicCamera.h
    Plane.cpp
    Plane.h
    PointD.cpp
    PointD.h
    PointLight.cpp
    PointLight.h
    Ray.cpp
    Ray.h
    SDLWindow.cpp
    SDLWindow.h
    Scene.cpp
    Scene.h
    Sphere.cpp
    Sphere.h
    VectorD.cpp
    VectorD.h
    NOTES.md
    README.md
)

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

