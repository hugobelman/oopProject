#include <iostream>
#include "image.hpp"
#include "pixel.hpp"
#include "grayScaleFilter.hpp"
#include "negativeFilter.hpp"
#include "blackAndWhiteFilter.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Image image("test.png");
    NegativeFilter f;

    image.save("1.png");

    f.applyOn(image);

    image.save("2.png");

    return 0;
}
