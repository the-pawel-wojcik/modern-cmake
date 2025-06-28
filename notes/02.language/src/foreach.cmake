cmake_minimum_required(VERSION 3.30)

message("-- foreach(idx RANGE 3)")
foreach(idx RANGE 3)
    message(" ${idx}")
endforeach()

message("-- foreach(idx RANGE start stop step)")
foreach(idx RANGE 7 11 2)
    message(" ${idx}")
endforeach()

set(myList every day and every night)
message("-- foreach(word IN LISTS myList)" )
foreach(word IN LISTS myList)
    message(" ${word}")
endforeach()

set(polski "przestrzeń;pole;macierz")
set(english "space;field;matrix")
message("-- foreach(pl en IN ZIP_LISTS polski english)" )
foreach(pl en IN ZIP_LISTS polski english)
    message(" ${pl} ${en}")
endforeach()

message("-- mixed foreach" )
foreach(word IN LISTS myList ITEMS 3 1 LISTS polski ITEMS 0x1d LISTS english)
    message(" ${word}")
endforeach()
