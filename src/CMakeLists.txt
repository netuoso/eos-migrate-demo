project(migratedemo)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( migratedemo migratedemo migratedemo.cpp )
target_include_directories( migratedemo PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( migratedemo ${CMAKE_SOURCE_DIR}/../ricardian )