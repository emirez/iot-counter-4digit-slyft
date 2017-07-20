#include "Arduino.h"
#include "microcoap/coap.h"
#include "coapled_app.h"
#include "TM1637.h"
#include "counter.h"
// Initiate 4DigitDisplay
#define CLK D3
#define DIO D5
TM1637 tm1637(CLK,DIO);

bool __command = false;
int counter = 5000;

void app_loop() {

    tm1637.display(0,(counter/1000)%10);
    tm1637.display(1,(counter/100)%10);
    tm1637.display(2,(counter/10)%10);
    tm1637.display(3,counter%10);
      if(__command){
        counter++;
        delay(250);
    } else {counter--;delay(250);}
      delay(250);
}
// -- Application level handler for GET to /digit
bool TUTCI__coapled__get___digit(
    struct TUTCI__coapled__get___digit_req *req,
    struct TUTCI__coapled__get___digit_resp *resp) {

      Serial.println("TUTCI__coapled__get___digit");
      
      resp->data.counter_205.command = __command;
      resp->response_code = COAP_RSPCODE_CONTENT;

//    resp->response_code = (coap_responsecode_t)MAKE_RSPCODE(5,1);

    return true;
}


// -- Application level handler for POST to /digit
bool TUTCI__coapled__post___digit(
    struct TUTCI__coapled__post___digit_req *req,
    struct TUTCI__coapled__post___digit_resp *resp) {

      Serial.println("TUTCI__coapled__post___digit");

      __command = req->data.counter.command;
      resp->response_code = COAP_RSPCODE_CHANGED;

      Serial.print( "Changed counter"); Serial.println( __command);

//    resp->response_code = (coap_responsecode_t)MAKE_RSPCODE(5,1);

    return true;
}
