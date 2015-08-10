#include <Arduino.h>
#include <SPI.h>
#include <Wifi.h>

class RestClient {

  public:
    RestClient(const char* host,const char* _ssid,const char* _pw);

    //Client Setup
    int connect();
    int begin(char*, char*);

    //Generic HTTP Request
    int request(const char* method, const char* path,
                const char* body, String* response);
    // Set a Request Header
    void setHeader(const char*);
    // Set Content-Type Header
    void setContentType(const char*);

    // GET path
    int get(const char*);
    // GET path and response
    int get(const char*, String*);

    // POST path and body
    int post(const char* path, const char* body);
    // POST path and body and response
    int post(const char* path, const char* body, String*);

    // PUT path and body
    int put(const char* path, const char* body);
    // PUT path and body and response
    int put(const char* path, const char* body, String*);

    // DELETE path
    int del(const char*);
    // DELETE path and body
    int del(const char*, const char*);
    // DELETE path and response
    int del(const char*, String*);
    // DELETE path and body and response
    int del(const char*, const char*, String*);

  private:
    WiFiClient client;
    int readResponse(String*);
    void write(const char*);
    const char* host;
    const char* ssid;
    const char* pw;
    int port;
    int num_headers;
    const char* headers[10];
    const char* contentType;
};
