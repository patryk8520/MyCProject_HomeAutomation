cmake_minimum_required(VERSION 3.7)
project(MyCProject)
add_executable(MyCProject Definitions.h main.c ModbusRtu.c
        dht11.c Socket.h Socket.c
        Button.c button.h dht11.h
        modbusRtu.h database.h Database.c)

include_directories(/usr/include/modbus)
find_library(MyModbus modbus lib)
find_library(Bcm bcm2835 lib)
target_link_libraries(MyCProject LINK_PUBLIC ${MyModbus})
target_link_libraries(MyCProject LINK_PUBLIC ${Bcm})
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ldl -lpthread -lmysqlclient")