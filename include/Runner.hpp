#pragma once


#include <AllegroFlare/EventEmitter.hpp>
#include <AllegroFlare/Frameworks/Full.hpp>
#include <AllegroFlare/GameEvent.hpp>
#include <AllegroFlare/Screens/Base.hpp>
#include <string>


class Runner : public AllegroFlare::Screens::Base
{
private:
   AllegroFlare::Frameworks::Full* framework;
   AllegroFlare::EventEmitter* event_emitter;

public:
   Runner(AllegroFlare::Frameworks::Full* framework=nullptr, AllegroFlare::EventEmitter* event_emitter=nullptr);
   virtual ~Runner();

   virtual void game_event_func(AllegroFlare::GameEvent* ev=nullptr) override;
   static void run(std::string mode="production");
};



