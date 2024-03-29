// $Id: debug.cpp,v 1.3 2019-10-22 12:41:48-07 - - $

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#include "debug.h"
#include "util.h"

debugflags::flagset debugflags::flags {};

void debugflags::setflags (const string& initflags) {
   for (const unsigned char flag: initflags) {
      if (flag == '@') flags.set();
                  else flags.set (flag, true);
   }
}

// getflag -
//    Check to see if a certain flag is on.
bool debugflags::getflag (char flag) {
   return flags.test (static_cast<unsigned char> (flag));
}

void debugflags::where (char flag, const char* file, int line,
                        const char* pretty_function) {
   // WARNING: Don't TRACE this function or the stack will blow up.
   cout << sys_info::execname() << ": DEBUG(" << flag << ") "
        << file << "[" << line << "] " << endl
        << "   " << pretty_function << endl;
}
