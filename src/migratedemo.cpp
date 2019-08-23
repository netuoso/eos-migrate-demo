/*
  Written by: @netuoso - EOS Titan
  This exmaple contract demonstrates how one may migrate data to a new table
  allowing them to safely modify the structure of the old table
*/

#include <migratedemo.hpp>

ACTION migratedemo::insert() {
  items items_table(_self, _self.value);
  items_table.emplace(_self, [&](auto& o){
    o.id = items_table.available_primary_key();
    o.type = 1;
  });
}

ACTION migratedemo::migrate( uint16_t version ) {
  /*
    This function will move the data from items to items2 or vice versa
    depending on the version number that is specified in the action call
    When a table is empty, it is safe to modify the table structure
  */

  if( version == 1 ) { // move rows from items_table to items_table2

    items items_table(_self, _self.value);
    items2 items_table2(_self, _self.value);

    auto itr = items_table.begin();

    while( itr != items_table.end() ){
      items_table2.emplace(_self, [&](auto& o){
        o.id = items_table2.available_primary_key();
        o.type = itr->type;
        o.state = 1; // some logic or default value here
      });
      itr = items_table.erase(itr);
    }
  } else if ( version == 2) { // move rows from items_table2 to items_table

    items items_table(_self, _self.value);
    items2 items_table2(_self, _self.value);

    auto itr = items_table2.begin();

    while( itr != items_table2.end() ){
      items_table.emplace(_self, [&](auto& o){
        o.id = items_table.available_primary_key();
        o.type = itr->type;
      });
      itr = items_table2.erase(itr);
    }
  }

 }