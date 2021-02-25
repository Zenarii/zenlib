@echo off
IF NOT EXIST build mkdir build
set error_flags = "/W3 /WX /wd4018 /wd4267"
set modules = "/DUSE_OPENGL /DZEN3D /DZEN2D"
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
echo [ZenBuild] Building platform layer
pushd build
cl -Zi %error_flags% /DINTERNAL_BUILD /DUSE_OPENGL /DZEN3D /DZEN2D ../zenlib/zencore/zencore_win32.c /link user32.lib gdi32.lib opengl32.lib winmm.lib 
popd
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
echo [ZenBuild] Building game layer
pushd build
cl -Zi %error_flags% /DINTERNAL_BUILD /DUSE_OPENGL /DZEN3D /DZEN2D ../sandbox.c /LD /link user32.lib gdi32.lib opengl32.lib winmm.lib 

popd
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~