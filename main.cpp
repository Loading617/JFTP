#include <CtrlLib/CtrlLib.h>
using namespace Upp;

struct JFTP : TopWindow {
    MenuBar menu;
    
    void FileMenu(Bar& bar) {
       bar.Add("Start Server", [=] { PromptOK(""); });
       bar.Add("Stop Server", [=] { PromptOK(""); });
       bar.Add("Restart Server", [=] { PromptOK(""); });
       bar.Add("Open Shared Folder", [=] { PromptOK(""); });
       bar.Add("Browse Server Files", [=] { PromptOK(""); });
       bar.Add("Exit", [=] { Exit(); });
    }
    
    void ConnectionsMenu(Bar& bar) {
       bar.Add("Active Connections", [=] { PromptOK(""); });
       bar.Add("Allow New Connections", [=] { PromptOK(""); });
       bar.Add("Disconnect Selected Device", [=] { PromptOK(""); });
       bar.Add("Reconnect Device", [=] { PromptOK(""); });
       bar.Add("Bluetooth Pairing", [=] { PromptOK(""); });
       bar.Add("Wi-Fi Network Switch", [=] { PromptOK(""); });
    }
    
    void SettingsMenu(Bar& bar) {
       bar.Add("Server Port Settings", [=] { PromptOK(""); });
       bar.Add("Authenication", [=] { PromptOK(""); });
       bar.Add("Encryption Options", [=] { PromptOK(""); });
       bar.Add("Allowed Devices List", [=] { PromptOK(""); });
       bar.Add("Max Connections List", [=] { PromptOK(""); });
       bar.Add("Idle Timeout", [=] { PromptOK(""); });
       bar.Add("Auto-Start on Launch", [=] { PromptOK(""); });
       bar.Add("Transfer Speed Limits", [=] { PromptOK(""); });
    }
    
    void ViewMenu(Bar& bar) {
       bar.Add("Connection Log", [=] { PromptOK(""); });
       bar.Add("Transfer History", [=] { PromptOK(""); });
       bar.Add("Bandwidth Usage", [=] { PromptOK(""); });
       bar.Add("Device Info", [=] { PromptOK(""); });
       bar.Add("Server QR Code", [=] { PromptOK(""); });
       bar.Add("Dark/Light Theme", [=] { PromptOK(""); });
    }
    
    void ToolsMenu(Bar& bar) {
       bar.Add("Test Connection", [=] { PromptOK(""); });
       bar.Add("Generate FTP URL", [=] { PromptOK(""); });
       bar.Add("Backup & Restore Settings", [=] { PromptOK(""); });
       bar.Add("Clear Transfer History", [=] { PromptOK(""); });
       bar.Add("Import/Export Shared Folders List", [=] { PromptOK(""); });
    }
    
    void HelpMenu(Bar& bar) {
       bar.Add("User Guide", [=] { PromptOK(""); });
       bar.Add("Quick Start", [=] { PromptOK(""); });
       bar.Add("Keyboard Shortcuts", [=] { PromptOK(""); });
       bar.Separator();
       bar.Add("About", [=] { PromptOK(""); });
       bar.Separator();
       bar.Add("Check for Updates", [=] { PromptOK(""); });
    }
    
    void MainMenu(Bar& bar) {
        bar.Sub("File", [=](Bar& bar) { FileMenu(bar); });
        bar.Sub("Connections", [=](Bar& bar) { ConnectionsMenu(bar); });
        bar.Sub("Settings", [=](Bar& bar) { SettingsMenu(bar); });
        bar.Sub("View", [=](Bar& bar){ ViewMenu(bar); });
        bar.Sub("Tools", [=](Bar& bar){ ToolsMenu(bar); });
        bar.Sub("Help", [=](Bar& bar){ HelpMenu(bar); });
    }

    JFTP() {
       Title("JFTP").Sizeable().MinimizeBox().MaximizeBox();
       AddFrame(menu);
       menu.Set([=](Bar& bar) { MainMenu(bar); });
    }
};

    GUI_APP_MAIN
    {
           JFTP app;
           app.Run();
    }
