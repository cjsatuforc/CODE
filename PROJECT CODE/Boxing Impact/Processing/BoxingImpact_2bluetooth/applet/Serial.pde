////////////////////////////////////
////////////    SERIAL   ///////////
////////////////////////////////////
void serialEvent(Serial thisPort) {
  if (thisPort == rightPort) {
    String rightString = rightPort.readStringUntil('\n');  // get the ASCII string
    if (rightString != null) {  // if it's not empty
      rightString = trim(rightString);  // trim off any whitespace
      int rightValues[] = int(split(rightString, ","));  // convert to an array of ints
      rightPS = 1023 - rightValues[0];
      rightPSmap = map(rightValues[0], 0,1023, 0, windowHeight-textBoxHeight);
      rightX = rightValues[1];
      rightY = rightValues[2];
      rightZ = rightValues[3];
      println("RIGHT: PS: " + rightPS + " X: " + rightX + " Y: " + rightY + " Z: " + rightZ);
    }
  }
  if (thisPort == leftPort) {
    String leftString = leftPort.readStringUntil('\n');  // get the ASCII string
    if (leftString != null) {  // if it's not empty
      leftString = trim(leftString);  // trim off any whitespace
      int leftValues[] = int(split(leftString, ","));  // convert to an array of ints
      leftPS = 1023 - leftValues[0];
      leftPSmap = map(leftValues[0], 0,1023, 0, windowHeight-textBoxHeight);
      leftX = leftValues[1];
      leftY = leftValues[2];
      leftZ = leftValues[3];
      println("LEFT: PS: " + leftPS + " X: " + leftX + " Y: " + leftY + " Z: " + leftZ);
    }
  }
}
