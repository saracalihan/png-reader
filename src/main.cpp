#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "image.hpp"

using namespace std;
int main()
{
    char *INPUT_FILENAME = "./example-image.png";
    Image image = start(INPUT_FILENAME);
    cout << endl
         << image.header[1] << image.header[2] << image.header[3];
    cout << endl
         << "length: " << (int)image.data[1] << " " << (int)image.data[2] << " " << (int)image.data[3] << " " << (int)image.data[4] << "\ntype" << image.data[5] << " " << image.data[6] << " " << image.data[7] << " " << image.data[8];

    return 0;
}
