/*
 
 This example prints out the IMEI number of the SIM card,
 then check to see if it's connected to a carrier. If so, 
 it prints the phone number associated with the card.
 Then it scans for nearby networks and prints out their signal strengths.
 
 Circuit:
 * GSM shield attached
 
 Created 8 Mar 2012
 by Tom Igoe, implemented by Javier Carazo
 */

// libraries
#include <GSM.h>

// PIN Number
#define PINNUMBER ""

// initialize the library instance
GSM gsmAccess;     // include a 'true' parameter for debug enabled
GSMScanner scannerNetworks;
GSMModem modemTest;
GSMBand bandManager;

// Save data variables
String IMEI = "";

// serial monitor result messages
String errortext = "ERROR";

void setup()
{
  // initialize serial communications
  Serial.begin(9600);
  Serial.println("GSM networks scanner");
  scannerNetworks.begin();
  
  // connection state
  boolean notConnected = true;
  
  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  
  // get modem parameters
  // IMEI, modem unique identifier
  Serial.print("Modem IMEI: ");
  IMEI = modemTest.getIMEI();
  IMEI.replace("\n","");
  if(IMEI != NULL)
    Serial.println(IMEI);
    
  // get current band 
  GSM3GSMBand band;
  band=bandManager.getBand();
  Serial.print("Current band: ");
  Serial.println(bandManager.getBandName(band));
  
  // currently connected carrier
  Serial.print("Current carrier: ");
  Serial.println(scannerNetworks.getCurrentCarrier());
    
  // returns strength and ber
  // signal strength in 0-31 scale. 31 means power > 51dBm
  // BER is the Bit Error Rate. 0-7 scale. 99=not detectable
  Serial.print("Signal Strength: ");
  Serial.print(scannerNetworks.getSignalStrength());
  Serial.println(" [0-31]");
}

void loop()
{
  // scan for existing networks, displays a list of networks
  Serial.println("Scanning available networks. May take some seconds.");
  
  Serial.println(scannerNetworks.readNetworks());
  
    // currently connected carrier
  Serial.print("Current carrier: ");
  Serial.println(scannerNetworks.getCurrentCarrier());
    
  // returns strength and ber
  // signal strength in 0-31 scale. 31 means power > 51dBm
  // BER is the Bit Error Rate. 0-7 scale. 99=not detectable
  Serial.print("Signal Strength: ");
  Serial.print(scannerNetworks.getSignalStrength());
  Serial.println(" [0-31]");

}
