cmake_minimum_required(VERSION 3.16)

project(Doctor1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Charts Core Gui Qml Quick  REQUIRED)

qt_add_executable(appDoctor1
    main.cpp
    Server.h
    Server.cpp
    VieoModel.h
    VieoModel.cpp
    File.h File.cpp
)

qt_add_qml_module(appDoctor1
    URI Doctor1
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appDoctor1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDoctor1
    PRIVATE
    Qt::Charts
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    )

install(TARGETS appDoctor1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
