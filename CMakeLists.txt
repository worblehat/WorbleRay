cmake_minimum_required(VERSION 3.1)
project(WorbleRay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    AmbientLight.cpp
    Camera.cpp
    LambertMaterial.cpp
    main.cpp
    OrthographicCamera.cpp
    Plane.cpp
    PointLight.cpp
    SDLWindow.cpp
    Scene.cpp
    Sphere.cpp
)

find_package(glm REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_INCLUDE_DIRS})

find_package(SDL REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL_LIBRARY})

