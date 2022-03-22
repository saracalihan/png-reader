#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "image.hpp"

using namespace std;

Image readImage(char *path)
{
    ifstream file;
    size_t size = 0;
    Image image;
    char *data = 0;
    char *header = new char[8];

    file.open(path, ios::in | ios::binary);
    image.path = path;

    file.read(header, 8);
    string imageType = "";
    imageType += header[1];
    imageType += header[2];
    imageType += header[3];
    if (imageType != "PNG")
    {
        std::cerr << "Image type must be \"PNG\"\n\a";
        throw;
    }

    image.header = header;

    file.seekg(0, ios::end);
    size = file.tellg();
    file.seekg(0, ios::beg);
    data = new char[size - 8 + 1];
    file.seekg(8); // skip the header
    file.read(data, size - 8);
    data[size] = '\0';
    image.data = data;
    image.size = size;

    file.close();
    return image;
}

bool setChunks(Image *image)
{
    /*chunk uzunlugu kullanilarak chunklar bir dizide tutulmali*/
    return 1;
}

Image start(char *path){
    Image image = readImage(path);
    setChunks(&image);
}
