# hodarFeat

Library requirements:
libeigen3-dev
libopencv-dev

cmake files included if you need them.

feature_extraction is an example of calling hodarFeats intakeImg function. The function is implemeneted in hodarfeat.cpp.

The function requires two images on disk - their locations passed as strings, all general file formats work. (JPG PNG etc etc).
If you want I can alter it to all any byte array, or image type in memory as opposed to saved on disk.

The function in the header file constructs a class named featDetect, wherein two objects of importance are prototyped:

pointStructure: Which returns the two points matched between images (x1,x2,y1,y2)
and the Hamming Distance  - i.e. the "power" of the match. Less being more.

For debugs sake you get to see all the points created in a window.



## Option 1: run with example call:

mkdir build
cd build
cmake ..
make -j4
./feature_extraction imgage1.png image2.png

## Option 2: include header

Simply drop the cpp, and h file in your include or libraries directory, include the .h file in your main program source and pass images at your whim. Naturally to store the
return you will need to create an instance of the object pointStructure in your code i.e: 

featDetect::pointStructure points = inTakeImg( path1, path2 )







