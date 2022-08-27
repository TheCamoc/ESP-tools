#ifndef __ESPTools__
#define __ESPTools__

#include <ArduinoJSON.h>
#include <LittleFS.h>
#include <string>
#include <map>

#ifdef ESP8266
    #include <ESP8266WebServer.h>
#elif ESP32
    #include <WebServer.h>
#endif

class ESPToolsClass
{
public:
    #ifdef ESP8266
    void begin(ESP8266WebServer *server);
    #elif ESP32
    void begin(WebServer *server);
    #endif
    
    int loadConfig();
    int saveConfig();
    void deleteConfig();
    void addConfigString(std::string name);
    
    std::map<std::string, std::string> config;
private:
    #ifdef ESP8266
    ESP8266WebServer *server;
    fs::FS fs = LittleFS;
    #elif ESP32
    WebServer *server;
    fs::LittleFSFS fs = LittleFS;
    #endif

    void handleConfigGET();
    void handleConfigPOST();
    void log(std::string message);
    void setupFS();

   
};

extern ESPToolsClass ESPTools;
#endif