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
    Color.h
    Framebuffer.h
    LambertMaterial.cpp
    LambertMaterial.h
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

find_package(glm REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_INCLUDE_DIRS})

find_package(SDL REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL_LIBRARY})

