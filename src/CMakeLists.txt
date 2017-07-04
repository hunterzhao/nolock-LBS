set(SOURCE_FILES
             databuffer.cc
             event_poll.cc
             lbs_server.cc
             message.pb.cc
             lbs_socket_event.cc
             listen_socket_event.cc
             notify_event.cc
             reactor.cc
             socket_event.cc
             log.cc
             parse_redis_proto.cc
             )

add_library(lbs STATIC ${SOURCE_FILES})
target_link_libraries(lbs)
add_library(lbs_so SHARED ${SOURCE_FILES})
set_target_properties(lbs_so PROPERTIES OUTPUT_NAME "lbs")
