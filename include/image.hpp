struct PNGChunk
{
    /* -----------------------------------------------------------------------------
    *  | length -4 bytes- | type -4 bytes- | data -[length] bytes- | CRC -4 bytes- |
    *  -----------------------------------------------------------------------------
    */
    int length;
    int type;
    long long unsigned int data;
    int crc;
};

struct Image
{
    char *path;
    unsigned short int width;
    unsigned short int lenght;
    char *data;
    char *header;
    unsigned int size;
    PNGChunk *chunks;
};
Image start(char* path);
Image readImage(char *path);
bool setChunks(Image *image);
