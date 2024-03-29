#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "hodarfeat.h"

using namespace std;
using namespace cv;

featDetect::pointStructure featDetect::intakeImg(const std::string& path1, const std::string& path2)
{
    Mat img_1 = imread ( path1, CV_LOAD_IMAGE_COLOR );
    Mat img_2 = imread ( path2, CV_LOAD_IMAGE_COLOR );


    std::vector<KeyPoint> keypoints_1, keypoints_2;
    Mat descriptors_1, descriptors_2;
    Ptr<FeatureDetector> detector = ORB::create();
    Ptr<DescriptorExtractor> descriptor = ORB::create();

    Ptr<DescriptorMatcher> matcher  = DescriptorMatcher::create ( "BruteForce-Hamming" );


    detector->detect ( img_1,keypoints_1 );
    detector->detect ( img_2,keypoints_2 );


    descriptor->compute ( img_1, keypoints_1, descriptors_1 );
    descriptor->compute ( img_2, keypoints_2, descriptors_2 );

    Mat outimg1;
    drawKeypoints( img_1, keypoints_1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    imshow("Points",outimg1);


    vector<DMatch> matches;
    vector<vector<int>> matchVect;

    //BFMatcher matcher ( NORM_HAMMING );
    matcher->match ( descriptors_1, descriptors_2, matches );


    double min_dist=10000, max_dist=0;


    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if ( dist < min_dist ) min_dist = dist;
        if ( dist > max_dist ) max_dist = dist;
    }

    //printf ( "-- Max dist : %f \n", max_dist );
    //printf ( "-- Min dist : %f \n", min_dist );


    std::vector<DMatch> good_matches;
    pointStructure goodVect;


    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        if ( matches[i].distance <= max ( 2*min_dist, 30.0 ) )
        {
            good_matches.push_back ( matches[i] );
            goodVect.x1.push_back( keypoints_1[matches[i].trainIdx].pt.x);
            goodVect.y1.push_back( keypoints_1[matches[i].trainIdx].pt.y);
            goodVect.x2.push_back( keypoints_2[matches[i].queryIdx].pt.x);
            goodVect.y2.push_back( keypoints_2[matches[i].queryIdx].pt.y);

            goodVect.hammDistance.push_back( matches[i].distance);

        }
    }

    Mat img_match;
    Mat img_goodmatch;
    drawMatches ( img_1, keypoints_1, img_2, keypoints_2, matches, img_match );
    drawMatches ( img_1, keypoints_1, img_2, keypoints_2, good_matches, img_goodmatch );
    imshow ( "Match", img_match );
    imshow ( "Good match", img_goodmatch );
    waitKey(0);

    return goodVect;
}
