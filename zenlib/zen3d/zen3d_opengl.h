// TODO(Abi):
// Zen3DPushLine() Can also then be wrapped
// Zen3DPushShape() Quads, Cube maybe idk
// Zen3DPushMesh() mesh can use a custom shader
// Zen3DPushStaticMesh() //only needs their VAOs

// Zen3DPushMode() wireframe and things
// Ability to enable and disable depth etc

// use a Uniform Buffer Object for things like perspective/view.
// model matrices should be optional for some shaders i guess

// Zen3DPushShader(shader s) { Zen3D->ActiveCustomShader = s };
// is a type of request so change in end frame too
// when pushing meshes then use glUseProgram(Zen3D->ActiveCustomShader)
// use a similar push camera
typedef struct zen3d_shader_info zen3d_shader_info;
struct zen3d_shader_info {
    char * Name;
    char * VertexSource;
    char * FragmentSource;
};

typedef enum zen3d_shader_type zen3d_shader_type;
enum zen3d_shader_type {
    ZEN3D_SHADER_RGBA,
    ZEN3D_SHADER_LIGHTING,
    
    ZEN3D_SHADER_COUNT,
};

typedef enum zen3d_request_type zen3d_request_type;
enum zen3d_request_type {
    ZEN3D_REQUEST_RGBA,
    ZEN3D_REQUEST_LINE,
    ZEN3D_REQUEST_STATIC_MESH,
    ZEN3D_REQUEST_SET_CAMERA,
    ZEN3D_REQUEST_POLYMODE,
    ZEN3D_REQUEST_ENABLE,
    ZEN3D_REQUEST_DISABLE,
    // TODO(Abi): think this through re more lights
    ZEN3D_REQUEST_SET_SUN, 
    
    ZEN3D_REQUEST_COUNT
};

typedef struct zen3d_request zen3d_request;
struct zen3d_request {
    zen3d_request_type Type;
    
    void * Data;
    u32 DataLength;
};

typedef enum zen3d_poly_mode zen3d_poly_mode;
enum zen3d_poly_mode {
    ZEN3D_POINTS,
    ZEN3D_WIREFRAME,
    ZEN3D_FILLED,
};

typedef enum zen3d_capability zen3d_capability;
enum zen3d_capability {
    ZEN3D_DEPTH,
    // TODO(Abi): fill this out
};

typedef enum zen3d_uniform_binding zen3d_uniform_binding;
enum zen3d_uniform_binding {
    ZEN3D_UNIFORM_MATRICES,
    ZEN3D_UNIFORM_LIGHTS,
    
    ZEN3D_UNIFORM_COUNT
};

struct zen3d {
    ZEN3D_COMMON;
    
    GLuint Uniformbuffers[ZEN3D_UNIFORM_COUNT];
    GLuint Shaders[ZEN3D_SHADER_COUNT];
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
    
    framebuffer Framebuffer;
    texture White;
};

struct static_mesh {
    GLuint VAO, VBO;
    u32 VerticesCount;
    texture * Texture;
};

typedef enum camera_mode camera_mode;
enum camera_mode {
    CAMERA_MODE_LOOK_AT,
    CAMERA_MODE_COUNT
};

struct camera {
    camera_mode Mode;
    v3 Position;
    v3 Target;
    f32 fov;
};

typedef struct sun sun;
struct sun {
    // NOTE(Abi): Padding since OpenGL uniform buffers align to 4 floats;
    v3 Direction; f32 _pad;
    v4 Colour;
};