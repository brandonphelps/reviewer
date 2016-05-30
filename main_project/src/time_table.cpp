

#include "time_table.h"

#include <iostream>

int data_map[] = { 5,    10,   20,   40,   80,  120,
                   80,  120,  160,  200,  260,  360,
                   160, 200,  260,  360,  460,  600,
                   600, 900, 1200, 1800, 2400, 3000,
                   2400,3000, 5000, 7000, 10000, 12000,
                   10000, 12000, 15000, 20000, 25000, 30000};

int data_map_width = 6;


int computeTime(int x, int y)
{
  std::cout << "Adding: " << data_map[x * data_map_width + y] << std::endl;
  
  return data_map[x * data_map_width + y];
}

