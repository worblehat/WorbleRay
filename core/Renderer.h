#ifndef RENDERER_H
#define RENDERER_H

class Color;
class Framebuffer;
class Scene;


class Renderer
{
public:
    explicit Renderer(const Scene& scene);

    void render(Framebuffer &target);
    void abort();

private:
    void render_iterative(Framebuffer &target) const;
    void render_progressive(Framebuffer &target) const;
    void render_progressive_with_lookup(Framebuffer &target) const;
    void render_rect(short x, short y, short step, Framebuffer &target) const;
    Color calculate_pixel(int x, int y) const;

private:
    const Scene &scene;
    bool _abort;
    double inv_gamma;
};

#endif // ifndef RENDERER_H
