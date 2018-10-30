//all pins defined here:
//define rows for array


//set up pins for row copper strips
int rowsTotal = 3;    //need to fix this number eventually
int rows[3];// = {firstRow,1,2,3};


//set up pins for column copper strips
int colsTotal = 3;    //fix this number eventually
int cols[3];// = {4,5,6,7};

//threshold for touch sensing
int threshold;

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i<=rowsTotal; i++){
     rows[i] = i;
     pinMode(rows[i], INPUT);
  }

  

  for(int i = rowsTotal+1; i<=colsTotal+(rowsTotal+1); i++){
    cols[i] = i;
    pinMode(cols[i], INPUT);
  }
 
  
  

}

void loop() {
  int rowActivated;
  int colActivated;
  
  
    for(int i = 0; i<=rowsTotal; i++){
      if (analogRead(rows[i]>threshold)){
        rowActivated = analogRead(rows[i]);
        for(int i = 0; i<=colsTotal; i++){
          if (analogRead(cols[i]>threshold)){
            colActivated = analogRead(cols[i]);
          }
        }
      }
      
      
    }
  

}
