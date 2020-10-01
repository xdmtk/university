> Nicholas Martinez

> COMP 465/L - Section 16513/16526

> Instructor: Karamian

> Date: 8/27/2020


# WRITE-UP:
---



### Problem/Objective

In this homework, we are given the setup code that constructs 
a colored triangle, with each vertex position being mapped to a value on the RGB 
spectrum. The goal was to pulse, or interpolate the RGB values, from 0 to 1 (completely
black to full value). 



### OpenGL Graphics Pipeline 

Throughout the reading it describe the OpenGL graphics pipeline,
which gave a lot of insight and context into the role of the vertex and fragment shaders
supplied by programmer to the OpenGL code. Essentially the graphics pipeline starts with the vertex
input data and is given to the vertex shader. Those vertices are connected via the next stage of the 
pipeline, the shape assembly stage. The output of this stage is then passed to the geometry shader, which
splits the given shapes into more shapes for the rasterizer to more easily turn them into pixel locations.

After the rasterizer, the pixel locations then go to arguably the most important part of the graphics
pipeline, the fragment shader. The fragment shader is ran indivudally on each pixel identified by 
the rasterizer, (although this is all done in parallel on the GPU for performance reasons), and 
ultimately decides the RGBA value of each pixel based on the logic of the supplied shader program.

Lastly, the output of the fragment shader is sent to the blending stage, in which further calculations 
are made based on other rendered objects in the scene, which determines if certain pixels will either be 
replaced, their alpha values reduced or increased, or if they will be blended with other pixel colors
that overlay it to generate a new RGBA value for that pixel.



### Vertex Inputs

In this particular program, the vertex inputs given to the vertex shader were as follows:

```
float vertices[] = {
        // positions             // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
};
```

Basically here the triangle vertices are defined in a normalized field, meaning that OpenGL will do the 
necessary calculations to map the 0-1 values to pixel coordinates on the screen. Also To be quite honest, 
I am still a bit confused on why the RGB values can be specified in the vertices array, but I imagine it 
has to do something with

```
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
```

where even though the color attributes are interleaved with the vertex points, the offset from positions to 
colors is constant throughout the array (only 3 positions, only 3 colors, space between them is the length of 3 
floats in bytes)



### Shader Program/Fragment Shader

The fragment shader program is of particular interest to me, and mainly because I have (very little) hobbyist experience writing 
shaders in my free time (usually on glslsandbox.com). The fragment shader makes the most sense to me because I've 
always understood it to operate indivudally on each pixel, all at the same time (in parallel, rather than sequentially 
across pixels like programming graphics in X11), so it makes for a very challenging mindset to accomplish interesting
things in GLSL. But basically to complete the objective, all I had to do was modulate the RGB values with a smoothly
transitioning normalized value like the sin() value of the ever changing time the shader has been active, passed in
via a uniform. 



### Challenges / What did I learn?

Really the most challenging and interesting part of this assignment was actually understanding a vertex shader
and all of the under the hood mechanisms that take place in setting up OpenGL on a machine and compiling it into
a standalone binary. When programming shaders on glslsandbox.com or shadertoy.com, a convenient set of uniforms
are already provided for you, you do not have to provide any vertex shader, and it is obviously compiled for you
instantly taking all of the complexities of setting up an OpenGL environment on your machine completely away from 
the programmer. I'm very glad I learned it however, and now finally understanding the actual difference between a 
fragment shader and a vertex shader, and why a vertex shader technically isn't necessary on the sites I mentioned before
because the vertices are just the dimensions of the viewport.


