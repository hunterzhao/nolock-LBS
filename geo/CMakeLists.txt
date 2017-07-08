set(SOURCE_FILES
             geointerface.cc
             geohash.cc
             trie_tree.cc
             )

add_library(geo STATIC ${SOURCE_FILES})
target_link_libraries(geo)

add_library(geo_so SHARED ${SOURCE_FILES})
target_link_libraries(geo_so)
set_target_properties(geo_so PROPERTIES OUTPUT_NAME "geo")

#add_library(geo_so SHARED ${SOURCE_FILES})
#
