#ifndef HODARFEAT_H
#define HODARFEAT_H
#endif

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

class featDetect
{

public:    

    struct pointStructure{
        std::vector<float> x1;
        std::vector<float> y1;
        std::vector<float> x2;
        std::vector<float> y2;
        std::vector<float> hammDistance; //How good are the matches (lower is better).
    };

    pointStructure intakeImg(const std::string&, const std::string&);
/*private:

    Mat img_1;
    Mat img_2;
    std::vector<KeyPoint> keypoints_1, keypoints_2;
    Mat descriptors_1, descriptors_2;
    Mat outimg1;
    vector<DMatch> matches;
    double min_dist=10000, max_dist=0;
    std::vector< DMatch > good_matches;
    Mat img_match;
    Mat img_goodmatch;
*/

};
