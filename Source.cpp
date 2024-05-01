/*
 @file    imgGen.cpp
 @author  kaevin barta


 
   working with 2D array that deals with initializing and outputing numbers in the array that creates shapes by
   writing to a file then using irfanveiw or other software to veiw it as a .pgm
 */

#include <iostream>
#include <fstream> 

const int WIDTH = 300;
const int HEIGHT = 200;

void createImage(unsigned char img[][WIDTH]);
bool writeImage(unsigned char img[][WIDTH]);
void drawRect(unsigned char image[][WIDTH], int imgHeight, int rectTop, int rectLeft, int rectHeight, int rectWidth);//draw rectagle shape with numbers
void drawCircle(unsigned char image[][WIDTH], int height, int centerX, int centerY, int radius, int rectTop, int rectLeft, int rectHeight, int rectWidth);
//No more capital letters as the start of function names.
 int main(){

    static unsigned char img[HEIGHT][WIDTH];

    createImage(img); //initalization, rectangle drawing and circle drawing, math
    writeImage(img);  //file output, close/open file, greyscale and size scale
    
    return 1;
}


void createImage(unsigned char img[][WIDTH]) {
    const int imgHeight = 200;
    const int rectTop = 50;
    const int rectLeft = 100;
    const int rectHeight = 175;
    const int rectWidth = 150;
    const int greyscale = 255;
    const int cirectTop = 100;
    const int cirectLeft = 150;
    const int cirectHeight = 150;
    const int cirectWidth = 200;
    const int circleHeight = 150;

    const int centerX = (cirectLeft + cirectWidth)/2;
    const int centerY = (cirectTop + cirectHeight)/2;

    const int radius = 25;//dont make this any bigger than HALF of the legth of the rectangle the circle is mapped in

    for (int row = 0; row < HEIGHT; row++) //initializes given 2D array with 255s.
        for (int col = 0; col < WIDTH; col++) // draws a small rectangle in upper left corner of given array.
            img[row][col] = 255;

    drawRect(img, imgHeight, rectTop, rectLeft, rectHeight, rectWidth);
    drawCircle(img, circleHeight, centerX, centerY, radius, cirectTop, cirectLeft, cirectHeight, cirectWidth);
}


void drawRect(unsigned char image[][WIDTH], int imgHeight, int rectTop, int rectLeft, int rectHeight, int rectWidth) {
    //creating a little rectagle or square, you can set it as you like.
    for (int y = rectTop; y < rectHeight; y++)//it starts at rectTop and ends at rectHeight filling the collums with the loop below.
        for (int x = rectLeft; x < rectWidth; x++)
            image[y][x] = 90;//changing the grey scale to 90.

}


void drawCircle(unsigned char image[][WIDTH], int height, int centerX, int centerY, int radius, int rectTop, int rectLeft, int rectHeight, int rectWidth) {

    /*
    -this uses a basic eqaution for a circle(x-a)^2+(y-b)^2=r^2 and so i minus r^2 because it should be the same number as the eqation. making anything but 0 not a point
    -i didnt want to over complicate so i just did x(times)x instead of x^2
    -bassicly the rectagle but it doesnt include the equation that makes some of the points false.
    */

    for (int y = rectTop; y < rectHeight; y++)
        for (int x = rectLeft; x < rectWidth; x++) {
            if (((x-centerX)* (x - centerX)) +((y-centerY)* (y - centerY))-(radius*radius) <= 0)//this is circle equation from math, if the numbers dont equal 0 then it does not belong.
                    image[y][x] = 10;//changing the grey scale to 10.
                
        }
    
}

bool writeImage(unsigned char img[][WIDTH]){
    std::ofstream imgFile; //like cout but into a file.

    imgFile.open("imgGenn.pgm"); //open file.

    imgFile << "P2" << '\n' << "300 200" << '\n' << "255" << '\n'; // change this numbers(200 300) if you are gonna change thier constant width and height, the rest stays.

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++)
            imgFile << static_cast<int>(img[row][col]) << ' '; //write the given array to the file.
        imgFile << '\n';//creates a new line.
    }

    imgFile.close(); //close it up for good measure.

    return true; //its a boolen function.
}





