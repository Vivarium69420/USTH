# Labwork 2 Part 2

## Dependencies

- The package manager for C++ will be OS dependent, please check with official
`vcpkg` website

```bash
vcpkg install opengl glew glfw3 freeglut soil glsl list
```

- NOTE: If you're in Arch, there might be some packages you still have to use
`yay` to install for some reason, you will see the problem, when it arise.

## Build and Run

- Similar to Part 1, about `Makefiles`, however here we only have two situation

```Makefiles
# For diamond block
make final 

# For coal block
make coal 
```
