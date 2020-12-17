// NOTE(Abi) Zen2d loads these already
#if defined(BUILD_LINUX) && !defined(ZEN2D)
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#define OPENGLPROC(function, type) global PFNGL##type##PROC gl##function;
#include "zen3d_opengl_proc_list.inc"

internal void Zen3DOpenGLLoadAllFunctions(void);
#endif

// TODO(Abi):
// Zen3DPushLine() Can also then be wrapped
// Zen3DPushShape() Quads, Cube maybe idk
// Zen3DPushMesh() mesh can use a custom shader
// Zen3DPushStaticMesh() //only needs their VAOs

// Zen3DPushMode() wireframe and things
// Ability to enable and disable depth etc

// use a Uniform Buffer Object for things like perspective/view.
// model matrices should be optional for some shaders i guess

typedef enum zen3d_request_type zen3d_request_type;
enum zen3d_request_type {
    ZEN3D_REQUEST_STANDARD,
    
    ZEN3D_REQUEST_COUNT
};

typedef struct zen3d_request zen3d_request;
struct zen3d_request {
    zen3d_request_type Type;
    
    void * Data;
    u32 DataLength;
};

struct zen3d {
    ZEN3D_COMMON;
    
    GLuint Shaders[ZEN3D_REQUEST_COUNT];
    GLuint GeneralVAO;
    
    struct { \
        GLuint VAO, VBO; \
        u32 Stride; \
        u32 Size; \
        u32 Max; \
        unsigned char * Memory; \
        u32 AllocPos; \
    } Shapes;
    
#define ZEN3D_MAX_REQUESTS 2048
    zen3d_request * ActiveRequest;
    zen3d_request   Requests[ZEN3D_MAX_REQUESTS];
    u32 RequestCount;
};
/*
typedef struct mesh mesh;
struct mesh {
    GLuint Shader;
    
    v3 * Vertices;
    v4 * Colours;
};
*/
//
// Helper structs
//

typedef struct _7f32 _7f32;
struct _7f32 {
    v3 Pos;
    v4 Col;
};