
#include "xTest.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#pragma comment(lib, "opencv_core300d.lib")
#pragma comment(lib, "opencv_imgproc300d.lib")
#pragma comment(lib, "opencv_highgui300d.lib")

namespace space_test_cv {
	using namespace cv;

	#define w 400

	void MyEllipse( Mat img, double angle )
	{
		int thickness = 2;
		int lineType = 8;

		ellipse( img,
			Point( w/2, w/2 ),
			Size( w/2, w/8 ),
			angle,
			0,
			360,
			Scalar( 255, 255, 0 ),
			thickness,
			lineType );
	}

	void MyFilledCircle( Mat img, Point center )
	{
		int thickness = -1;
		int lineType = 8;

		circle( img,
			center,
			w/32,
			Scalar( 0, 0, 255 ),
			thickness,
			lineType );
	}

	void MyPolygon( Mat img )
	{
		int lineType = 8;

		/** Create some points */
		Point rook_points[1][20];
		rook_points[0][0]  = Point(    w/4,   7*w/8 );
		rook_points[0][1]  = Point(  3*w/4,   7*w/8 );
		rook_points[0][2]  = Point(  3*w/4,  13*w/16 );
		rook_points[0][3]  = Point( 11*w/16, 13*w/16 );
		rook_points[0][4]  = Point( 19*w/32,  3*w/8 );
		rook_points[0][5]  = Point(  3*w/4,   3*w/8 );
		rook_points[0][6]  = Point(  3*w/4,     w/8 );
		rook_points[0][7]  = Point( 26*w/40,    w/8 );
		rook_points[0][8]  = Point( 26*w/40,    w/4 );
		rook_points[0][9]  = Point( 22*w/40,    w/4 );
		rook_points[0][10] = Point( 22*w/40,    w/8 );
		rook_points[0][11] = Point( 18*w/40,    w/8 );
		rook_points[0][12] = Point( 18*w/40,    w/4 );
		rook_points[0][13] = Point( 14*w/40,    w/4 );
		rook_points[0][14] = Point( 14*w/40,    w/8 );
		rook_points[0][15] = Point(    w/4,     w/8 );
		rook_points[0][16] = Point(    w/4,   3*w/8 );
		rook_points[0][17] = Point( 13*w/32,  3*w/8 );
		rook_points[0][18] = Point(  5*w/16, 13*w/16 );
		rook_points[0][19] = Point(    w/4,  13*w/16 );

		const Point* ppt[1] = { rook_points[0] };
		int npt[] = { 20 };

		fillPoly( img,
			ppt,
			npt,
			1,
			Scalar( 255, 255, 255 ),
			lineType );
	}

	void MyLine( Mat img, Point start, Point end )
	{
		int thickness = 2;
		int lineType = 8;
		line( img,
			start,
			end,
			Scalar( 0, 0, 0 ),
			thickness,
			lineType );
	}

	void test1()
	{
		/// Windows names
		char atom_window[] = "Drawing 1: Atom";
		char rook_window[] = "Drawing 2: Rook";

		/// Create black empty images
		Mat atom_image = Mat::zeros( w, w, CV_8UC3 );
		Mat rook_image = Mat::zeros( w, w, CV_8UC3 );

		/// 1. Draw a simple atom:
		/// -----------------------

		/// 1.a. Creating ellipses
		MyEllipse( atom_image, 90 );
		MyEllipse( atom_image, 0 );
		MyEllipse( atom_image, 45 );
		MyEllipse( atom_image, -45 );

		/// 1.b. Creating circles
		MyFilledCircle( atom_image, Point( w/2, w/2) );

		/// 2. Draw a rook
		/// ------------------

		/// 2.a. Create a convex polygon
		MyPolygon( rook_image );

		/// 2.b. Creating rectangles
		rectangle( rook_image,
			Point( 0, 7*w/8 ),
			Point( w, w),
			Scalar( 0, 255, 255 ),
			-1,
			8 );

		/// 2.c. Create a few lines
		MyLine( rook_image, Point( 0, 15*w/16 ), Point( w, 15*w/16 ) );
		MyLine( rook_image, Point( w/4, 7*w/8 ), Point( w/4, w ) );
		MyLine( rook_image, Point( w/2, 7*w/8 ), Point( w/2, w ) );
		MyLine( rook_image, Point( 3*w/4, 7*w/8 ), Point( 3*w/4, w ) );

		/// 3. Display your stuff!
		imshow( atom_window, atom_image );
		moveWindow( atom_window, 0, 200 );
		imshow( rook_window, rook_image );
		moveWindow( rook_window, w, 200 );

		waitKey( 0 );

	}


	/// Global Variables
	const int NUMBER = 100;
	const int DELAY = 5;

	const int window_width = 900;
	const int window_height = 600;
	int x_1 = -window_width/2;
	int x_2 = window_width*3/2;
	int y_1 = -window_width/2;
	int y_2 = window_width*3/2;

	/// Function definitions

	/**
	 * @function randomColor
	 * @brief Produces a random color given a random object
	 */
	static Scalar randomColor( RNG& rng )
	{
	  int icolor = (unsigned) rng;
	  return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
	}


	/**
	 * @function Drawing_Random_Lines
	 */
	int Drawing_Random_Lines( Mat image, char* window_name, RNG rng )
	{
		Point pt1, pt2;

		for( int i = 0; i < NUMBER; i++ )
		{
			pt1.x = rng.uniform( x_1, x_2 );
			pt1.y = rng.uniform( y_1, y_2 );
			pt2.x = rng.uniform( x_1, x_2 );
			pt2.y = rng.uniform( y_1, y_2 );

			line( image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), 8 );
			imshow( window_name, image );
			if( waitKey( DELAY ) >= 0 )
			{ 
				return -1; 
			}
		}

	  return 0;
	}

	/**
	 * @function Drawing_Rectangles
	 */
	int Drawing_Random_Rectangles( Mat image, char* window_name, RNG rng )
	{
		Point pt1, pt2;
		int lineType = 8;
		int thickness = rng.uniform( -3, 10 );

		for( int i = 0; i < NUMBER; i++ )
		{
			pt1.x = rng.uniform( x_1, x_2 );
			pt1.y = rng.uniform( y_1, y_2 );
			pt2.x = rng.uniform( x_1, x_2 );
			pt2.y = rng.uniform( y_1, y_2 );

			rectangle( image, pt1, pt2, randomColor(rng), MAX( thickness, -1 ), lineType );

			imshow( window_name, image );
			if( waitKey( DELAY ) >= 0 )
			{ 
				return -1; 
			}
		}

		return 0;
	}

	/**
	 * @function Drawing_Random_Ellipses
	 */
	int Drawing_Random_Ellipses( Mat image, char* window_name, RNG rng )
	{
		int lineType = 8;

		for ( int i = 0; i < NUMBER; i++ )
		{
			Point center;
			center.x = rng.uniform(x_1, x_2);
			center.y = rng.uniform(y_1, y_2);

			Size axes;
			axes.width = rng.uniform(0, 200);
			axes.height = rng.uniform(0, 200);

			double angle = rng.uniform(0, 180);

			ellipse( image, center, axes, angle, angle - 100, angle + 200,
					 randomColor(rng), rng.uniform(-1,9), lineType );

			imshow( window_name, image );

			if( waitKey(DELAY) >= 0 )
			{ 
				return -1;
			}
		}

	  return 0;
	}

	/**
	 * @function Drawing_Random_Polylines
	 */
	int Drawing_Random_Polylines( Mat image, char* window_name, RNG rng )
	{
		int lineType = 8;

		for( int i = 0; i< NUMBER; i++ )
		{
			Point pt[2][3];
			pt[0][0].x = rng.uniform(x_1, x_2);
			pt[0][0].y = rng.uniform(y_1, y_2);
			pt[0][1].x = rng.uniform(x_1, x_2);
			pt[0][1].y = rng.uniform(y_1, y_2);
			pt[0][2].x = rng.uniform(x_1, x_2);
			pt[0][2].y = rng.uniform(y_1, y_2);
			pt[1][0].x = rng.uniform(x_1, x_2);
			pt[1][0].y = rng.uniform(y_1, y_2);
			pt[1][1].x = rng.uniform(x_1, x_2);
			pt[1][1].y = rng.uniform(y_1, y_2);
			pt[1][2].x = rng.uniform(x_1, x_2);
			pt[1][2].y = rng.uniform(y_1, y_2);

			const Point* ppt[2] = {pt[0], pt[1]};
			int npt[] = {3, 3};

			polylines(image, ppt, npt, 2, true, randomColor(rng), rng.uniform(1,10), lineType);

			imshow( window_name, image );
			if( waitKey(DELAY) >= 0 )
			{ 
				return -1; 
			}
		}
		return 0;
	}

	/**
	 * @function Drawing_Random_Filled_Polygons
	 */
	int Drawing_Random_Filled_Polygons( Mat image, char* window_name, RNG rng )
	{
		int lineType = 8;

		for ( int i = 0; i < NUMBER; i++ )
		{
			Point pt[2][3];
			pt[0][0].x = rng.uniform(x_1, x_2);
			pt[0][0].y = rng.uniform(y_1, y_2);
			pt[0][1].x = rng.uniform(x_1, x_2);
			pt[0][1].y = rng.uniform(y_1, y_2);
			pt[0][2].x = rng.uniform(x_1, x_2);
			pt[0][2].y = rng.uniform(y_1, y_2);
			pt[1][0].x = rng.uniform(x_1, x_2);
			pt[1][0].y = rng.uniform(y_1, y_2);
			pt[1][1].x = rng.uniform(x_1, x_2);
			pt[1][1].y = rng.uniform(y_1, y_2);
			pt[1][2].x = rng.uniform(x_1, x_2);
			pt[1][2].y = rng.uniform(y_1, y_2);

			const Point* ppt[2] = {pt[0], pt[1]};
			int npt[] = {3, 3};

			fillPoly( image, ppt, npt, 2, randomColor(rng), lineType );

			imshow( window_name, image );
			if( waitKey(DELAY) >= 0 )
			{
				return -1; 
			}
		}
		return 0;
	}

	/**
	 * @function Drawing_Random_Circles
	 */
	int Drawing_Random_Circles( Mat image, char* window_name, RNG rng )
	{
		int lineType = 8;

		for (int i = 0; i < NUMBER; i++)
		{
			Point center;
			center.x = rng.uniform(x_1, x_2);
			center.y = rng.uniform(y_1, y_2);

			circle( image, center, rng.uniform(0, 300), randomColor(rng),
					rng.uniform(-1, 9), lineType );

			imshow( window_name, image );
			if( waitKey(DELAY) >= 0 )
			{ 
				return -1; 
			}
		}

	  return 0;
	}

	/**
	 * @function Displaying_Random_Text
	 */
	int Displaying_Random_Text( Mat image, char* window_name, RNG rng )
	{
		int lineType = 8;

		for ( int i = 1; i < NUMBER; i++ )
		{
			Point org;
			org.x = rng.uniform(x_1, x_2);
			org.y = rng.uniform(y_1, y_2);

			putText( image, "Testing text rendering", org, rng.uniform(0,8),
						rng.uniform(0,100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);

			imshow( window_name, image );
			if( waitKey(DELAY) >= 0 )
			{ 
				return -1; 
			}
		}

		return 0;
	}

	/**
	 * @function Displaying_Big_End
	 */
	int Displaying_Big_End( Mat image, char* window_name, RNG )
	{
		const char* str = "X-Lab forever!";
		Size textsize = getTextSize(str, FONT_HERSHEY_COMPLEX, 3, 5, 0);
		Point org((window_width - textsize.width)/2, (window_height - textsize.height)/2);
		int lineType = 8;

		Mat image2;

		for( int i = 0; i < 255; i += 2 )
		{
			image2 = image - Scalar::all(i);
			putText( image2, str, org, FONT_HERSHEY_COMPLEX, 3,
						Scalar(i, i, 255), 5, lineType );

			imshow( window_name, image2 );
			if( waitKey(DELAY) >= 0 )
			{ 
				return -1; 
			}
		}

		return 0;
	}

	int test2_main()
	{
		int c;

		/// Start creating a window
		char window_name[] = "Drawing_2 Tutorial";

		/// Also create a random object (RNG)
		RNG rng( 0xFFFFFFFF );

		/// Initialize a matrix filled with zeros
		Mat image = Mat::zeros( window_height, window_width, CV_8UC3 );
		/// Show it in a window during DELAY ms
		imshow( window_name, image );
		waitKey( DELAY );

		/// Now, let's draw some lines
		c = Drawing_Random_Lines(image, window_name, rng);
		if( c != 0 ) return 0;

		/// Go on drawing, this time nice rectangles
		c = Drawing_Random_Rectangles(image, window_name, rng);
		if( c != 0 ) return 0;

		/// Draw some ellipses
		c = Drawing_Random_Ellipses( image, window_name, rng );
		if( c != 0 ) return 0;

		/// Now some polylines
		c = Drawing_Random_Polylines( image, window_name, rng );
		if( c != 0 ) return 0;

		/// Draw filled polygons
		c = Drawing_Random_Filled_Polygons( image, window_name, rng );
		if( c != 0 ) return 0;

		/// Draw circles
		c = Drawing_Random_Circles( image, window_name, rng );
		if( c != 0 ) return 0;

		/// Display text in random positions
		c = Displaying_Random_Text( image, window_name, rng );
		if( c != 0 ) return 0;

		/// Displaying the big end!
		c = Displaying_Big_End( image, window_name, rng );
		if( c != 0 ) return 0;

		return 0;
	}

	void test2()
	{
		while(true)
		{
			test2_main();			
		}

		waitKey(0);
	}

}

void test_cv()
{
	space_test_cv::test1();
	//space_test_cv::test2();

	getchar();
}