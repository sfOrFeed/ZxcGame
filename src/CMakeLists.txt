add_executable(ZxcGame_exe main.cpp Game.cpp Game.h)
target_link_libraries(ZxcGame_exe PRIVATE ImGui-SFML::ImGui-SFML)

if (WIN32)
    if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET ZxcGame_exe POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
                $<TARGET_FILE:sfml-graphics>
                $<TARGET_FILE:sfml-window>
                $<TARGET_FILE:sfml-system>
                $<TARGET_FILE:sfml-audio>
                $<TARGET_FILE:sfml-network>
                $<TARGET_FILE_DIR:ZxcGame_exe>)
    endif ()
endif ()