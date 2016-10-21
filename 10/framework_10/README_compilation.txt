
 *** Windows (Open VS2012 x64 command prompt)

# required libraries are in the folder 'freeglut'
cl main.cpp gl2ps.c matplotpp.cpp SimpleGraph.cpp  /I freeglut\include /link /LIBPATH:freeglut\lib\x64





 *** Linux (command line)

# install required libraries
sudo yum install freeglut-devel mesa-libGLU-devel

# compile
g++ main.cpp gl2ps.c matplotpp.cpp SimpleGraph.cpp -std=c++11 -lglut -lGL -lGLU -o main

# run
./main



