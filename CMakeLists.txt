cmake_minimum_required(VERSION 3.1)
project(WorbleRay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-DWORBLERAY_DEBUG")

add_executable(${PROJECT_NAME}
    base/Camera.cpp
    base/Camera.h
    base/Framebuffer.cpp
    base/Framebuffer.h
    base/GeometricObject.cpp
    base/GeometricObject.h
    base/Light.cpp
    base/Light.h
    base/Material.h
    core/Intersection.cpp
    core/Intersection.h
    core/Ray.cpp
    core/Ray.h
    core/Scene.cpp
    core/Scene.h
    impl/AmbientLight.cpp
    impl/AmbientLight.h
    impl/LambertMaterial.cpp
    impl/LambertMaterial.h
    impl/OrthographicCamera.cpp
    impl/OrthographicCamera.h
    impl/PerspectiveCamera.cpp
    impl/PerspectiveCamera.h
    impl/PhongMaterial.cpp
    impl/PhongMaterial.h
    impl/Plane.cpp
    impl/Plane.h
    impl/PointLight.cpp
    impl/PointLight.h
    impl/SDLWindow.cpp
    impl/SDLWindow.h
    impl/Sphere.cpp
    impl/Sphere.h
    util/Color.cpp
    util/Color.h
    util/log.h
    util/math.h
    util/PointD.cpp
    util/PointD.h
    util/VectorD.cpp
    util/VectorD.h
    main.cpp
    NOTES.md
    README.md
)

target_include_directories(${PROJECT_NAME} PRIVATE base)
target_include_directories(${PROJECT_NAME} PRIVATE core)
target_include_directories(${PROJECT_NAME} PRIVATE impl)
target_include_directories(${PROJECT_NAME} PRIVATE util)

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
