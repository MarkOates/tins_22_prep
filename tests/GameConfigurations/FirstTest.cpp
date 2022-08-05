
#include <gtest/gtest.h>

#include <GameConfigurations/First.hpp>


TEST(GameConfigurations_FirstTest, can_be_created_without_blowing_up)
{
   GameConfigurations::First first;
}


#include <Runner.hpp>

TEST(RunnerTest, run__runs_the_program)
{
   Runner runner;
   runner.run("test");
   SUCCEED();
}


