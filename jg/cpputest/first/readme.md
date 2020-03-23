# cpputest 

## Instalation
Clone cpputest source [from github][1]
Installed as indicated in github (autotools)
- autogen.sh (autoreconf)
- make a build directory and cd too it
- configure ../configure
- make check and install
  Files are at `/usr/local` (config CPPUTEST_HOME in makefiles )

## First example  
Project directory structure
.
├── Makefile          -- Project's 
├── src               -- Production code folder
│   ├── code  
│   │   ├── code.cpp  -- CUT
│   │   └── code.h    -- interface
│   ├── main.cpp      -- Production main
│   └── Makefile      -- production's 
└── t                 -- test code 
    ├── main.cpp      -- test main calls runner
    ├── Makefile      -- test's includes MakefileWrker.mk 
    ├── MakefileWorker.mk
    └── test.cpp      -- collects the tests


[1]:https://github.com/cpputest/cpputest.git
