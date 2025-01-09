#include "Praise0_Algorithm.h"
#include <cstddef>

namespace Server_Library
{
    Praise0_Algorithm::Praise0_Algorithm()
    {
    }

    Praise0_Algorithm::~Praise0_Algorithm()
    {
    }

    void Praise0_Algorithm::Do_Praise(
        class Server_Library::Praise0_Input* ptr_In_SubSet,
        class Server_Library::Praise0_Output* ptr_Out_SubSet
    )
    {
        __int16 mouse_X, mouse_Y, new_mouse_X, new_mouse_Y;
        /*
        // Get the mouse state
        var mouse = MouseState;

        if (_firstMove) // This bool variable is initially set to true.
        {
            _lastPos = new Vector2(mouse.X, mouse.Y);
            _firstMove = false;
        }
        else
        {
            // Calculate the offset of the mouse position
            var deltaX = mouse.X - _lastPos.X;
            var deltaY = mouse.Y - _lastPos.Y;
            _lastPos = new Vector2(mouse.X, mouse.Y);

            // Apply the camera pitch and yaw (we clamp the pitch in the camera class)
            camera.Yaw += deltaX * sensitivity;
            camera.Pitch -= deltaY * sensitivity; // Reversed since y-coordinates range from bottom to top

    */}
}