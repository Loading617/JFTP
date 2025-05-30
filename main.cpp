#include <CtrlLib/CtrlLib.h>
#include "JFTP.h"

using namespace Upp;

GUI_APP_MAIN
{
    FtpServer server;
    server.Start(21);
    PromptOK("FTP server started on port 21");
    Run();
}
