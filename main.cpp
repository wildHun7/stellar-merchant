#include "core/GameApp.h"
#include "io/TerminalRenderer.h"
#include "io/TerminalInput.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8); // set UTF-8 in windows terminal
    SetConsoleCP(CP_UTF8);
    sm::GameApp app(
        std::make_unique<sm::TerminalRenderer>(),
        std::make_unique<sm::TerminalInput>()
        );
    app.run();
    return 0;
}
    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


