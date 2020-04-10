#include <iostream>
#include <vector>
#include <string>
#include "hodarfeat.h"

using namespace std;


int main ( int argc, char** argv )
{
    std::string current_exec_name = argv[0];
     std::vector<std::string> all_args;

     if (argc > 1) {
       all_args.assign(argv + 1, argv + argc);
     }

    featDetect myFeats;

    myFeats.intakeImg(all_args[0], all_args[1]);

    return 0;
}
