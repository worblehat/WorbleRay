#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class Framebuffer
{
    public:
        Framebuffer(short width, short height);
        virtual void set_pixel(short x, short y, float r, float g, float b) = 0;
        virtual void refresh() = 0;
    public:
        short width;
        short height;
}; 

inline Framebuffer::Framebuffer(short width, short height)
{
    this->width = width;
    this->height = height;
}

#endif //ifndef FRAMEBUFFER_H
