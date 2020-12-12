ZENAPPFUNC ZEN_APPLICATION_STATIC_LOAD(StaticLoad) {
    Platform = Platform_;
    
#ifdef ZEN2D
    Zen2D = MemoryArenaAlloc(&Platform->PermenantArena, sizeof(*Zen2D));
    Zen2DInit(&Platform->PermenantArena);
    Platform->Zen2D = Zen2D;
#endif
    
#ifdef ZEN3D
    Zen3D = MemoryArenaAlloc(&Platform->PermenantArena, sizeof(*Zen2D));
    Zen3DInit(&Platform->PermenantArena);
    Platform->Zen3D = Zen3D;
#endif
    
    AppInit();
}

ZENAPPFUNC ZEN_APPLICATION_UPDATE(Update) {
#ifdef ZEN2D
    Zen2DBeginFrame();
#endif
    
#ifdef ZEN3D
    
#endif
    
    AppUpdate();
    
#ifdef ZEN3D
    
#endif
    
#ifdef ZEN2D
    Zen2DEndFrame();
#endif
}

// TODO(Abi): Fix hotloading seg faults
ZENAPPFUNC ZEN_APPLICATION_HOT_LOAD(HotLoad) {
    Platform = Platform_;
    
#ifdef ZEN2D
    Zen2D = Platform->Zen2D;
    Zen2DOpenGLLoadAllFunctions();
#endif
    
    AppHotLoad();
}

ZENAPPFUNC ZEN_APPLICATION_HOT_UNLOAD(HotUnload) {
    AppHotUnload();
}

#ifdef ZEN2D
#include "zen2d/zen2d.c"
#endif

#ifdef ZEN3D
#include "zen3d/zen3d.c"
#endif