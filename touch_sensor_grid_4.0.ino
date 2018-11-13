 int rowsTotal = 5;    //need to fix this number eventually
int rows[5];// = {firstRow,1,2,3};

//set up pins for column copper strips
int colsTotal = 5;    //fix this number eventually
int cols[5] = {0,1,2,3,4};

//threshold for touch sensing
int threshold = 20;

void setup() {
  Serial.begin(9600);

  int digitalPin = 8;
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
      //this for loop sends HIGH to the row represented by rowCount
      //and sends LOW to all other rows
      for(int i = 0; i<rowsTotal; i++)
      {
        if(i==rowCount)
        {
          digitalWrite(rows[rowCount], HIGH);
        }
        else
        {
          digitalWrite(rows[i], LOW);
        }
      }
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

