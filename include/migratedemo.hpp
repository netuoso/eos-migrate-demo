/*
  Written by: @netuoso - EOS Titan
	This exmaple contract demonstrates how one may migrate data to a new table
	allowing them to safely modify the structure of the old table
*/

#include <eosio/eosio.hpp>
using namespace eosio;

CONTRACT migratedemo : public contract {
   public:
      using contract::contract;

      ACTION insert( );
      ACTION migrate( uint16_t version );

      using insert_action = action_wrapper<"insert"_n, &migratedemo::insert>;
      using migrate_action = action_wrapper<"migrate"_n, &migratedemo::migrate>;

   private:

		struct [[eosio::table]] item
		{
		    uint64_t id;
		    uint64_t type;

		    uint64_t primary_key() const { return id; }
		};

		struct [[eosio::table]] item2
		{
		    uint64_t id;
		    uint64_t type;
		    uint64_t state;

		    uint64_t primary_key() const { return id; }
		};

		typedef eosio::multi_index<"items"_n, item> items;
		typedef eosio::multi_index<"items2"_n, item2> items2;
};