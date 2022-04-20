#include "src/dwin.h"

extern unsigned char v1[8];

void setup() {
  // put your setup code here, to run once:

  uint8_t err = 0;

  dwin_setup();

  err = DWIN_SET(v1,sizeof(v1));

}

void loop() {
  // put your main code here, to run repeatedly:

}
