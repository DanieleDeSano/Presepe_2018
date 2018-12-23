// PRESEPE 2018

// PWM pins
#define G_STRIP 			3
#define B_STRIP 			5
#define R_STRIP 			6
#define SCURO 				9
#define SOLE 				10
#define ARCO_CENTRALE 		11	// ex LANT_ESTERNO  -- ex CAPANNA

// non PWM pins
#define ARCO_LATERALE 		2	// ex LANT_INTERNO - ex SPOT 

// non PWM pins - non utilizzati
#define BANC_4 				4	// ex ROSONE
#define BANC_2 				7	// ex CAMPANILE
#define CASE_A 				8	// ex CASE
#define CASE_B 				12	// ex NORCINO SUPERIORE
#define FARETTI				13	// ex CAS E_C ex NORCINO INFERIORE
 
#define STEP 10 

void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  analogWrite(G_STRIP, 0);
  analogWrite(B_STRIP, 0);
  analogWrite(R_STRIP, 0);
  analogWrite(SCURO, 0);
  analogWrite(SOLE, 0);
  analogWrite(ARCO_CENTRALE, 0);
  
  digitalWrite (ARCO_LATERALE, LOW);
  digitalWrite (BANC_4, LOW);
  digitalWrite (BANC_2, LOW);
  digitalWrite (CASE_A, LOW);
  digitalWrite (CASE_B, LOW);
  digitalWrite (FARETTI, LOW);
}

void loop() 
{
  int i ;
 
  // --------------------- BLU tenue a 15 - SCURO acceso - ARCHI acceso

  analogWrite  (B_STRIP, 15);
  digitalWrite (SCURO, HIGH);
  analogWrite  (ARCO_CENTRALE, 255);

  
  delay (10000);
  delay (2000);
  delay (1000);

  // ---------------------  diminusce scuro notte, diminuisce BLU
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    v = 255.0 * (i / 800.0);
    analogWrite(B_STRIP,  max(15,v) );
    analogWrite(SCURO,  255-v );
    delay(STEP);
  }  

  // ---------------------- ex 2017 
  
  digitalWrite (CASE_B, HIGH);
  delay(2000);
  digitalWrite (CASE_A, HIGH);
  delay(2000);
  delay(1000);
  
  // ---------------------- aumenta ROSSO da 0 a 255
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    v = 255.0 * (i / 800.0);
    analogWrite(R_STRIP,  v );
    delay(STEP);
  }  

  // ---------------------- ex 2017 

  digitalWrite (CASE_B, LOW);
  delay (2000);
  digitalWrite (BANC_2, HIGH);
  delay (2000);
  digitalWrite (BANC_4, HIGH);
  
  // ---------------------- aumenta VERDE da 0 a 255 e spegne ARCO
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    v = 255.0 * (i / 800.0);
    analogWrite(G_STRIP,  v );
	analogWrite(ARCO_CENTRALE, 255 - v );
    delay(STEP);

    if (i == 600)
    {
      digitalWrite (FARETTI, HIGH);
    }


  }  
  analogWrite(ARCO_CENTRALE, 0);
  
  
  // ---------------------- ex 2017 
  
  digitalWrite (CASE_A, LOW);
  delay(1000);
  delay(3000);
  
  // ---------------------- sorge SOLE - parte prima - da 0 a 80


   for (int i = 0 ; i < 600 ; i++)
  {
    float v ;
    v = 80.0 * (i / 600.0);
    analogWrite(SOLE,  v );
    delay(STEP);


  }  
  

  // ---------------------- ex 2017 

  delay(1000);
  digitalWrite (BANC_2, LOW);
  delay(1000);
  digitalWrite (BANC_4, LOW);

  // ---------------------- sorge SOLE - parte seconda - da 80 a 255

   for (int i = 0 ; i < 300 ; i++)
  {
    float v ;
    v = 80 + 175.0 * (i / 300.0);
    analogWrite(SOLE,  v );
    delay(STEP);
  }  
  
  // ---------------------- SOLE stabile al culmine

  delay(10000);

  // ---------------------- riduce SOLE - da 255 a 80
  
   for (int i = 0 ; i < 400 ; i++)
  {
    float v ;
    v = 175.0 * (i / 400.0);
    analogWrite(SOLE,  255-v );
    delay(STEP);
  }  
  
  digitalWrite (FARETTI, LOW);


  // ---------------------- ex 2017 
  
  digitalWrite (BANC_2, HIGH);
  delay(1000);
  digitalWrite (BANC_4, HIGH);

  // ---------------------- riduce SOLE - da 80 a 0 - diminuisce ROSSO e VERDE da 255 a 25 per imbrunire - accensione ARCO prima parte da 0 a 120
  
   for (int i = 0 ; i < 700 ; i++)
  {
    float v ;
    float z;
    float x;
    
    v = 80.0 * (i / 700.0);
    z = 230.0 * (i / 700.0);
    x = 120.0 * (i / 700.0);
    
    analogWrite(SOLE,  255-175-v );
    analogWrite(R_STRIP,  255-z );
    analogWrite(G_STRIP,  255-z );
	
	analogWrite(ARCO_CENTRALE,  x );
	
    delay(STEP);
  }  

  // ---------------------- ex 2017 
  

  // ---------------------- diminuisce ROSSO e VERDE da 25 a 0 per notte 
  
  for (int i = 0 ; i < 800 ; i++)
  {
    float v;
    float x;
    
    v = 25.0 * (i / 800.0);
    x = 135.0 * (i / 800.0);

    analogWrite(R_STRIP,  25-v );
    analogWrite(G_STRIP,  25-v );
	analogWrite(ARCO_CENTRALE,  120 + x );

	// a meta, ex 2017 
    if (i == 400)
    {
       digitalWrite (BANC_4, HIGH);
    }
    delay(STEP);
  }  

  // ---------------------- ex 2017 

  delay (2000);
  digitalWrite (CASE_A, HIGH);
  delay (2000);
  delay (3000);
  digitalWrite (BANC_4, LOW);
  delay (2000);
  digitalWrite (BANC_2, LOW);
  delay (5000);
  digitalWrite (CASE_B, HIGH);
  delay (5000);
 
  // ---------------------- attenua BLU da 255 a 15 - aumenta SCURO da 0 a 255
 
  for (int i = 0 ; i < 1800 ; i++)
  {
    float v ;
    float z;
    
    v = 240.0 * (i / 1800.0);
    analogWrite(B_STRIP,  255-v );

    z = 255.0 * (i / 1800.0);
    analogWrite(SCURO,  z );
    
	// ---------------------- ex 2017 
	
    if (i == 1000)
    {
       digitalWrite (CASE_A, LOW);
    }
    if (i == 1200)
    {
       digitalWrite (CASE_B, LOW);
    }
    
    delay(STEP);
  }  
}
