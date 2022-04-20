/*
 * dwin.cpp
 * 
 * Copyright 2022 raja <raja@raja-IdeaPad-Gaming-3-15IMH05>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include "dwin.h"

//Object instantiation should always take place in the cpp file
SoftwareSerial dwin(27,26);

unsigned char Buffer[80]; 
unsigned char Buffer_Len = 0;
unsigned char tcount = 0;


unsigned char v1[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char v2[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char v3[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char i1[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char i2[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char i3[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char e1[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char e2[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};
unsigned char e3[8] = {0X5A, 0XA5, 0X05, 0X82, 0X54, 0X20, 0X00, 0X23};

/*
* @brief: DWIN_read 
* This function is used to read from a particular location
*/
uint8_t DWIN_read()
{
if (dwin.available())
  {
    //dwin.println(F("Some buffer filled"));
    Buffer[Buffer_Len] = dwin.read();
    Buffer_Len++;
    tcount = 5;

   return DISP_DAT_AVAIL;
  }
  else
  {
    if (Buffer[0] == 0X5A)
    { 
      Buffer_Len = 0;
    }
    else
    {
    return DISP_NO_DAT;
    }
    
  }


  
return DISP_DAT_READ;
}

/*
* @brief: DWIN_SET(unsigned char *) 
* This function is used to set voltage,current and energy.
*/

uint8_t DWIN_SET(unsigned char *val,size_t len)
{
//Serial.write(val, 8);
if(dwin.write(val,len))
{
return DISP_OK;
}
else
{
	return DISP_FAIL;
}
}

/*
 * @brief: begin 
 * 
*/

void dwin_setup()
{
	dwin.begin(9600);
}
