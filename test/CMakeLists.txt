set(SERVER_SOURCE server.cc)
set(CLIENT_SOURCE client.cc message.pb.cc until.cc)

add_executable(server ${SERVER_SOURCE})
target_link_libraries(server lbs protobuf geo glog profiler tcmalloc)

add_executable(client ${CLIENT_SOURCE})
target_link_libraries(client protobuf hiredis)

