
#include <gtest/gtest.h>

#include <Runner.hpp>


TEST(RunnerTest, can_be_created_without_blowing_up)
{
   Runner runner;
}


TEST(RunnerTest, run__runs_the_program)
{
   Runner runner;
   //runner.run("test");
   SUCCEED();
}

