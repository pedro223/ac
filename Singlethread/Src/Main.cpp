/*
 * Main.cpp
 *
 *  Created on: 13 sept. 2018
 *      Author: arias
 */

#include <CImg.h>
#include <math.h>
#include <stdio.h>
using namespace cimg_library;

/**********************************
 * TODO
 * 	- Change the data type returned by CImg.srcImage to adjust the
 * 	requirements of your workgroup
 * 	- Change the data type of the components pointers to adjust the
 * 	requirements of your workgroup
 */

int main() {
	CImg<double> srcImage1("bailarina.bmp"); // Open file and object initialization
	CImg<double> srcImage2("background_V.bmp"); // Open file and object initialization

	double *pRcomp1, *pGcomp1, *pBcomp1; // Pointers to the R, G and B components of image 1
	double *pRcomp2, *pGcomp2, *pBcomp2; // Pointers to the R, G and B components of image 2

	double *pRnew, *pGnew, *pBnew;
	double *pdstImage; // Pointer to the new image pixels
	int width, height; // Width and height of the image
	int nComp; // Number of image components


	/***************************************************
	 *
	 * Variables initialization.
	 * Preparation of the necessary elements for the algorithm
	 * Out of the benchmark time
	 *
	 */

	srcImage2.display(); // If needed, show the source image

	width = srcImage1.width(); // Getting information from the source image
	height  = srcImage1.height();
	nComp = srcImage1.spectrum(); // source image number of components
				// Common values for spectrum (number of image components):
				//  B&W images = 1
				//	Normal color images = 3 (RGB)
				//  Special color images = 4 (RGB and alpha/transparency channel)


	// Allocate memory space for the pixels of the destination (processed) image 
	pdstImage = (double *) malloc (width * height * nComp * sizeof(double));
	if (pdstImage == NULL) {
		printf("\nMemory allocating error\n");
		exit(-2);
	}

	// Pointers to the RGB arrays of the source image 1
	pRcomp1 = srcImage1.data(); // pRcomp points to the R component
	pGcomp1 = pRcomp1 + height * width; // pGcomp points to the G component
	pBcomp1 = pGcomp1 + height * width; // pBcomp points to B component

	// Pointers to the RGB arrays of the source image 2
	pRcomp2 = srcImage2.data(); // pRcomp points to the R component
	pGcomp2 = pRcomp2 + height * width; // pGcomp points to the G component
	pBcomp2 = pGcomp2 + height * width; // pBcomp points to B component

	// Pointers to the RGB arrays of the destination image
	pRnew = pdstImage;
	pGnew= pRnew + height * width;
	pBnew= pGnew + height * width;

	/*********************************************
	 * Algorithm start
	 *
	 * Measure initial time
	 *
	 *	COMPLETE
	 *
	 */



	/************************************************
	 * Algorithm.
	 * In this example, the algorithm is a components exchange
	 *
	 * TO BE REPLACED BY YOUR ALGORITHM
	 */

	//Si M es la imagen superior I la inferior, y E la resultante la fórmula es:
	//E = 255 - (255-M)*(255-I)/255

	//Pantalla: Halla el valor opuesto de los píxeles de ambas capas, los multiplica entre si,
	//y vuelve a calcular el valor opuesto. Suele ofrecer resultados más claros que las capas originales.

	int npixels = height * width;
	for (int i = 0; i < npixels; i++)
	{
		*pRnew = (int)255-(255-*pRcomp1)*(255-*pRcomp2)/255;
		*pGnew = (int)255-(255-*pGcomp1)*(255-*pGcomp2)/255;
		*pBnew = (int)255-(255-*pBcomp1)*(255-*pBcomp2)/255;

	     pRnew++;  pRcomp1++;
	     pGnew++;  pGcomp1++;
	     pBnew++;  pBcomp1++;
	}

	/***********************************************
	 * End of the algorithm
	 *
	 * Measure the final time and calculate the time spent
	 *
	 * COMPLETE
	 *
	 */

		
	// Create a new image object with the calculated pixels
	// In case of normal color image use nComp=3,
	// In case of B&W image use nComp=1.
	CImg<double> dstImage(pdstImage, width, height, 1, nComp);

	// Store the destination image in disk
	dstImage.save("bailarina2.bmp");

	// Display the destination image
	dstImage.display(); // If needed, show the result image
	return(0);

}


