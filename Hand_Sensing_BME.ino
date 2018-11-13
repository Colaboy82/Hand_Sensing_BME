//set up pins for row copper strips
int rowsTotal = 5;    //need to fix this number eventually
int rows[5];// = {firstRow,1,2,3};

//set up pins for column copper strips
int colsTotal = 5;    //fix this number eventually
int cols[5] = {0,1,2,3,4};

//threshold for touch sensing
int threshold = 0;

void setup() {
  Serial.begin(9600);

  int digitalPin = 2;
  for (int i = 0; i < rowsTotal; i++){
     rows[i] = digitalPin;
     pinMode(rows[i], OUTPUT);
     digitalPin++;
  }
}

void loop() {
  int rowActivated;
  int colActivated;
  int rowCount;
  int colCount;
  int value;
    for(rowCount = 0; rowCount<rowsTotal; rowCount++)
    {
      digitalWrite(rows[rowCount], HIGH);
      delay(500);
      for (colCount = 0; colCount<colsTotal; colCount++)
      {
        value = analogRead(cols[colCount]);
        if(value>threshold)
        {
          colActivated = colCount;
          rowActivated = rowCount;
          Serial.println("Row: " + String(rowActivated) + ", Column: " + String(colActivated));  
          Serial.println("Value: " + String(value));
        }
      } 
              
    }
}
