# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(qt_d3d11_window LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "${CMAKE_CURRENT_SOURCE_DIR}")
endif()


set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/opengl/openglwindow")

find_package(Qt6 REQUIRED COMPONENTS Core Gui)
find_library(D3D12_TARGET NAMES d3d11 REQUIRED)

qt_standard_project_setup()

qt_add_executable(d3d11window
    main.cpp
    D3D11Window.cpp D3D11Window.hpp
    D3D11Context.cpp D3D11Context.hpp
)

set_target_properties(d3d11window PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(d3d11window PRIVATE
    Qt6::Core
    Qt6::Gui
    d3d11
)

install(TARGETS d3d11window
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
