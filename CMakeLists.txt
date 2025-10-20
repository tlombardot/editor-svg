cmake_minimum_required(VERSION 4.0)
project(editor_svg C)

set(CMAKE_C_STANDARD 11)

include_directories(components)
include_directories(config)
include_directories(svg)
include_directories(utils)

add_executable(editor_svg
        components/create.c
        components/create.h
        components/edit.c
        components/edit.h
        components/get.c
        components/get.h
        components/list.c
        components/list.h
        components/remove.c
        components/remove.h
        config/allocate.c
        config/allocate.h
        config/color.h
        config/path.c
        config/path.h
        config/struct.h
        config/style.c
        config/style.h
        svg/load_svg.c
        svg/load_svg.h
        svg/svg.c
        svg/svg.h
        utils/interface_path.c
        utils/interface_path.h
        utils/windows_user.c
        utils/windows_user.h
        main.c
        svg/load_svg.h)
