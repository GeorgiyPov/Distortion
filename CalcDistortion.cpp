#include "CalcDistortion.h"

void CalcDistortion::ProcessImage(cv::Mat image)
{
        
    int width = image.cols;
    int height = image.rows;
    int* x = new int[width]();
    int* y = new int[height]();

    unsigned char* buffer = new unsigned char[height * width];
    buffer = image.data;

    //задаем вектора
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (buffer[i * width + j] > 200)
            {
                y[i]++;
                x[j]++;
            }
        }
    }

    //обрезаем значения векторов
    int x_value, y_value;

    x_value = 0;
    y_value = 0;

    for (int i = 0; i < height; i++)
        if (y[i] > 5)
            y_value++;

    for (int j = 0; j < width; j++)
        if (x[j] > 5)
            x_value++;


    std::cout << "y: " << y_value << " x: " << x_value << std::endl;
    double distortion = (double)y_value / x_value;

    std::cout << "distortion: " << distortion;

}