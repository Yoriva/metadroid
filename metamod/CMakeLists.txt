cmake_minimum_required(VERSION 3.19)
project(metamod CXX)

if(ANDROID_ABI STREQUAL "arm64-v8a")
	set(ARCH_SUFFIX "arm64")
elseif(ANDROID_ABI STREQUAL "armeabi-v7a")
	set(ARCH_SUFFIX "armv7l")
else()
	message(FATAL_ERROR "Unsupported ANDROID_ABI: ${ANDROID_ABI}")
endif()

set(PROJECT_HEADERS_DIR
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/include/engine"
	"${PROJECT_SOURCE_DIR}/include/common"
	"${PROJECT_SOURCE_DIR}/include/dlls"
	"${PROJECT_SOURCE_DIR}/include/game_shared"
	"${PROJECT_SOURCE_DIR}/include/pm_shared"
	"${PROJECT_SOURCE_DIR}/include/public"
	"${CMAKE_CURRENT_BINARY_DIR}"
)

set(METAMOD_SOURCES
	"src/api_info.cpp"
	"src/commands_meta.cpp"
	"src/conf_meta.cpp"
	"src/dllapi.cpp"
	"src/engine_api.cpp"
	"src/game_support.cpp"
	"src/h_export.cpp"
	"src/log_meta.cpp"
	"src/mdebug.cpp"
	"src/meta_rehlds_api.cpp"
	"src/metamod.cpp"
	"src/metamod_physics.cpp"
	"src/mextdll.cpp"
	"src/mlist.cpp"
	"src/mplayer.cpp"
	"src/mplugin.cpp"
	"src/mreg.cpp"
	"src/mutil.cpp"
	"src/precompiled.cpp"
	"src/public_amalgamation.cpp"
	"src/reg_support.cpp"
	"src/sdk_util.cpp"
	"src/studioapi.cpp"
	"src/sys_module.cpp"
	"src/utils.cpp"

	"${PROJECT_SOURCE_DIR}/version/appversion.h"
)

add_library(metamod SHARED ${METAMOD_SOURCES})
set_target_properties(metamod PROPERTIES
	POSITION_INDEPENDENT_CODE ON
	OUTPUT_NAME "metadroid_android_${ARCH_SUFFIX}"
)
target_include_directories(metamod PRIVATE ${PROJECT_HEADERS_DIR})
target_compile_options(metamod PRIVATE
	-Wall -Wextra -Wno-unused-parameter
	-fno-exceptions
	-fno-builtin
	-Wno-unknown-pragmas
)
target_compile_definitions(metamod PRIVATE
	METAMOD_CORE
	NDEBUG
	LINUX
	_LINUX
	_stricmp=strcasecmp
	_strnicmp=strncasecmp
	_strdup=strdup
	_unlink=unlink
	_write=write
	_close=close
	_getcwd=getcwd
	_vsnprintf=vsnprintf
	_snprintf=snprintf
)
target_link_libraries(metamod PRIVATE dl)

install(TARGETS metamod LIBRARY DESTINATION addons/metamod PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
install(FILES "${PROJECT_SOURCE_DIR}/extra/config.ini" "${PROJECT_SOURCE_DIR}/extra/plugins.ini" DESTINATION addons/metamod PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
