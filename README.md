# EOS Migrate Smart Contract Demo

### Description
When updating a smart contract, it is often necessary to make modifications to structs stored in tables. However, due to the
way EOS Smart Contracts work, if there is existing data in a table that gets modified, it will become invalid with the new
struct format. This example smart contract shows a method of migrating data from one table to another, allowing the user to
modify the old table.

### Building
  - cd to 'build' directory
  - run the command 'cmake ..'
  - run the command 'make'

### Deploying
  - The built smart contract is under the 'migratedemo' directory in the 'build' directory
  - You can then do a 'set contract' action with 'cleos' and point in to the './build/migratedemo' directory

### Additions to CMake should be done to the CMakeLists.txt in the './src' directory and not in the top level CMakeLists.txt
