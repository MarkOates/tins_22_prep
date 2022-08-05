

#include <GameConfigurations/First.hpp>
#include <AllegroFlare/Prototypes/FixedRoom2D/EntityFactory.hpp>
#include <AllegroFlare/Prototypes/FixedRoom2D/RoomFactory.hpp>
#include <stdexcept>
#include <sstream>


namespace GameConfigurations
{


First::First()
{
}


First::~First()
{
}


AllegroFlare::Prototypes::FixedRoom2D::Configuration First::build(AllegroFlare::BitmapBin* bitmap_bin, AllegroFlare::FontBin* font_bin, AllegroFlare::EventEmitter* event_emitter, AllegroFlare::Prototypes::FixedRoom2D::EntityCollectionHelper* entity_collection_helper__this_is_a_hack)
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "First" << "::" << "build" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "First" << "::" << "build" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(event_emitter))
      {
         std::stringstream error_message;
         error_message << "First" << "::" << "build" << ": error: " << "guard \"event_emitter\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(entity_collection_helper__this_is_a_hack))
      {
         std::stringstream error_message;
         error_message << "First" << "::" << "build" << ": error: " << "guard \"entity_collection_helper__this_is_a_hack\" not met";
         throw std::runtime_error(error_message.str());
      }
   AllegroFlare::Prototypes::FixedRoom2D::Configuration result;

   AllegroFlare::InventoryIndex &inventory_index = result.get_inventory_index_ref();
   AllegroFlare::Inventory &af_inventory = result.get_af_inventory_ref();
   AllegroFlare::Inventory &flags = result.get_flags_ref();
   std::map<std::string, AllegroFlare::Prototypes::FixedRoom2D::Entities::Base*> &entity_dictionary =
      result.get_entity_dictionary_ref();
   std::map<std::string, AllegroFlare::Prototypes::FixedRoom2D::Room*> &room_dictionary =
      result.get_room_dictionary_ref();
   std::map<std::string, std::string> &entity_room_associations =
      result.get_entity_room_associations_ref();
   std::map<std::string, AllegroFlare::Prototypes::FixedRoom2D::Script> &script_dictionary =
      result.get_script_dictionary_ref();
   std::string &starting_in_room_identifier = result.get_starting_in_room_identifier_ref();


   AllegroFlare::Prototypes::FixedRoom2D::EntityFactory entity_factory(bitmap_bin);
   AllegroFlare::Prototypes::FixedRoom2D::RoomFactory room_factory(
      bitmap_bin, font_bin, event_emitter, entity_collection_helper__this_is_a_hack
   );

   inventory_index = AllegroFlare::InventoryIndex::build_placeholder_inventory_index();

   af_inventory.add_item(1);
   af_inventory.add_item(4);
   af_inventory.add_item(3);

   room_dictionary = {
      { "front_hall", room_factory.create_room() },
      { "study", room_factory.create_room() },
   };

   entity_dictionary = {
      { "front_hall_bg", entity_factory.create_entity("room_0.png",
            1920/2, 1080, 1.0, "Background", "observe_front_hall") },
      { "main_hall_bg", entity_factory.create_entity("room_1.png",
            1920/2, 1080, 1.0, "Background", "observe_main_hall") },
      { "door1", entity_factory.create_entity(
            "download-door-png-transparent-image-and-clipart-3.png", 1400, 800, 0.85, "Door 1", "observe_door1") },
      { "door2", entity_factory.create_entity(
            "download-door-png-transparent-image-and-clipart-3.png", 500, 800, 0.85, "Door 2", "observe_door2") },
   };

   entity_room_associations = {
      { "front_hall_bg", "front_hall" },
      { "main_hall_bg", "study" },
      { "door1", "front_hall" },
      { "door2", "study" },
      { "chair", "front_hall" },
      { "table", "front_hall" },
      { "keys", "front_hall" },
   };

   script_dictionary = {
      { "observe_front_hall", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "DIALOG: This is a pretty dark room. | It's kinda hard to see anything, to be honest."
      })},
      { "observe_main_hall", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "DIALOG: This is a pretty dark room. | It's kinda hard to see anything, to be honest."
      })},
      { "observe_door1", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "DIALOG: Just a regular door. | I'm going to step through it.",
            "ENTER_ROOM: study",
      })},
      { "observe_door2", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "DIALOG: A regular door. | I'll to in.",
            "ENTER_ROOM: front_hall",
      })},
      { "signal_hello", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "SIGNAL: Hello what's going on?"})
      },
      { "collect_keys", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "COLLECT: keys"
      })},
      { "observe_table", AllegroFlare::Prototypes::FixedRoom2D::Script({
            "DIALOG: Hmm. Interesting, there's a key on this table."
      })},
   };

   starting_in_room_identifier = "front_hall";
    
   return result;
}
} // namespace GameConfigurations


