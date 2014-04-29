glfw-cxx
========

glfw-cxx is a C++, Object Oriented wrapper for GLFW3.
I wanted an up-to-date, OOP version of GLFW, but couldn't find one. Here's my attempt at making one.



Installation
----

glfw-cxx requires a C++11-compatible compiler.
To install glfw-cxx, just run the following:
```bash
$ git clone http://github.com/Mischa-Alff/glfw-cxx.git glfw-cxx
$ cd glfw-cxx
$ mkdir build && cmake ..
$ make -j4
$ sudo make install
```


Why should I use __glfw-cxx__?
----

__glfw-cxx__ is simply a C++ OOP wrapper over plain, C, GLFW, along with a few extra features, such as:
- Event Queues (Don't worry, your precious callbacks still work)
- Classes!
- Lambda support for callbacks.
- No more need to call glfwInit()!
- And probably a few more things I can't remember at this very moment!

Documentation
----

You can view the documentation at http://glfw-cxx.destrock.com/docs/

Note
----

I try to keep this wrapper up-to-date with the current git version of GLFW.
