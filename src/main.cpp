#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "microcoap/coap.h"
#include "udp_microcoap_wrapper.h"
#include "counter.h"
#include "TM1637.h"

WiFiUDP Udp;

const char* ssid     = "CASSINIguest";
const char* password = "Cassini2016!";

void setup_wifi() {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() {
    Serial.begin(9600);
    setup_wifi();
    Udp.begin(5683);
    coap_setup();
    udp_microcoap_wrapper_init(&Udp);
}

extern void app_loop();

void loop() {
    // get coap processing object
    udp_microcoap_wrapper *c = udp_microcoap_wrapper_get();

    // let it handle a message (if one is available via WifiUdp)
    c->b_debug = true;
    c->ops->handle_udp_coap_message(c);

    app_loop();
}
