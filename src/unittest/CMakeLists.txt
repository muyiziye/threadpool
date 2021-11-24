project(unittest)

include_directories(
    ${EXTLIBS_PATH}/include/
)

set(${PROJECT_NAME}_SRC 
    main.cpp
)

find_library(LOGSYSTEM_PATH NAMES logsystem HINTS ${EXTLIBS_PATH}/lib/)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})

target_link_libraries(${PROJECT_NAME} 
    ${LOGSYSTEM_PATH}
)

install(TARGETS ${PROJECT_NAME} 
    DESTINATION ${OUTPUT_PATH}/bin
)
