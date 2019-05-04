#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include<OneWire.h>               
#include<DallasTemperature.h>     
//#include <Wire.h>
#include <String.h> 
#include <LiquidCrystal_I2C.h>

#include <dht11.h> 
#include "Sodaq_DS3231.h"
dht11 DHT11;                         
#define DHT11PIN 43 

File root;
 File myFilepopo;
File myFile4;
File myFileza;
File myFilecola;
File myFilejk;
File myFilec;
File myFilexc;
File myFilert;
File myFilegf;
File myFile5;
File myFilell;
File myFile7;
File myFilefy;
File myFile6;
File myFileqw;
File myFileb;
File myFilees;
File myFilet;
 File myFilenm;
File myFileqqq;
File myFiledd;
File myFile2;
File myFile3;
File myFile8;

LiquidCrystal_I2C lcd(0x27,16,2);
char DiaSemana[][4] = {"Lun","Mar","Mie","Jue","Vie","Sab","Dom"};
//DateTime dt(2019,4,6,20,40,0,5);

char StrContains(char *str, char *sfind);
void StrClear(char *str, char length);
void XML_response(EthernetClient cl);
void XML_responsedos(EthernetClient cl);
void analizarCadena(char * str);
void informeDeVarCalen();
void analizarEntrada(char * str);
void actualizarSDpuno();
void XML_responsenumone(EthernetClient cl);
void analizarEntradatres(char * str);
void pasajelunes();
void actualizarSensores();
void directorios();
void compruebaExistencia();
void actualizarBomba();
void limpiarBUBU();
void cargaForce();
void infiniti();
void pregunta();
boolean hayLimite();
void ejecucionClase();
int diaActivo();
boolean diaBonito();



OneWire ourWire(3);                //Se establece el pin 2  como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

DeviceAddress address1 = {0x28 ,0x31 ,0xDD, 0x45, 0x92, 0x11, 0x2, 0xE4};//dirección del sensor 1
DeviceAddress address2 = {0x28 ,0xF9, 0x6C ,0x45, 0x92, 0x18, 0x2, 0xEA};//dirección del sensor 2
DeviceAddress address3 = {0x28 ,0xB7 ,0xC9, 0x45, 0x92, 0x11, 0x2 ,0xDF};//dirección del sensor 3



// size of buffer used to capture HTTP requests
#define REQ_BUF_SZ   50

// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress dnsserver (192, 168, 1, 1);
IPAddress gateway (192, 168, 1, 1);
IPAddress subnet (255, 255, 255, 177);
//IPAddress ip(192, 168, 1, 177); // IP address, may need to change depending on network
//IPAddress ip(169, 254, 165, 158);//169.254.165.158
IPAddress ip(192, 168, 1, 150);//ip gabriel
EthernetServer server(70);
File webFile;               // the web page file on the SD card
char HTTP_req[REQ_BUF_SZ]; // buffered HTTP request stored as null terminated string
char req_index = 0;              // index into HTTP_req buffer

int obtencionSD = 1;
int trenNumerico[20];
int pinesVeinte[20]= {22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,47,49,51,37};
int bomba = 0;
int automatico = 0;
int bombAndAuto[2];
char cadelunes[50];
char cademartes[50];
char cademiercoles[50];
char cadejueves[50];
char cadeviernes[50];
char cadesabado[50];
char cadedomingo[50];
char cadettt[50];
char cadeccc[50];
char cadeestadocalen[50];
char cadetemperatura[50];
char cadetempec[50];

int tempoBomba = 0;

int sensor1 = 2;
int sensordos = 2;
int sensor3 = 2;

boolean otrosDiez = false;
int contador = 0;

//variables de calendario
char hora1a[6]= {'0','0',':','0','0','\0'};
char hora1b[6]= {'0','0',':','0','0','\0'};
char hora1c[6]= {'0','0',':','0','0','\0'};
char hora1d[6]= {'0','0',':','0','0','\0'};

char hora2a[6]= {'0','0',':','0','0','\0'};
char hora2b[6]= {'0','0',':','0','0','\0'};
char hora2c[6]= {'0','0',':','0','0','\0'};
char hora2d[6]= {'0','0',':','0','0','\0'};

char hora3a[6]= {'0','0',':','0','0','\0'};
char hora3b[6]= {'0','0',':','0','0','\0'};
char hora3c[6]= {'0','0',':','0','0','\0'};
char hora3d[6]= {'0','0',':','0','0','\0'};

char hora4a[6]= {'0','0',':','0','0','\0'};
char hora4b[6]= {'0','0',':','0','0','\0'};
char hora4c[6]= {'0','0',':','0','0','\0'};
char hora4d[6]= {'0','0',':','0','0','\0'};

char hora5a[6]= {'0','0',':','0','0','\0'};
char hora5b[6]= {'0','0',':','0','0','\0'};
char hora5c[6]= {'0','0',':','0','0','\0'};
char hora5d[6]= {'0','0',':','0','0','\0'};

char hora6a[6]= {'0','0',':','0','0','\0'};
char hora6b[6]= {'0','0',':','0','0','\0'};
char hora6c[6]= {'0','0',':','0','0','\0'};
char hora6d[6]= {'0','0',':','0','0','\0'};

char hora7a[6]= {'0','0',':','0','0','\0'};
char hora7b[6]= {'0','0',':','0','0','\0'};
char hora7c[6]= {'0','0',':','0','0','\0'};
char hora7d[6]= {'0','0',':','0','0','\0'};

int estado1;
int estado2;
int estado3;
int estado4;
int estado5;
int estado6;
int estado7;
int estado9;

long horaCompleta = 0;

int temperaturagg;
int temperados;

int bombombom = 0;

int bombaestado=31;









/*
class estadoCalendario
  {  private:
          int esta1;
          int esta2;
          int esta3;
          int esta4;
          int esta5;
          int esta6;
          int esta7;

          int tempexterior;
          int tempinterior;
          
          int estaActivo9;

          //horas

            char ho1a[6]= {'0','0',':','0','0','\0'};
            char ho1b[6]= {'0','0',':','0','0','\0'};
            char ho1c[6]= {'0','0',':','0','0','\0'};
            char ho1d[6]= {'0','0',':','0','0','\0'};
            
            char ho2a[6]= {'0','0',':','0','0','\0'};
            char ho2b[6]= {'0','0',':','0','0','\0'};
            char ho2c[6]= {'0','0',':','0','0','\0'};
            char ho2d[6]= {'0','0',':','0','0','\0'};
            
            char ho3a[6]= {'0','0',':','0','0','\0'};
            char ho3b[6]= {'0','0',':','0','0','\0'};
            char ho3c[6]= {'0','0',':','0','0','\0'};
            char ho3d[6]= {'0','0',':','0','0','\0'};
            
            char ho4a[6]= {'0','0',':','0','0','\0'};
            char ho4b[6]= {'0','0',':','0','0','\0'};
            char ho4c[6]= {'0','0',':','0','0','\0'};
            char ho4d[6]= {'0','0',':','0','0','\0'};
            
            char ho5a[6]= {'0','0',':','0','0','\0'};
            char ho5b[6]= {'0','0',':','0','0','\0'};
            char ho5c[6]= {'0','0',':','0','0','\0'};
            char ho5d[6]= {'0','0',':','0','0','\0'};
            
            char ho6a[6]= {'0','0',':','0','0','\0'};
            char ho6b[6]= {'0','0',':','0','0','\0'};
            char ho6c[6]= {'0','0',':','0','0','\0'};
            char ho6d[6]= {'0','0',':','0','0','\0'};
            
            char ho7a[6]= {'0','0',':','0','0','\0'};
            char ho7b[6]= {'0','0',':','0','0','\0'};
            char ho7c[6]= {'0','0',':','0','0','\0'};
            char ho7d[6]= {'0','0',':','0','0','\0'};
          
     public:

            estadoCalendario::estadoCalendario(int t1 , int t2){  
              
             
             }

           
  };

*/















void setup()
{
    
    // disable Ethernet chip
    pinMode(bombaestado, OUTPUT);
   // digitalWrite(sonido, HIGH);
    //Wire.begin(); // Inicia el puerto I2C
     Serial.begin(9600);       // for debugging

    // initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(4)) {
        Serial.println("ERROR - SD card initialization failed!");
        
        infiniti();    // init failed
    }
    //directorios();
     Serial.println("carga force");
    cargaForce();

   

    
    Serial.println("carga lista");
    Serial.println("SUCCESS - SD card initialized.");
    // check for index.htm file
    if (!SD.exists("index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
        infiniti();  // can't find index file
    }
    Serial.println("SUCCESS - Found index.htm file.");
    Ethernet.begin(mac, ip, dnsserver, gateway, subnet);
    //Ethernet.begin(mac, ip); 
    server.begin();           // start to listen for clients
    Serial.println("Todo cargado, comenzando ...");
    actualizarBomba();
    Serial.println("primera ejucucion lista");
    cualquierCosa();
    Serial.println("segunda ejucucion lista");
    Wire.begin();
    rtc.begin();

    //rtc.setDateTime(dt);

    lcd.init();
    lcd.backlight();
    lcd.clear();
    sensors.begin();   //Se inicia el sensor
    

    











   
}

void loop()
{
   
    //Serial.println("busca cliente");
 
    EthernetClient client = server.available();  // try to get client
  
    pregunta();
    
    if (client) {  // got client?
        // Serial.println("cliente online");
        boolean currentLineIsBlank = true;
        boolean tranqui = false;
  
        while (client.connected()) {
          
         //  Serial.println("coneccion continua con cliente");
            if (client.available()) {   // client data available to read
              
            //  Serial.println("cliente solicita lectura");

            
              
                char c = client.read(); // read 1 byte (character) from client
                
                // buffer first part of HTTP request in HTTP_req array (string)
                Serial.println(c);
                req_index=0;
                if( c == 'G'){
                    HTTP_req[req_index] = c;
                    req_index++;
                   char letraPedido = client.read();
                   
                    while(  req_index < (REQ_BUF_SZ - 1) and (letraPedido != '\r') and (letraPedido != '\n') ){
                             
                            
                            
                            HTTP_req[req_index] = letraPedido;  //problema
                            req_index++;
                            letraPedido = client.read();
                            //compruebaExistencia();  
                            
                           // Serial.println(HTTP_req[req_index]);
                           
                       
                      }
                      HTTP_req[req_index] = '\0';
                     // limpiarBUBU();
                     tranqui=true;
                  
                  }
                
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
               
                
                
                        
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (tranqui) {
                    // send a standard http response header
                  Serial.println("correcto"); 
                  tranqui = false;
                   
                            
                       

                if(StrContains(HTTP_req, "valor")){
                            
                              client.println("HTTP/1.1 200 OK");
                              client.println("Content-Type: text/xml");
                              client.println("Connection: keep-alive");
                              client.println();
                              
                              analizarCadena(HTTP_req);
                }else if( StrContains(HTTP_req, "tily") ){
                              client.println("HTTP/1.1 200 OK");
                              client.println("Content-Type: text/xml");
                              client.println("Connection: keep-alive");
                              client.println();
                              analizarEntrada(HTTP_req);
                              actualizarSDpuno();
                }else if(  StrContains(HTTP_req, "pala") ){

                             client.println("HTTP/1.1 200 OK");
                              client.println("Content-Type: text/xml");
                              client.println("Connection: keep-alive");
                              client.println();
                              analizarEntradatres(HTTP_req);
                              actualizarSDptres();
                              cualquierCosa();
                              
                              


                  
                              }else if(StrContains(HTTP_req, "calendarioplease")){
                       
                                  client.println("HTTP/1.1 200 OK");
                                  client.println("Content-Type: text/xml");
                                  client.println("Connection: keep-alive");
                                  client.println();
                                  Serial.println("se transmitio correctamente desde sd");
                                  informeDeVarCalen();
                                  XML_responsetres(client);    
                  
                    }else if (StrContains(HTTP_req, "GET /page2.htm")) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connnection: close");
                        client.println();
                        webFile = SD.open("page2.htm");
                        actualizarBomba();
                        

                           
                    

                    }else if(StrContains(HTTP_req, "GET /page3.htm")){
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connnection: close");
                        client.println();
                        webFile = SD.open("page3.htm");
                      
                      
                    }else if (StrContains(HTTP_req, "ajax_inputs")) {
                        // send rest of HTTP header
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        XML_response(client);
                        
                        
                              
                          
                    }else if(StrContains(HTTP_req, "atrsdqseyo")){
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        Serial.println("se transmitio correctamente desde sd");
                        XML_responsedos(client);


                      
                    }else if(StrContains(HTTP_req, "favicon")){
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        webFile = SD.open("favicon.ico");

                        //darle el icono
                      
                    }else if(StrContains(HTTP_req, "clase")){


                                if(StrContains(HTTP_req, "invierno")){
                                  client.println("HTTP/1.1 200 OK");
                                  client.println("Content-Type: text/xml");
                                  client.println("Connection: keep-alive");
                                  client.println();

                                 // ejecucionClase(20);
                                  
                                  }else if(StrContains(HTTP_req, "verano")){
                                          client.println("HTTP/1.1 200 OK");
                                          client.println("Content-Type: text/xml");
                                          client.println("Connection: keep-alive");
                                          client.println();
                                           //ejecucionClase(35);
                                    
                                    }else if(StrContains(HTTP_req, "defecto")){
                                                    client.println("HTTP/1.1 200 OK");
                                                    client.println("Content-Type: text/xml");
                                                    client.println("Connection: keep-alive");
                                                    client.println();
                                                    // ejecucionClase(43);


                                      
                                      }


                      
                      
                      }
                    else {  // web page request
                        // send rest of HTTP header
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send web page
                      
                        webFile = SD.open("index.htm", FILE_READ);        // open web page file
                        Serial.println("indexo");
                        
                         
                    }
                    
                    if (webFile) {
                            Serial.println("cargando peido...");
                            while(webFile.available()) {
                                client.write(webFile.read()); // send web page to client
                            }
                            Serial.println("carga terminada");
                            webFile.close();
                        }
                    // display received HTTP request on serial port
                    Serial.println(HTTP_req);
                    tranqui = false;
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;

                    
                }//nunca entra
                
                // every line of text received from the client ends with \r\n
                
            } // end if (client.available())
         
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
        
    } // end if (client)
 
}

// send the XML file containing analog value
void XML_responsedos(EthernetClient cl){

    int analog_val;
    //delay(50);
    cl.println("<?xml version = \"1.0\" ?>");
    cl.println("<inputs>");

    int kc;
    for(kc = 0;kc<20;kc++){
          analog_val = trenNumerico[kc] ;       
         Serial.println(analog_val);
          cl.println("<analog>");              
          cl.println(analog_val);
          cl.println("</analog>");

    }

    cl.println("</inputs>");
  
  }









void XML_responsetres(EthernetClient cl){

    int valort;
    String hora;
    //delay(50);
    cl.println("<?xml version = \"1.0\" ?>");
    cl.println("<inputs>");

    
      
    hora = hora1a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora1b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora1c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora1d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado1;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);
    



    hora = hora2a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora2b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora2c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora2d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado2;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);






    hora = hora3a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora3b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora3c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora3d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado3;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);





    hora = hora4a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora4b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora4c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora4d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado4;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);
    




    hora = hora5a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora5b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora5c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora5d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado5;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);







    hora = hora6a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora6b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora6c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora6d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado6;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);




    hora = hora7a;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora7b;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora7c;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    hora = hora7d;     
    cl.println("<analog>");              
    cl.println(hora);
    cl.println("</analog>");

    valort = estado7;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);
    
    //mandar tempglobal
    valort = temperaturagg;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);

    valort = estado9;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);

    valort = temperados;     
    cl.println("<analog>");              
    cl.println(valort);
    cl.println("</analog>");
    Serial.println(valort);

    
    

    cl.println("</inputs>");
  
  }





void actualizarSDptres(){
  
                              char temporal[20];
                              //Serial.println(trenNumerico[3]);

                              for(int j = 0;j<20;j++){
                                
                                  temporal[j]=trenNumerico[j] + 48;
                               
                              }


                               
                              SD.remove("cualq.txt");
                              
                              myFileqqq = SD.open("cualq.txt", FILE_WRITE);
                              
                               myFileqqq.println(temporal);
                               //Serial.println(temporal);

                               myFileqqq.close();
  
  
  }


void actualizarSDpuno(){
  
   
                              char temporal[2];
                              temporal[0]=bomba + 48;
                               temporal[1]=automatico + 48;
                              SD.remove("confi.txt");
                              
                              myFiledd = SD.open("confi.txt", FILE_WRITE);
                              
                               myFiledd.println(temporal);
                               //Serial.println(temporal);

                               myFiledd.close();
  
  
  
  
  
  }


void XML_response(EthernetClient cl)
{
    int analog_val;
    //delay(50);
    cl.println("<?xml version = \"1.0\" ?>");
    cl.println("<inputs>");
    actualizarBomba();


  //llamar a precisar valores sensores
    //actualizarSensores();

    
    // read analog pin A2
   // analog_val = ((analogRead(2) + 1) / 11);
    analog_val = sensor1;
    cl.println("<analog>");
    cl.println(analog_val);
    cl.println("</analog>");
    
   // analog_val = ((analogRead(3) + 1) / 11);
    analog_val = sensordos;
    cl.println("<analog>");
    cl.println(analog_val);
    cl.println("</analog>");
    

   //int chk = DHT11.read(DHT11PIN);
   // analog_val = DHT11.temperature;        //eeeeeeeeeeeeeh como que tendria que leer de diferente forma, va nose, ya estoy mucho tiempo sin dormir
    analog_val = sensor3;
    Serial.println(analog_val);
    cl.println("<analog>");              //buscar funcion de lectura para temperatura sin la humedad (que nadie la llamo); 
    cl.println(analog_val);
    cl.println("</analog>");


    analog_val =  bomba;       
         
          cl.println("<analog>");              
          cl.println(analog_val);
          cl.println("</analog>");

           analog_val =  automatico;       
       
          cl.println("<analog>");              
          cl.println(analog_val);
          cl.println("</analog>");


          //bombaestado
          analog_val =  bombombom;
          cl.println("<analog>");              
          cl.println(analog_val);
          cl.println("</analog>");
          

    cl.println("</inputs>");
    
    //Serial.println(DHT11.temperature);
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length){
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }
    return 0;
    
}
void analizarEntradatres(char * str){

  int n = 0;
  int tal = 6;
  while((str[n] != 'f') && (tal == 6)){
      
        if(str[n]== 's'){
         
          if(str[n+1]== 'o'){
            

            
            for(int i=2;i<22;i++){
              
              trenNumerico[i-2]=(str[n+i])-48;
              
             
              
              }



            
            tal=1;
            
            }
          
          
          }
      
           n++;
         }

  
  
  }
void analizarEntrada(char * str){
  int n = 0;
  int tal = 6;
  while((str[n] != 'f') && (tal == 6)){
        if(str[n]== 'l'){
          if(str[n+1]== 'y'){
            
            bomba=(str[n+2])-48;
            automatico=(str[n+3])-48;
            tal=1;
            
            }
          
          
          }
      
           n++;
         }
  Serial.println(bomba);
  Serial.println(automatico);
  }
void analizarCadena(char * str){
  
  int n = 0;
  int tal = 6;
  while((str[n] != 'k') && (tal == 6)){

    if(str[n]=='o'){
        if(str[n+1]=='r'){
            if(str[n+2]=='x'){

                estado9 = (str[n+3])-48;
                Serial.println("estado9");
                tal=3;  
                for(int g = 0;g<50;g++){
                        cadeccc[g] = str[g];
                       
                  }
                  cadeccc[50]='\0';
                  //Serial.println(str);
                  //Serial.println("cadeccc el estado del calendario");
                  //Serial.println(cadeccc);
                  //Serial.println("cadeccc fin");

                  if (obtencionSD == 0 ){
                     pasajeccc();
                  }
                  //Serial.println(str);


                            
          
        }else if(str[n+2]=='='){


          if(str[n+3]=='w'){


               int numeronson = str[n+4]-48;
              temperados = (str[n+5]-48)+(numeronson*10);
              //Serial.println("ver dos");
              //Serial.println(temperados);
              //Serial.println("ver fin dos");
              tal=3;

              for(int g = 0;g<50;g++){
                        cadetempec[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajebcb();
                   }


            
            
            }else{
            //hay temperatura a partir de ahi
              int numeron = str[n+3]-48;
              temperaturagg = (str[n+4]-48)+(numeron*10); //posible
              //Serial.println("ver gg");
              //Serial.println(temperaturagg);
              //Serial.println("ver fin gg");
              tal=3;

              for(int g = 0;g<50;g++){
                        cadettt[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajettt();
                  }
          }


              
              
            }else if(str[n+2]=='0'){

                if(str[n+3]=='1'){
                  for(int g = 0;g<50;g++){
                        cadelunes[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajelunes();  //quien mas te llama?
                   }
                  if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora1a[0]=str[n+6];  
                    hora1a[1]=str[n+7];
                    hora1a[2]=  str[n+8];
                    hora1a[3]= str[n+9];
                    hora1a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora1b[0]=str[n+12];  
                          hora1b[1]=str[n+13];
                          hora1b[2]=str[n+14];
                          hora1b[3]=str[n+15];
                          hora1b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora1c[0]=str[n+18];  
                              hora1c[1]=str[n+19];
                              hora1c[2]=str[n+20];
                              hora1c[3]=str[n+21];
                              hora1c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora1d[0]=str[n+24];  
                                  hora1d[1]=str[n+25];
                                  hora1d[2]=str[n+26];
                                  hora1d[3]=str[n+27];
                                  hora1d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado1 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora1d[0]='0';  
                                  hora1d[1]='0';
                                  hora1d[2]=':';
                                  hora1d[3]='0';
                                  hora1d[4]='0';
                                  estado1 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora1c[0]='0';  
                                  hora1c[1]='0';
                                  hora1c[2]=':';
                                  hora1c[3]='0';
                                  hora1c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora1d[0]=str[n+19];
                                    hora1d[1]=str[n+20];
                                    hora1d[2]=str[n+21];
                                    hora1d[3]=str[n+22];
                                    hora1d[4]=str[n+23];

                                    estado1 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora1d[0]='0';  
                                      hora1d[1]='0';
                                      hora1d[2]=':';
                                      hora1d[3]='0';
                                      hora1d[4]='0';
                                      estado1 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora1b[0]='0';  
                                  hora1b[1]='0';
                                  hora1b[2]=':';
                                  hora1b[3]='0';
                                  hora1b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora1c[0]=str[n+13];
                                    hora1c[1]=str[n+14];
                                    hora1c[2]=str[n+15];
                                    hora1c[3]=str[n+16];
                                    hora1c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora1d[0]=str[n+19];
                                        hora1d[1]=str[n+20];
                                        hora1d[2]=str[n+21];
                                        hora1d[3]=str[n+22];
                                        hora1d[4]=str[n+23];

                                        estado1 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora1d[0]='0';  
                                        hora1d[1]='0';
                                        hora1d[2]=':';
                                        hora1d[3]='0';
                                        hora1d[4]='0';

                                            estado1 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora1c[0]='0';  
                                      hora1c[1]='0';
                                      hora1c[2]=':';
                                      hora1c[3]='0';
                                      hora1c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora1d[0]=str[n+14];
                                            hora1d[1]=str[n+15];
                                            hora1d[2]=str[n+16];
                                            hora1d[3]=str[n+17];
                                            hora1d[4]=str[n+18];

                                            estado1 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora1d[0]='0';  
                                          hora1d[1]='0';
                                          hora1d[2]=':';
                                          hora1d[3]='0';
                                          hora1d[4]='0';
                                          estado1 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora1a[0]='0';  
                                  hora1a[1]='0';
                                  hora1a[2]=':';
                                  hora1a[3]='0';
                                  hora1a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora1b[0]=str[n+7];
                                            hora1b[1]=str[n+8];
                                            hora1b[2]=str[n+9];
                                            hora1b[3]=str[n+10];
                                            hora1b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora1c[0]=str[n+13];
                                              hora1c[1]=str[n+14];
                                              hora1c[2]=str[n+15];
                                              hora1c[3]=str[n+16];
                                              hora1c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora1d[0]=str[n+19];
                                                hora1d[1]=str[n+20];
                                                hora1d[2]=str[n+21];
                                                hora1d[3]=str[n+22];
                                                hora1d[4]=str[n+23];
                                                  //estado
                                                estado1 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora1d[0]='0';  
                                                  hora1d[1]='0';
                                                  hora1d[2]=':';
                                                  hora1d[3]='0';
                                                  hora1d[4]='0';
                                                  estado1 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora1c[0]='0';  
                                                hora1c[1]='0';
                                                hora1c[2]=':';
                                                hora1c[3]='0';
                                                hora1c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora1d[0]=str[n+14];
                                                  hora1d[1]=str[n+15];
                                                  hora1d[2]=str[n+16];
                                                  hora1d[3]=str[n+17];
                                                  hora1d[4]=str[n+18];
                                                    //estado
                                                  estado1 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora1d[0]='0';  
                                                          hora1d[1]='0';
                                                          hora1d[2]=':';
                                                          hora1d[3]='0';
                                                          hora1d[4]='0';

                                                          estado1 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora1b[0]='0';  
                                  hora1b[1]='0';
                                  hora1b[2]=':';
                                  hora1b[3]='0';
                                  hora1b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora1c[0]=str[n+8];
                                                  hora1c[1]=str[n+9];
                                                  hora1c[2]=str[n+10];
                                                  hora1c[3]=str[n+11];
                                                  hora1c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora1d[0]=str[n+14];
                                                      hora1d[1]=str[n+15];
                                                      hora1d[2]=str[n+16];
                                                      hora1d[3]=str[n+17];
                                                      hora1d[4]=str[n+18];
                                                      
                                                        estado1 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora1d[0]='0';  
                                                      hora1d[1]='0';
                                                      hora1d[2]=':';
                                                      hora1d[3]='0';
                                                      hora1d[4]='0';
                                                      
                                                       estado1 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora1c[0]='0';  
                                        hora1c[1]='0';
                                        hora1c[2]=':';
                                        hora1c[3]='0';
                                        hora1c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora1d[0]=str[n+9];
                                                      hora1d[1]=str[n+10];
                                                      hora1d[2]=str[n+11];
                                                      hora1d[3]=str[n+12];
                                                      hora1d[4]=str[n+13];
                                                      
                                                      estado1 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora1d[0]='0';  
                                                        hora1d[1]='0';
                                                        hora1d[2]=':';
                                                        hora1d[3]='0';
                                                        hora1d[4]='0';

                                                      estado1 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                      
                  
                  }else
                if(str[n+3]=='2'){

                  for(int g = 0;g<50;g++){
                        cademartes[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajemartes();
                   }





                        if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora2a[0]=str[n+6];  
                    hora2a[1]=str[n+7];
                    hora2a[2]=  str[n+8];
                    hora2a[3]= str[n+9];
                    hora2a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora2b[0]=str[n+12];  
                          hora2b[1]=str[n+13];
                          hora2b[2]=str[n+14];
                          hora2b[3]=str[n+15];
                          hora2b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora2c[0]=str[n+18];  
                              hora2c[1]=str[n+19];
                              hora2c[2]=str[n+20];
                              hora2c[3]=str[n+21];
                              hora2c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora2d[0]=str[n+24];  
                                  hora2d[1]=str[n+25];
                                  hora2d[2]=str[n+26];
                                  hora2d[3]=str[n+27];
                                  hora2d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado2 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora2d[0]='0';  
                                  hora2d[1]='0';
                                  hora2d[2]=':';
                                  hora2d[3]='0';
                                  hora2d[4]='0';
                                  estado2 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora2c[0]='0';  
                                  hora2c[1]='0';
                                  hora2c[2]=':';
                                  hora2c[3]='0';
                                  hora2c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora2d[0]=str[n+19];
                                    hora2d[1]=str[n+20];
                                    hora2d[2]=str[n+21];
                                    hora2d[3]=str[n+22];
                                    hora2d[4]=str[n+23];

                                    estado2 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora2d[0]='0';  
                                      hora2d[1]='0';
                                      hora2d[2]=':';
                                      hora2d[3]='0';
                                      hora2d[4]='0';
                                      estado2 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora2b[0]='0';  
                                  hora2b[1]='0';
                                  hora2b[2]=':';
                                  hora2b[3]='0';
                                  hora2b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora2c[0]=str[n+13];
                                    hora2c[1]=str[n+14];
                                    hora2c[2]=str[n+15];
                                    hora2c[3]=str[n+16];
                                    hora2c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora2d[0]=str[n+19];
                                        hora2d[1]=str[n+20];
                                        hora2d[2]=str[n+21];
                                        hora2d[3]=str[n+22];
                                        hora2d[4]=str[n+23];

                                        estado2 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora2d[0]='0';  
                                        hora2d[1]='0';
                                        hora2d[2]=':';
                                        hora2d[3]='0';
                                        hora2d[4]='0';

                                            estado2 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora2c[0]='0';  
                                      hora2c[1]='0';
                                      hora2c[2]=':';
                                      hora2c[3]='0';
                                      hora2c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora2d[0]=str[n+14];
                                            hora2d[1]=str[n+15];
                                            hora2d[2]=str[n+16];
                                            hora2d[3]=str[n+17];
                                            hora2d[4]=str[n+18];

                                            estado2 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora2d[0]='0';  
                                          hora2d[1]='0';
                                          hora2d[2]=':';
                                          hora2d[3]='0';
                                          hora2d[4]='0';
                                          estado2 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora2a[0]='0';  
                                  hora2a[1]='0';
                                  hora2a[2]=':';
                                  hora2a[3]='0';
                                  hora2a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora2b[0]=str[n+7];
                                            hora2b[1]=str[n+8];
                                            hora2b[2]=str[n+9];
                                            hora2b[3]=str[n+10];
                                            hora2b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora2c[0]=str[n+13];
                                              hora2c[1]=str[n+14];
                                              hora2c[2]=str[n+15];
                                              hora2c[3]=str[n+16];
                                              hora2c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora2d[0]=str[n+19];
                                                hora2d[1]=str[n+20];
                                                hora2d[2]=str[n+21];
                                                hora2d[3]=str[n+22];
                                                hora2d[4]=str[n+23];
                                                  //estado
                                                estado2 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora2d[0]='0';  
                                                  hora2d[1]='0';
                                                  hora2d[2]=':';
                                                  hora2d[3]='0';
                                                  hora2d[4]='0';
                                                  estado2 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora2c[0]='0';  
                                                hora2c[1]='0';
                                                hora2c[2]=':';
                                                hora2c[3]='0';
                                                hora2c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora2d[0]=str[n+14];
                                                  hora2d[1]=str[n+15];
                                                  hora2d[2]=str[n+16];
                                                  hora2d[3]=str[n+17];
                                                  hora2d[4]=str[n+18];
                                                    //estado
                                                  estado2 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora2d[0]='0';  
                                                          hora2d[1]='0';
                                                          hora2d[2]=':';
                                                          hora2d[3]='0';
                                                          hora2d[4]='0';

                                                          estado2 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora2b[0]='0';  
                                  hora2b[1]='0';
                                  hora2b[2]=':';
                                  hora2b[3]='0';
                                  hora2b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora2c[0]=str[n+8];
                                                  hora2c[1]=str[n+9];
                                                  hora2c[2]=str[n+10];
                                                  hora2c[3]=str[n+11];
                                                  hora2c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora2d[0]=str[n+14];
                                                      hora2d[1]=str[n+15];
                                                      hora2d[2]=str[n+16];
                                                      hora2d[3]=str[n+17];
                                                      hora2d[4]=str[n+18];
                                                      
                                                        estado2 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora2d[0]='0';  
                                                      hora2d[1]='0';
                                                      hora2d[2]=':';
                                                      hora2d[3]='0';
                                                      hora2d[4]='0';
                                                      
                                                       estado2 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora2c[0]='0';  
                                        hora2c[1]='0';
                                        hora2c[2]=':';
                                        hora2c[3]='0';
                                        hora2c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora2d[0]=str[n+9];
                                                      hora2d[1]=str[n+10];
                                                      hora2d[2]=str[n+11];
                                                      hora2d[3]=str[n+12];
                                                      hora2d[4]=str[n+13];
                                                      
                                                      estado2 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora2d[0]='0';  
                                                        hora2d[1]='0';
                                                        hora2d[2]=':';
                                                        hora2d[3]='0';
                                                        hora2d[4]='0';

                                                      estado2 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  } //anidardo con else o conseguir hacerlo con Sswitch
                else if(str[n+3]=='3'){

                  for(int g = 0;g<50;g++){
                        cademiercoles[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajemiercoles();
                  }
                  
                  
                  
                    
                  
                  if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora3a[0]=str[n+6];  
                    hora3a[1]=str[n+7];
                    hora3a[2]=  str[n+8];
                    hora3a[3]= str[n+9];
                    hora3a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora3b[0]=str[n+12];  
                          hora3b[1]=str[n+13];
                          hora3b[2]=str[n+14];
                          hora3b[3]=str[n+15];
                          hora3b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora3c[0]=str[n+18];  
                              hora3c[1]=str[n+19];
                              hora3c[2]=str[n+20];
                              hora3c[3]=str[n+21];
                              hora3c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora3d[0]=str[n+24];  
                                  hora3d[1]=str[n+25];
                                  hora3d[2]=str[n+26];
                                  hora3d[3]=str[n+27];
                                  hora3d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado3 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora3d[0]='0';  
                                  hora3d[1]='0';
                                  hora3d[2]=':';
                                  hora3d[3]='0';
                                  hora3d[4]='0';
                                  estado3 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora3c[0]='0';  
                                  hora3c[1]='0';
                                  hora3c[2]=':';
                                  hora3c[3]='0';
                                  hora3c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora3d[0]=str[n+19];
                                    hora3d[1]=str[n+20];
                                    hora3d[2]=str[n+21];
                                    hora3d[3]=str[n+22];
                                    hora3d[4]=str[n+23];

                                    estado3 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora3d[0]='0';  
                                      hora3d[1]='0';
                                      hora3d[2]=':';
                                      hora3d[3]='0';
                                      hora3d[4]='0';
                                      estado3 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora3b[0]='0';  
                                  hora3b[1]='0';
                                  hora3b[2]=':';
                                  hora3b[3]='0';
                                  hora3b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora3c[0]=str[n+13];
                                    hora3c[1]=str[n+14];
                                    hora3c[2]=str[n+15];
                                    hora3c[3]=str[n+16];
                                    hora3c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora3d[0]=str[n+19];
                                        hora3d[1]=str[n+20];
                                        hora3d[2]=str[n+21];
                                        hora3d[3]=str[n+22];
                                        hora3d[4]=str[n+23];

                                        estado3 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora3d[0]='0';  
                                        hora3d[1]='0';
                                        hora3d[2]=':';
                                        hora3d[3]='0';
                                        hora3d[4]='0';

                                            estado3 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora3c[0]='0';  
                                      hora3c[1]='0';
                                      hora3c[2]=':';
                                      hora3c[3]='0';
                                      hora3c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora3d[0]=str[n+14];
                                            hora3d[1]=str[n+15];
                                            hora3d[2]=str[n+16];
                                            hora3d[3]=str[n+17];
                                            hora3d[4]=str[n+18];

                                            estado3 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora3d[0]='0';  
                                          hora3d[1]='0';
                                          hora3d[2]=':';
                                          hora3d[3]='0';
                                          hora3d[4]='0';
                                          estado3 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora3a[0]='0';  
                                  hora3a[1]='0';
                                  hora3a[2]=':';
                                  hora3a[3]='0';
                                  hora3a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora3b[0]=str[n+7];
                                            hora3b[1]=str[n+8];
                                            hora3b[2]=str[n+9];
                                            hora3b[3]=str[n+10];
                                            hora3b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora3c[0]=str[n+13];
                                              hora3c[1]=str[n+14];
                                              hora3c[2]=str[n+15];
                                              hora3c[3]=str[n+16];
                                              hora3c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora3d[0]=str[n+19];
                                                hora3d[1]=str[n+20];
                                                hora3d[2]=str[n+21];
                                                hora3d[3]=str[n+22];
                                                hora3d[4]=str[n+23];
                                                  //estado
                                                estado3 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora3d[0]='0';  
                                                  hora3d[1]='0';
                                                  hora3d[2]=':';
                                                  hora3d[3]='0';
                                                  hora3d[4]='0';
                                                  estado3 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora3c[0]='0';  
                                                hora3c[1]='0';
                                                hora3c[2]=':';
                                                hora3c[3]='0';
                                                hora3c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora3d[0]=str[n+14];
                                                  hora3d[1]=str[n+15];
                                                  hora3d[2]=str[n+16];
                                                  hora3d[3]=str[n+17];
                                                  hora3d[4]=str[n+18];
                                                    //estado
                                                  estado3 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora3d[0]='0';  
                                                          hora3d[1]='0';
                                                          hora3d[2]=':';
                                                          hora3d[3]='0';
                                                          hora3d[4]='0';

                                                          estado3 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora3b[0]='0';  
                                  hora3b[1]='0';
                                  hora3b[2]=':';
                                  hora3b[3]='0';
                                  hora3b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora3c[0]=str[n+8];
                                                  hora3c[1]=str[n+9];
                                                  hora3c[2]=str[n+10];
                                                  hora3c[3]=str[n+11];
                                                  hora3c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora3d[0]=str[n+14];
                                                      hora3d[1]=str[n+15];
                                                      hora3d[2]=str[n+16];
                                                      hora3d[3]=str[n+17];
                                                      hora3d[4]=str[n+18];
                                                      
                                                        estado3 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora3d[0]='0';  
                                                      hora3d[1]='0';
                                                      hora3d[2]=':';
                                                      hora3d[3]='0';
                                                      hora3d[4]='0';
                                                      
                                                       estado3 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora3c[0]='0';  
                                        hora3c[1]='0';
                                        hora3c[2]=':';
                                        hora3c[3]='0';
                                        hora3c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora3d[0]=str[n+9];
                                                      hora3d[1]=str[n+10];
                                                      hora3d[2]=str[n+11];
                                                      hora3d[3]=str[n+12];
                                                      hora3d[4]=str[n+13];
                                                      
                                                      estado3 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora3d[0]='0';  
                                                        hora3d[1]='0';
                                                        hora3d[2]=':';
                                                        hora3d[3]='0';
                                                        hora3d[4]='0';

                                                      estado3 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                  
                  
                  
                  
                  
                  
                  }else
                if(str[n+3]=='4'){

                  for(int g = 0;g<50;g++){
                        cadejueves[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajejueves();
                  }
                  
                  
                  
                  
                  
                  if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora4a[0]=str[n+6];  
                    hora4a[1]=str[n+7];
                    hora4a[2]=  str[n+8];
                    hora4a[3]= str[n+9];
                    hora4a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora4b[0]=str[n+12];  
                          hora4b[1]=str[n+13];
                          hora4b[2]=str[n+14];
                          hora4b[3]=str[n+15];
                          hora4b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora4c[0]=str[n+18];  
                              hora4c[1]=str[n+19];
                              hora4c[2]=str[n+20];
                              hora4c[3]=str[n+21];
                              hora4c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora4d[0]=str[n+24];  
                                  hora4d[1]=str[n+25];
                                  hora4d[2]=str[n+26];
                                  hora4d[3]=str[n+27];
                                  hora4d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado4 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora4d[0]='0';  
                                  hora4d[1]='0';
                                  hora4d[2]=':';
                                  hora4d[3]='0';
                                  hora4d[4]='0';
                                  estado4 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora4c[0]='0';  
                                  hora4c[1]='0';
                                  hora4c[2]=':';
                                  hora4c[3]='0';
                                  hora4c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora4d[0]=str[n+19];
                                    hora4d[1]=str[n+20];
                                    hora4d[2]=str[n+21];
                                    hora4d[3]=str[n+22];
                                    hora4d[4]=str[n+23];

                                    estado4 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora4d[0]='0';  
                                      hora4d[1]='0';
                                      hora4d[2]=':';
                                      hora4d[3]='0';
                                      hora4d[4]='0';
                                      estado4 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora4b[0]='0';  
                                  hora4b[1]='0';
                                  hora4b[2]=':';
                                  hora4b[3]='0';
                                  hora4b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora4c[0]=str[n+13];
                                    hora4c[1]=str[n+14];
                                    hora4c[2]=str[n+15];
                                    hora4c[3]=str[n+16];
                                    hora4c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora4d[0]=str[n+19];
                                        hora4d[1]=str[n+20];
                                        hora4d[2]=str[n+21];
                                        hora4d[3]=str[n+22];
                                        hora4d[4]=str[n+23];

                                        estado4 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora4d[0]='0';  
                                        hora4d[1]='0';
                                        hora4d[2]=':';
                                        hora4d[3]='0';
                                        hora4d[4]='0';

                                            estado4 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora4c[0]='0';  
                                      hora4c[1]='0';
                                      hora4c[2]=':';
                                      hora4c[3]='0';
                                      hora4c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora4d[0]=str[n+14];
                                            hora4d[1]=str[n+15];
                                            hora4d[2]=str[n+16];
                                            hora4d[3]=str[n+17];
                                            hora4d[4]=str[n+18];

                                            estado4 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora4d[0]='0';  
                                          hora4d[1]='0';
                                          hora4d[2]=':';
                                          hora4d[3]='0';
                                          hora4d[4]='0';
                                          estado4 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora4a[0]='0';  
                                  hora4a[1]='0';
                                  hora4a[2]=':';
                                  hora4a[3]='0';
                                  hora4a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora4b[0]=str[n+7];
                                            hora4b[1]=str[n+8];
                                            hora4b[2]=str[n+9];
                                            hora4b[3]=str[n+10];
                                            hora4b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora4c[0]=str[n+13];
                                              hora4c[1]=str[n+14];
                                              hora4c[2]=str[n+15];
                                              hora4c[3]=str[n+16];
                                              hora4c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora4d[0]=str[n+19];
                                                hora4d[1]=str[n+20];
                                                hora4d[2]=str[n+21];
                                                hora4d[3]=str[n+22];
                                                hora4d[4]=str[n+23];
                                                  //estado
                                                estado4 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora4d[0]='0';  
                                                  hora4d[1]='0';
                                                  hora4d[2]=':';
                                                  hora4d[3]='0';
                                                  hora4d[4]='0';
                                                  estado4 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora4c[0]='0';  
                                                hora4c[1]='0';
                                                hora4c[2]=':';
                                                hora4c[3]='0';
                                                hora4c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora4d[0]=str[n+14];
                                                  hora4d[1]=str[n+15];
                                                  hora4d[2]=str[n+16];
                                                  hora4d[3]=str[n+17];
                                                  hora4d[4]=str[n+18];
                                                    //estado
                                                  estado4 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora4d[0]='0';  
                                                          hora4d[1]='0';
                                                          hora4d[2]=':';
                                                          hora4d[3]='0';
                                                          hora4d[4]='0';

                                                          estado4 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora4b[0]='0';  
                                  hora4b[1]='0';
                                  hora4b[2]=':';
                                  hora4b[3]='0';
                                  hora4b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora4c[0]=str[n+8];
                                                  hora4c[1]=str[n+9];
                                                  hora4c[2]=str[n+10];
                                                  hora4c[3]=str[n+11];
                                                  hora4c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora4d[0]=str[n+14];
                                                      hora4d[1]=str[n+15];
                                                      hora4d[2]=str[n+16];
                                                      hora4d[3]=str[n+17];
                                                      hora4d[4]=str[n+18];
                                                      
                                                        estado4 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora4d[0]='0';  
                                                      hora4d[1]='0';
                                                      hora4d[2]=':';
                                                      hora4d[3]='0';
                                                      hora4d[4]='0';
                                                      
                                                       estado4 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora4c[0]='0';  
                                        hora4c[1]='0';
                                        hora4c[2]=':';
                                        hora4c[3]='0';
                                        hora4c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora4d[0]=str[n+9];
                                                      hora4d[1]=str[n+10];
                                                      hora4d[2]=str[n+11];
                                                      hora4d[3]=str[n+12];
                                                      hora4d[4]=str[n+13];
                                                      
                                                      estado4 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora4d[0]='0';  
                                                        hora4d[1]='0';
                                                        hora4d[2]=':';
                                                        hora4d[3]='0';
                                                        hora4d[4]='0';

                                                      estado4 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                  
                  
                  
                  
                  
                  
                  
                  
                  }
               else if(str[n+3]=='5'){



                for(int g = 0;g<50;g++){
                        cadeviernes[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajeviernes();}
                
                
                
                
                
                if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora5a[0]=str[n+6];  
                    hora5a[1]=str[n+7];
                    hora5a[2]=  str[n+8];
                    hora5a[3]= str[n+9];
                    hora5a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora5b[0]=str[n+12];  
                          hora5b[1]=str[n+13];
                          hora5b[2]=str[n+14];
                          hora5b[3]=str[n+15];
                          hora5b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora5c[0]=str[n+18];  
                              hora5c[1]=str[n+19];
                              hora5c[2]=str[n+20];
                              hora5c[3]=str[n+21];
                              hora5c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora5d[0]=str[n+24];  
                                  hora5d[1]=str[n+25];
                                  hora5d[2]=str[n+26];
                                  hora5d[3]=str[n+27];
                                  hora5d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado5 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora5d[0]='0';  
                                  hora5d[1]='0';
                                  hora5d[2]=':';
                                  hora5d[3]='0';
                                  hora5d[4]='0';
                                  estado5 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora5c[0]='0';  
                                  hora5c[1]='0';
                                  hora5c[2]=':';
                                  hora5c[3]='0';
                                  hora5c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora5d[0]=str[n+19];
                                    hora5d[1]=str[n+20];
                                    hora5d[2]=str[n+21];
                                    hora5d[3]=str[n+22];
                                    hora5d[4]=str[n+23];

                                    estado5 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora5d[0]='0';  
                                      hora5d[1]='0';
                                      hora5d[2]=':';
                                      hora5d[3]='0';
                                      hora5d[4]='0';
                                      estado5 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora5b[0]='0';  
                                  hora5b[1]='0';
                                  hora5b[2]=':';
                                  hora5b[3]='0';
                                  hora5b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora5c[0]=str[n+13];
                                    hora5c[1]=str[n+14];
                                    hora5c[2]=str[n+15];
                                    hora5c[3]=str[n+16];
                                    hora5c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora5d[0]=str[n+19];
                                        hora5d[1]=str[n+20];
                                        hora5d[2]=str[n+21];
                                        hora5d[3]=str[n+22];
                                        hora5d[4]=str[n+23];

                                        estado5 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora5d[0]='0';  
                                        hora5d[1]='0';
                                        hora5d[2]=':';
                                        hora5d[3]='0';
                                        hora5d[4]='0';

                                            estado5 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora5c[0]='0';  
                                      hora5c[1]='0';
                                      hora5c[2]=':';
                                      hora5c[3]='0';
                                      hora5c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora5d[0]=str[n+14];
                                            hora5d[1]=str[n+15];
                                            hora5d[2]=str[n+16];
                                            hora5d[3]=str[n+17];
                                            hora5d[4]=str[n+18];

                                            estado5 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora5d[0]='0';  
                                          hora5d[1]='0';
                                          hora5d[2]=':';
                                          hora5d[3]='0';
                                          hora5d[4]='0';
                                          estado5 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora5a[0]='0';  
                                  hora5a[1]='0';
                                  hora5a[2]=':';
                                  hora5a[3]='0';
                                  hora5a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora5b[0]=str[n+7];
                                            hora5b[1]=str[n+8];
                                            hora5b[2]=str[n+9];
                                            hora5b[3]=str[n+10];
                                            hora5b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora5c[0]=str[n+13];
                                              hora5c[1]=str[n+14];
                                              hora5c[2]=str[n+15];
                                              hora5c[3]=str[n+16];
                                              hora5c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora5d[0]=str[n+19];
                                                hora5d[1]=str[n+20];
                                                hora5d[2]=str[n+21];
                                                hora5d[3]=str[n+22];
                                                hora5d[4]=str[n+23];
                                                  //estado
                                                estado5 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora5d[0]='0';  
                                                  hora5d[1]='0';
                                                  hora5d[2]=':';
                                                  hora5d[3]='0';
                                                  hora5d[4]='0';
                                                  estado5 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora5c[0]='0';  
                                                hora5c[1]='0';
                                                hora5c[2]=':';
                                                hora5c[3]='0';
                                                hora5c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora5d[0]=str[n+14];
                                                  hora5d[1]=str[n+15];
                                                  hora5d[2]=str[n+16];
                                                  hora5d[3]=str[n+17];
                                                  hora5d[4]=str[n+18];
                                                    //estado
                                                  estado5 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora5d[0]='0';  
                                                          hora5d[1]='0';
                                                          hora5d[2]=':';
                                                          hora5d[3]='0';
                                                          hora5d[4]='0';

                                                          estado5 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora5b[0]='0';  
                                  hora5b[1]='0';
                                  hora5b[2]=':';
                                  hora5b[3]='0';
                                  hora5b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora5c[0]=str[n+8];
                                                  hora5c[1]=str[n+9];
                                                  hora5c[2]=str[n+10];
                                                  hora5c[3]=str[n+11];
                                                  hora5c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora5d[0]=str[n+14];
                                                      hora5d[1]=str[n+15];
                                                      hora5d[2]=str[n+16];
                                                      hora5d[3]=str[n+17];
                                                      hora5d[4]=str[n+18];
                                                      
                                                        estado5 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora5d[0]='0';  
                                                      hora5d[1]='0';
                                                      hora5d[2]=':';
                                                      hora5d[3]='0';
                                                      hora5d[4]='0';
                                                      
                                                       estado5 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora5c[0]='0';  
                                        hora5c[1]='0';
                                        hora5c[2]=':';
                                        hora5c[3]='0';
                                        hora5c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora5d[0]=str[n+9];
                                                      hora5d[1]=str[n+10];
                                                      hora5d[2]=str[n+11];
                                                      hora5d[3]=str[n+12];
                                                      hora5d[4]=str[n+13];
                                                      
                                                      estado5 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora5d[0]='0';  
                                                        hora5d[1]='0';
                                                        hora5d[2]=':';
                                                        hora5d[3]='0';
                                                        hora5d[4]='0';

                                                      estado5 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                
                
                
                
                
                
                
                }else
                if(str[n+3]=='6'){

                  for(int g = 0;g<50;g++){
                        cadesabado[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajesabado();}
                  
                  
                  
                  if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora6a[0]=str[n+6];  
                    hora6a[1]=str[n+7];
                    hora6a[2]=  str[n+8];
                    hora6a[3]= str[n+9];
                    hora6a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora6b[0]=str[n+12];  
                          hora6b[1]=str[n+13];
                          hora6b[2]=str[n+14];
                          hora6b[3]=str[n+15];
                          hora6b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora6c[0]=str[n+18];  
                              hora6c[1]=str[n+19];
                              hora6c[2]=str[n+20];
                              hora6c[3]=str[n+21];
                              hora6c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora6d[0]=str[n+24];  
                                  hora6d[1]=str[n+25];
                                  hora6d[2]=str[n+26];
                                  hora6d[3]=str[n+27];
                                  hora6d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado6 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora6d[0]='0';  
                                  hora6d[1]='0';
                                  hora6d[2]=':';
                                  hora6d[3]='0';
                                  hora6d[4]='0';
                                  estado6 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora6c[0]='0';  
                                  hora6c[1]='0';
                                  hora6c[2]=':';
                                  hora6c[3]='0';
                                  hora6c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora6d[0]=str[n+19];
                                    hora6d[1]=str[n+20];
                                    hora6d[2]=str[n+21];
                                    hora6d[3]=str[n+22];
                                    hora6d[4]=str[n+23];

                                    estado6 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora6d[0]='0';  
                                      hora6d[1]='0';
                                      hora6d[2]=':';
                                      hora6d[3]='0';
                                      hora6d[4]='0';
                                      estado6 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora6b[0]='0';  
                                  hora6b[1]='0';
                                  hora6b[2]=':';
                                  hora6b[3]='0';
                                  hora6b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora6c[0]=str[n+13];
                                    hora6c[1]=str[n+14];
                                    hora6c[2]=str[n+15];
                                    hora6c[3]=str[n+16];
                                    hora6c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora6d[0]=str[n+19];
                                        hora6d[1]=str[n+20];
                                        hora6d[2]=str[n+21];
                                        hora6d[3]=str[n+22];
                                        hora6d[4]=str[n+23];

                                        estado6 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora6d[0]='0';  
                                        hora6d[1]='0';
                                        hora6d[2]=':';
                                        hora6d[3]='0';
                                        hora6d[4]='0';

                                            estado6 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora6c[0]='0';  
                                      hora6c[1]='0';
                                      hora6c[2]=':';
                                      hora6c[3]='0';
                                      hora6c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora6d[0]=str[n+14];
                                            hora6d[1]=str[n+15];
                                            hora6d[2]=str[n+16];
                                            hora6d[3]=str[n+17];
                                            hora6d[4]=str[n+18];

                                            estado6 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora6d[0]='0';  
                                          hora6d[1]='0';
                                          hora6d[2]=':';
                                          hora6d[3]='0';
                                          hora6d[4]='0';
                                          estado6 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora6a[0]='0';  
                                  hora6a[1]='0';
                                  hora6a[2]=':';
                                  hora6a[3]='0';
                                  hora6a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora6b[0]=str[n+7];
                                            hora6b[1]=str[n+8];
                                            hora6b[2]=str[n+9];
                                            hora6b[3]=str[n+10];
                                            hora6b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora6c[0]=str[n+13];
                                              hora6c[1]=str[n+14];
                                              hora6c[2]=str[n+15];
                                              hora6c[3]=str[n+16];
                                              hora6c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora6d[0]=str[n+19];
                                                hora6d[1]=str[n+20];
                                                hora6d[2]=str[n+21];
                                                hora6d[3]=str[n+22];
                                                hora6d[4]=str[n+23];
                                                  //estado
                                                estado6 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora6d[0]='0';  
                                                  hora6d[1]='0';
                                                  hora6d[2]=':';
                                                  hora6d[3]='0';
                                                  hora6d[4]='0';
                                                  estado6 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora6c[0]='0';  
                                                hora6c[1]='0';
                                                hora6c[2]=':';
                                                hora6c[3]='0';
                                                hora6c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora6d[0]=str[n+14];
                                                  hora6d[1]=str[n+15];
                                                  hora6d[2]=str[n+16];
                                                  hora6d[3]=str[n+17];
                                                  hora6d[4]=str[n+18];
                                                    //estado
                                                  estado6 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora6d[0]='0';  
                                                          hora6d[1]='0';
                                                          hora6d[2]=':';
                                                          hora6d[3]='0';
                                                          hora6d[4]='0';

                                                          estado6 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora6b[0]='0';  
                                  hora6b[1]='0';
                                  hora6b[2]=':';
                                  hora6b[3]='0';
                                  hora6b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora6c[0]=str[n+8];
                                                  hora6c[1]=str[n+9];
                                                  hora6c[2]=str[n+10];
                                                  hora6c[3]=str[n+11];
                                                  hora6c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora6d[0]=str[n+14];
                                                      hora6d[1]=str[n+15];
                                                      hora6d[2]=str[n+16];
                                                      hora6d[3]=str[n+17];
                                                      hora6d[4]=str[n+18];
                                                      
                                                        estado6 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora6d[0]='0';  
                                                      hora6d[1]='0';
                                                      hora6d[2]=':';
                                                      hora6d[3]='0';
                                                      hora6d[4]='0';
                                                      
                                                       estado6 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora6c[0]='0';  
                                        hora6c[1]='0';
                                        hora6c[2]=':';
                                        hora6c[3]='0';
                                        hora6c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora6d[0]=str[n+9];
                                                      hora6d[1]=str[n+10];
                                                      hora6d[2]=str[n+11];
                                                      hora6d[3]=str[n+12];
                                                      hora6d[4]=str[n+13];
                                                      
                                                      estado6 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora6d[0]='0';  
                                                        hora6d[1]='0';
                                                        hora6d[2]=':';
                                                        hora6d[3]='0';
                                                        hora6d[4]='0';

                                                      estado6 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                  
                  
                  
                  
                  
                  }else
                if(str[n+3]=='7'){

                  for(int g = 0;g<50;g++){
                        cadedomingo[g] = str[g];
                       
                  }
                   if (obtencionSD == 0 ){
                  pasajedomingo();}
                  
                  
                  
                  
                  if(str[n+6]!='b'){ //si hay valor de a, procedo a tomarlo

                    hora7a[0]=str[n+6];  
                    hora7a[1]=str[n+7];
                    hora7a[2]=  str[n+8];
                    hora7a[3]= str[n+9];
                    hora7a[4]=str[n+10];

                    if(str[n+12] != 'c'){  //hay b, lo tomo

                          hora7b[0]=str[n+12];  
                          hora7b[1]=str[n+13];
                          hora7b[2]=str[n+14];
                          hora7b[3]=str[n+15];
                          hora7b[4]=str[n+16];

                          if(str[n+18] != 'd'){ //hay c , lo tomo

                              hora7c[0]=str[n+18];  
                              hora7c[1]=str[n+19];
                              hora7c[2]=str[n+20];
                              hora7c[3]=str[n+21];
                              hora7c[4]=str[n+22];

                              if(str[n+24] != 'e'){ //hay d, lo tomo

                                  hora7d[0]=str[n+24];  
                                  hora7d[1]=str[n+25];
                                  hora7d[2]=str[n+26];
                                  hora7d[3]=str[n+27];
                                  hora7d[4]=str[n+28];

                                  //termine ahora veo el estado y termina el analicis del primer get
                                  estado7 =str[n+30] - 48;//se pasa a 30 porque en 29 esta la letra t, se pasa a boolean

                                  tal=1; //para salir del while
                                
                                
                                }else if(str[n+24] == 'e'){ //no hay d, sigo con el estado

                                  hora7d[0]='0';  
                                  hora7d[1]='0';
                                  hora7d[2]=':';
                                  hora7d[3]='0';
                                  hora7d[4]='0';
                                  estado7 =str[n+25] - 48;
                                  tal=1;
                                  }
                            
                            
                            }else if(str[n+18] == 'd'){ //no hay c,  porque me encontre con d

                                  hora7c[0]='0';  
                                  hora7c[1]='0';
                                  hora7c[2]=':';
                                  hora7c[3]='0';
                                  hora7c[4]='0';

                                  
                                  if(str[n+19] != 'e'){ //hay d, lo tomo
                                    
                                    hora7d[0]=str[n+19];
                                    hora7d[1]=str[n+20];
                                    hora7d[2]=str[n+21];
                                    hora7d[3]=str[n+22];
                                    hora7d[4]=str[n+23];

                                    estado7 =str[n+25] - 48;
                                    tal=1;
                                    
                                    
                                    }else if(str[n+19] == 'e'){ // no hay d sigo con estado
                                      hora7d[0]='0';  
                                      hora7d[1]='0';
                                      hora7d[2]=':';
                                      hora7d[3]='0';
                                      hora7d[4]='0';
                                      estado7 =str[n+20] - 48;
                                      tal=1;
                                      }
                              
                              }
                      
                      
                      }else if(str[n+12] == 'c'){ //no hay b, sigo con otra cosa

                                  hora7b[0]='0';  
                                  hora7b[1]='0';
                                  hora7b[2]=':';
                                  hora7b[3]='0';
                                  hora7b[4]='0';

                              if(str[n+13] != 'd'){ //si hay c, tomo

                                
                                    hora7c[0]=str[n+13];
                                    hora7c[1]=str[n+14];
                                    hora7c[2]=str[n+15];
                                    hora7c[3]=str[n+16];
                                    hora7c[4]=str[n+17];

                                    if( str[n+19] != 'e' ){ //hat d , lo tomo

                                        hora7d[0]=str[n+19];
                                        hora7d[1]=str[n+20];
                                        hora7d[2]=str[n+21];
                                        hora7d[3]=str[n+22];
                                        hora7d[4]=str[n+23];

                                        estado7 =str[n+25] - 48;
                                         tal=1;
                                      
                                      }else if( str[n+19] == 'e'  ){//no hay d, sigo con estado


                                        hora7d[0]='0';  
                                        hora7d[1]='0';
                                        hora7d[2]=':';
                                        hora7d[3]='0';
                                        hora7d[4]='0';

                                            estado7 =str[n+20] - 48;
                                             tal=1;

                                        
                                        }
                                
                                
                                }else if(str[n+13] == 'd'){ //no hay c pq ta d en vez de una hora

                                      hora7c[0]='0';  
                                      hora7c[1]='0';
                                      hora7c[2]=':';
                                      hora7c[3]='0';
                                      hora7c[4]='0';
                                      

                                      if(str[n+14] != 'e'){ //hay d , lo tomo

                                            hora7d[0]=str[n+14];
                                            hora7d[1]=str[n+15];
                                            hora7d[2]=str[n+16];
                                            hora7d[3]=str[n+17];
                                            hora7d[4]=str[n+18];

                                            estado7 =str[n+20] - 48;
                                             tal=1;
                                        
                                        
                                        }else if(str[n+14] == 'e'  ){ //no hay d, voy con el estado
                                          
                                          hora7d[0]='0';  
                                          hora7d[1]='0';
                                          hora7d[2]=':';
                                          hora7d[3]='0';
                                          hora7d[4]='0';
                                          estado7 =str[n+15] - 48;
                                             tal=1;
                                          
                                          }

                                  
                                  
                                  }



                        
                        }

                    
                    }else if(str[n+6]=='b'){ //si hay b entonces no hay a para tomar


                                  hora7a[0]='0';  
                                  hora7a[1]='0';
                                  hora7a[2]=':';
                                  hora7a[3]='0';
                                  hora7a[4]='0';
                      
                      if(str[n+7]!='c'){//hay b, lo tomo
                        
                                            hora7b[0]=str[n+7];
                                            hora7b[1]=str[n+8];
                                            hora7b[2]=str[n+9];
                                            hora7b[3]=str[n+10];
                                            hora7b[4]=str[n+11];

                                            if(str[n+13]!='d'){ //hay c, lo tomo

                                              hora7c[0]=str[n+13];
                                              hora7c[1]=str[n+14];
                                              hora7c[2]=str[n+15];
                                              hora7c[3]=str[n+16];
                                              hora7c[4]=str[n+17];

                                              if(str[n+19]!='e'){ //hay d, lo tomo

                                                hora7d[0]=str[n+19];
                                                hora7d[1]=str[n+20];
                                                hora7d[2]=str[n+21];
                                                hora7d[3]=str[n+22];
                                                hora7d[4]=str[n+23];
                                                  //estado
                                                estado7 =str[n+25] - 48;
                                                tal=1;
                                                
                                                
                                                
                                                }else if( str[n+19]=='e' ){//no hay d, sigo con el estado
                                                  hora7d[0]='0';  
                                                  hora7d[1]='0';
                                                  hora7d[2]=':';
                                                  hora7d[3]='0';
                                                  hora7d[4]='0';
                                                  estado7 =str[n+20] - 48;
                                                   tal=1;
                                                
                                                  
                                                  }

                                              
                                              
                                              
                                              }else if(str[n+13]=='d'){ //no hay c para tomar, sigo con otra cosa


                                                hora7c[0]='0';  
                                                hora7c[1]='0';
                                                hora7c[2]=':';
                                                hora7c[3]='0';
                                                hora7c[4]='0';

                                                if( str[n+14]!='e' ){ //hay d, lo tomo

                                                  hora7d[0]=str[n+14];
                                                  hora7d[1]=str[n+15];
                                                  hora7d[2]=str[n+16];
                                                  hora7d[3]=str[n+17];
                                                  hora7d[4]=str[n+18];
                                                    //estado
                                                  estado7 =str[n+20] - 48;
                                                  tal=1;
                                                  
                                                  
                                                  } else if( str[n+14]=='e' ){//no hay d, sigo con otra cosa

                                                          hora7d[0]='0';  
                                                          hora7d[1]='0';
                                                          hora7d[2]=':';
                                                          hora7d[3]='0';
                                                          hora7d[4]='0';

                                                          estado7 =str[n+15] - 48;
                                                           tal=1;
                                                    
                                                    }
                                                
                                                
                                                
                                                
                                                }
                        
                        
                        
                        }else if( str[n+7]=='c' ){ //no hay b, sigo con otra cosa

                                  hora7b[0]='0';  
                                  hora7b[1]='0';
                                  hora7b[2]=':';
                                  hora7b[3]='0';
                                  hora7b[4]='0';

                              if(str[n+8]!='d'  ){//hay c, lo tomo
                                
                                                  hora7c[0]=str[n+8];
                                                  hora7c[1]=str[n+9];
                                                  hora7c[2]=str[n+10];
                                                  hora7c[3]=str[n+11];
                                                  hora7c[4]=str[n+12];
                                                 
                                                  if( str[n+14]!='e' ){//hay d , lo tomo

                                                      hora7d[0]=str[n+14];
                                                      hora7d[1]=str[n+15];
                                                      hora7d[2]=str[n+16];
                                                      hora7d[3]=str[n+17];
                                                      hora7d[4]=str[n+18];
                                                      
                                                        estado7 =str[n+20] - 48;
                                                           tal=1;
                                                    
                                                    
                                                    
                                                    }else if( str[n+14]=='e' ){//no hay d, sigo con estado

                                                      hora7d[0]='0';  
                                                      hora7d[1]='0';
                                                      hora7d[2]=':';
                                                      hora7d[3]='0';
                                                      hora7d[4]='0';
                                                      
                                                       estado7 =str[n+15] - 48;
                                                           tal=1;
                                                      
                                                      }
                                
                                }else if( str[n+8]=='d' ){//no hay c, sigo con otra cosa

                                        hora7c[0]='0';  
                                        hora7c[1]='0';
                                        hora7c[2]=':';
                                        hora7c[3]='0';
                                        hora7c[4]='0';

                                        if( str[n+9]!='e' ){//hay d, lo tomo
                                          
                                                      hora7d[0]=str[n+9];
                                                      hora7d[1]=str[n+10];
                                                      hora7d[2]=str[n+11];
                                                      hora7d[3]=str[n+12];
                                                      hora7d[4]=str[n+13];
                                                      
                                                      estado7 =str[n+15] - 48;
                                                      tal=1;
                                          
                                          }else if( str[n+9]=='e' ){//no hay d, sigo con estado
                                                        hora7d[0]='0';  
                                                        hora7d[1]='0';
                                                        hora7d[2]=':';
                                                        hora7d[3]='0';
                                                        hora7d[4]='0';

                                                      estado7 =str[n+10] - 48;
                                                      tal=1;
                                            
                                            }
                                  



                                  
                                  
                                  }
                          
                          
                          
                          }
                      
                      }
                  
                  
                  
                  
                  
                  
                  
                  
                  }
                
              
              
              }
           
          
          }
      
      }
    
    n++;
    }
    
  
  
  }










void informeDeVarCalen(){
  
  
  Serial.println("termino de analizar");
    Serial.println(hora1a);
    Serial.println(hora1b);
    Serial.println(hora1c);
    Serial.println(hora1d);
    Serial.println(estado1);
    
    Serial.println(hora2a);
    Serial.println(hora2b);
    Serial.println(hora2c);
    Serial.println(hora2d);
    Serial.println(estado2);
    Serial.println(hora3a);
    Serial.println(hora3b);
    Serial.println(hora3c);
    Serial.println(hora3d);
    Serial.println(estado3);
    Serial.println(hora4a);
    Serial.println(hora4b);
    Serial.println(hora4c);
    Serial.println(hora4d);
    Serial.println(estado4);
    Serial.println(hora5a);
    Serial.println(hora5b);
    Serial.println(hora5c);
    Serial.println(hora5d);
    Serial.println(estado5);
    Serial.println(hora6a);
    Serial.println(hora6b);
    Serial.println(hora6c);
    Serial.println(hora6d);
    Serial.println(estado6);
    Serial.println(hora7a);
    Serial.println(hora7b);
    Serial.println(hora7c);
    Serial.println(hora7d);
    Serial.println(estado7);
    Serial.println(temperaturagg);
  
  
  }









void pasajelunes(){  
        cadelunes[50] = '\0';                           
        SD.remove("dialu.txt");
        
        myFile2 = SD.open("dialu.txt", FILE_WRITE);                              
        myFile2.println(cadelunes);
        
        //Serial.println(cadelunes); // valor01= 
        
        myFile2.close();  
  }
void pasajemartes(){
        cademartes[50] = '\0';                                  
        SD.remove("diama.txt");
        
        myFile3 = SD.open("diama.txt", FILE_WRITE);                              
        myFile3.println(cademartes);
        //Serial.println(cademartes);
        myFile3.close();  
  }
  void pasajemiercoles(){                               
        cademiercoles[50] = '\0'; 
        SD.remove("diami.txt");
        
        myFile4 = SD.open("diami.txt", FILE_WRITE);                              
        myFile4.println(cademiercoles);
        //Serial.println(cademiercoles);
        myFile4.close();  
  }
  void pasajejueves(){                               
        cadejueves[50] = '\0'; 
        SD.remove("diaju.txt");
        
        myFile5 = SD.open("diaju.txt", FILE_WRITE);                              
        myFile5.println(cadejueves);
        
        Serial.println(cadejueves);
        myFile5.close();  
  }
  void pasajeviernes(){                               
        cadeviernes[50] = '\0'; 
        SD.remove("diavi.txt");
        
        myFile6 = SD.open("diavi.txt", FILE_WRITE);                              
        myFile6.println(cadeviernes);
        //Serial.println(cadeviernes);
        myFile6.close();  
  }
  void pasajesabado(){                               
        cadesabado[50] = '\0'; 
        SD.remove("diasa.txt");
        
        myFile7 = SD.open("diasa.txt", FILE_WRITE);                              
        myFile7.println(cadesabado);
        //Serial.println(cadesabado);
        myFile7.close();  
  }
  void pasajedomingo(){                               
        cadedomingo[50] = '\0'; 
        SD.remove("diado.txt");
        
        myFile8 = SD.open("diado.txt", FILE_WRITE);                              
        myFile8.println(cadedomingo);
        //Serial.println(cadedomingo);
        myFile8.close();  
  }
  void pasajettt(){                               
        cadettt[50] = '\0'; 
        SD.remove("tembb.txt");
        
        myFilet = SD.open("tembb.txt", FILE_WRITE);                              
        myFilet.println(cadettt);
        //Serial.println(cadettt);
        myFilet.close();  
  }
  void pasajeccc(){                               
        cadeccc[50] = '\0';
        SD.remove("diaes.txt");
        
        myFilecola = SD.open("diaes.txt", FILE_WRITE);                              
        myFilecola.println(cadeccc);
        Serial.println(cadeccc);
        myFilecola.close();  
  }



void pasajebcb(){
  
  
        cadetempec[50] = '\0';
        SD.remove("tembc.txt");
        
        myFileb = SD.open("tembc.txt", FILE_WRITE);                              
        myFileb.println(cadetempec);
        //Serial.println(cadetempec);
        myFileb.close();
  
  
  
  
  }







void cualquierCosa(){

  
  for(int p = 0; p < 20 ;p++){
    
    if(trenNumerico[p] == 1){

        digitalWrite(pinesVeinte[p],HIGH);
      }else{
        digitalWrite(pinesVeinte[p],LOW);
        }
    
    }

  
  }


void actualizarBomba(){
  
  
  
  actualizarSensores();
  lcd.clear();
  
  DateTime now = rtc.now();
  Serial.print(now.year(),DEC);
  Serial.print('/');
  Serial.print(now.month(),DEC);
  Serial.print('/');
  Serial.print(now.date(),DEC);
  Serial.print(' ');
  Serial.print(now.hour(),DEC);
  Serial.print(':');
  Serial.print(now.minute(),DEC);
  Serial.print(':');
  Serial.print(now.second(),DEC);
  Serial.print(' ');
  Serial.print(DiaSemana[now.dayOfWeek()]);
  Serial.println();
//otros Diez comienza en false,,, contador en 0.

  contador++;
  if((contador == 18) and (otrosDiez == false)){
      contador = 0;
      otrosDiez = true;        
    }

  if((contador == 4) and (otrosDiez == true)){
      contador = 0;
      otrosDiez = false;        
    }


if(otrosDiez){ //18 segundos false 4 segundos true.

  lcd.setCursor(0,0);
  lcd.print(now.year(),DEC);
  lcd.print('/');
  lcd.print(now.month(),DEC);
  lcd.print('/');
  lcd.print(now.date(),DEC);
  lcd.print(' ');
  lcd.print(DiaSemana[now.dayOfWeek()]);

  lcd.setCursor(0,1);
  lcd.print(now.hour(),DEC);
  lcd.print(':');
  lcd.print(now.minute(),DEC);
  lcd.print(':');
  lcd.print(now.second(),DEC);
  lcd.print(' ');
}else{
  
  lcd.setCursor(0,0);
  lcd.print("Tem1");
  lcd.print("  ");
  lcd.print("Tem2");
  lcd.print("  ");
  lcd.print("Tem3");
  

  lcd.setCursor(0,1);
  lcd.print(sensor1);
  lcd.print("  /  ");
  lcd.print(sensordos);
  lcd.print("  /  ");
  lcd.print(sensor3);

  
  
  
  
  
  
  }

  //si es temprano actualizar var completa
  if(now.hour() < 6){
    
    horaCompleta = 0;
    
    }
  
  Serial.println("bien");
  
  Serial.println(bomba);
   Serial.println(automatico);
    Serial.println(estado9);
     Serial.println(sensor1);
      Serial.println(sensordos);
       Serial.println(temperaturagg);
        Serial.println(temperados);
        Serial.println("fin muestra");
        tempoBomba=0;
  if(bomba){
    digitalWrite(bombaestado,HIGH);//si o si
    int bombombom = 1;
    //activar bomba
    }else if((automatico) and (diaBonito())){

      //pregunto por calendario
      if(estado9){
        //calendario activo
        //tomar dia-hora actual con reloj

          
         if(  diaActivo()  ){
                Serial.println("dia esta avtivo");
                if(  (   temperaturagg <= sensor1  )   and   (  temperados > sensordos     )   ){

                          if(hayLimite()){
                            digitalWrite(bombaestado,HIGH); //pty
                            int bombombom = 1;
                            }
                          

                  
                  }else{
                          if(hayLimite()){
                            digitalWrite(bombaestado,LOW); //pty
                            int bombombom = 0;
                          }
                          
                    }
                //preguntar por temperaturas.
          }else{
                  if(hayLimite()){
                    digitalWrite(bombaestado,LOW);
                    int bombombom = 0;
                    }
                  
            }
         



        
        //preguntar por dia VAR
        }else if(temperaturagg <= sensor1 ){
              Serial.println("primera pregunta entro");
              if(temperados > sensordos ){            //poner (sensordos - 2) grados, de modo que tenga un margen de dos grados para activarce???
                    Serial.println("segunda pregunta entro");
                    if(hayLimite()){
                        digitalWrite(bombaestado,HIGH); //pty
                        int bombombom = 1;
                      }
                    
                }else{
                    if(hayLimite()){
                        digitalWrite(bombaestado,LOW);//pty
                        int bombombom = 0;
                      }
                    
                  
                  }
                  
          
          }else{
                    if(hayLimite()){
                      digitalWrite(bombaestado,LOW);  //pty
                      int bombombom = 0;
                      }
                    
            
            }
      
      
      
      }else{ //si automatico y manual desactivados, apagar bomba
        
        digitalWrite(bombaestado,LOW); //si o si
        int bombombom = 0;
        
        
        
        }
  
  
  
  
  delay(10);
  
  }





void actualizarSensores(){
 
  
  sensor1 =  ((analogRead(2) + 1) / 11);
 
  sensordos =  ((analogRead(3) + 1) / 11);
  

 int chkk = DHT11.read(DHT11PIN);
 
  sensor3 = DHT11.temperature;
  
/*
sensors.requestTemperatures();  
//envía el comando para obtener las temperaturas

int locuno = sensors.getTempC(address1);//Se obtiene la temperatura en °C del sensor 1
int locdos = sensors.getTempC(address2);//Se obtiene la temperatura en °C del sensor 2
int loctres = sensors.getTempC(address3);//Se obtiene la temperatura en °C del sensor 3

if (locuno > 1){
  sensor1= locuno;
  }
if (locdos > 1){
  sensordos= locdos;
  }

if (loctres > 1){
  sensor3= loctres;
  }


*/

  
  
  }



void limpiarBUBU(){
  
  req_index = 0;
  StrClear(HTTP_req, REQ_BUF_SZ);
  
  
  
  }




























void cargaForce(){
    
    
     if (SD.exists("CUALQ.txt")) {
     
     
     myFileqw = SD.open("CUALQ.txt", FILE_READ);
     int letra;
     
     int n = 0;
     while(myFileqw.available()and(n<50)){
      
      letra=myFileqw.read();
      
      //ponerlo en array de enteros, aunque esta en char
      trenNumerico[n]=letra-48;
      n++;
      
      
      }
      myFileqw.close();
      trenNumerico[50]='\0';
  }else{
    Serial.println("no hay ygytytytt cualquiera.txt");
        infiniti();
    
    }






      if (SD.exists("diaes.txt")) {
    
     
     
     myFilees = SD.open("diaes.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilees.available()and(n<50)){
      //Serial.println(n);
      letra=myFilees.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadeestadocalen[n]=letra;
      n++;
      
      
      }
      myFilees.close();
      cadeestadocalen[50]='\0';
      //mandar a analizar la cadena
      Serial.println(cadeestadocalen);
     
      analizarCadena(cadeestadocalen);
      //Serial.println("estado bien");
      
      
  }else{
    
    Serial.println("no hay dialunes.txt");
        infiniti();
    
    }








      if (SD.exists("CONFI.txt")) {
        
     
     
     myFilefy = SD.open("confi.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilefy.available()and(n<50)){
      
      letra=myFilefy.read();
      
      //ponerlo en array de enteros, aunque esta en char
      if(n==0){
      bomba=(letra-48);
      }else if(n==1){
        automatico=(letra-48);
        }
      n++;
      
      
      }
      myFilefy.close();
      //Serial.println(bomba);
      //Serial.println(automatico);
  }else{
    
    Serial.println("no hay configuno.txt");
        infiniti();
    
    }




 if (SD.exists("dialu.txt")) {
    
     
     
     myFilell = SD.open("dialu.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilell.available()and(n<50)){
      
      letra=myFilell.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadelunes[n]=letra;
      n++;
      
      
      }
      myFilell.close();
      cadelunes[50]='\0';
      //mandar a analizar la cadena
      //Serial.println("bien hasta aca?");
      //Serial.println(estado1);
      Serial.println(cadelunes);
      analizarCadena(cadelunes);
      Serial.println(cadelunes);
      Serial.println("lunes cargado");
      //Serial.println(estado1);
  }else{
    
    Serial.println("no hay dialunes.txt");
        infiniti();
    
    }

 if (SD.exists("diama.txt")) {
     
     
     myFilegf = SD.open("diama.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilegf.available()and(n<50)){
      
      letra=myFilegf.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cademartes[n]=letra;
      n++;
      
      
      }
      myFilegf.close();
      cademartes[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cademartes);
  }else{
    
    Serial.println("no hay martes.txt");
        infiniti();
    
    }

   if (SD.exists("diami.txt")) {
     
     
     myFilejk = SD.open("diami.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilejk.available()and(n<50)){
      
      letra=myFilejk.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cademiercoles[n]=letra;
      n++;
      
      
      }
      myFilejk.close();
      cademiercoles[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cademiercoles);
  }else{
    
    Serial.println("no hay miercoles.txt");
        infiniti();
    
    }


 if (SD.exists("diaju.txt")) {
     
    
     myFilenm = SD.open("diaju.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilenm.available()and(n<50)){
      
      letra=myFilenm.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadejueves[n]=letra;
      n++;
      
      
      }
      myFilenm.close();
      cadejueves[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cadejueves);
  }else{
    
    Serial.println("no hay jueves.txt");
        infiniti();
    
    }

 if (SD.exists("diavi.txt")) {
     
     
     myFilert = SD.open("diavi.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilert.available()and(n<50)){
      
      letra=myFilert.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadeviernes[n]=letra;
      n++;
      
      
      }
      myFilert.close();
      cadeviernes[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cadeviernes);
  }else{
    
    Serial.println("no hay viernes.txt");
        infiniti();
    
    
    }



   if (SD.exists("diasa.txt")) {
     
     
     myFileza = SD.open("diasa.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFileza.available()and(n<50)){
      
      letra=myFileza.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadesabado[n]=letra;
      n++;
      
      
      }
      myFileza.close();
      cadesabado[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cadesabado);
  }else{
    
    Serial.println("no hay sabada.txt");
        infiniti();
    
    }

   if (SD.exists("diado.txt")) {
     
     
     myFilexc = SD.open("diado.txt", FILE_READ);
     char letra;
     
     int n = 0;
     while(myFilexc.available()and(n<50)){
      
      letra=myFilexc.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadedomingo[n]=letra;
      n++;
      
      
      }
      myFilexc.close();
      cadedomingo[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cadedomingo);
  }else{
    Serial.println("no hay diadomingo.txt");
        infiniti();
    
    
    }





   if (SD.exists("TEMBB.txt")) {
     
    
     myFilepopo = SD.open("TEMBB.txt", FILE_READ);
     Serial.println("temp listo");
     char letra;
     
     int n = 0;
     while(myFilepopo.available()and(n<50)){
      
      letra=myFilepopo.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadetemperatura[n]=letra;
      n++;
      
      
      }
      myFilepopo.close();
      cadetemperatura[50]='\0';
      //mandar a analizar la cadena
      analizarCadena(cadetemperatura);
      //Serial.println(cadetemperatura);
      //Serial.println(temperaturagg);
  }else{
    Serial.println("no hay temperaturab.txt");
        infiniti();
    
    }





    if (SD.exists("TEMBC.txt")) {
     
    
     myFilec = SD.open("TEMBC.txt", FILE_READ);
     Serial.println("tempc listo");   //ultmo mensaje visto
     char letra;
     
     int n = 0;
     while(myFilec.available()and(n<50)){
      
      letra=myFilec.read();
      
      //ponerlo en array de enteros, aunque esta en char
      cadetempec[n]=letra;
      n++;
     // Serial.println(n);   
      
      }
      myFilec.close();
      cadetempec[50]='\0';
      Serial.println("tempc todo leido y errado");   
      //mandar a analizar la cadena
      analizarCadena(cadetempec);
      Serial.println("volvi de variabilizar"); 
      
  }else{
    Serial.println("no hay temperaturabcc.txt");
        infiniti();
    
    }

    Serial.println("carga force finalizado"); 
    obtencionSD = 0;
    }












void infiniti(){
  Serial.println("interrumpido");
    lcd.init();
    lcd.backlight();
    lcd.clear();

  //escribir
   lcd.setCursor(0,0);
  lcd.print("Falla 01:");
  
  lcd.setCursor(0,1);
  lcd.print("SD no detectada");
  


  
  while(1){
    
    
    }

  
  }









void pregunta(){
  
  if(tempoBomba > 900){
    Serial.println(tempoBomba);
    actualizarBomba();
    tempoBomba=0;
    
    }else{
      
        tempoBomba++;
        delay(1);
      }
  
  
  }






int diaActivo(){
  
  DateTime now = rtc.now();
  int horaActual;
  int horaA;
  int horaB;
  int horaC;
  int horaD;
   //Dia actual en tres 0 a 6
  switch(now.dayOfWeek()){
    
    case 0:
            //utilizar hora militar
            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora1a[0] - 48)*1000 +((hora1a[1]-48) * 100    )+((hora1a[3]-48) * 10      )+((hora1a[4] -48)*1      );
            
            horaB = (hora1b[0] - 48)*1000 +((hora1b[1]-48) * 100    )+((hora1b[3]-48) * 10      )+((hora1b[4] -48)*1      );

            horaC = (hora1c[0] - 48)*1000 +((hora1c[1]-48) * 100    )+((hora1c[3]-48) * 10      )+((hora1c[4] -48)*1      );

            horaD = (hora1d[0] - 48)*1000 +((hora1d[1]-48) * 100    )+((hora1d[3]-48) * 10      )+((hora1d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            if((estado1 == 1)  and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual)    )){
              return 1;
              }else{
                return 0;
                }
            break;
    case 1:

            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora2a[0] - 48)*1000 +((hora2a[1]-48) * 100    )+((hora2a[3]-48) * 10      )+((hora2a[4] -48)*1      );
            
            horaB = (hora2b[0] - 48)*1000 +((hora2b[1]-48) * 100    )+((hora2b[3]-48) * 10      )+((hora2b[4] -48)*1      );

            horaC = (hora2c[0] - 48)*1000 +((hora2c[1]-48) * 100    )+((hora2c[3]-48) * 10      )+((hora2c[4] -48)*1      );

            horaD = (hora2d[0] - 48)*1000 +((hora2d[1]-48) * 100    )+((hora2d[3]-48) * 10      )+((hora2d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            
            if((estado2 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    case 2:

            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora3a[0] - 48)*1000 +((hora3a[1]-48) * 100    )+((hora3a[3]-48) * 10      )+((hora3a[4] -48)*1      );
            
            horaB = (hora3b[0] - 48)*1000 +((hora3b[1]-48) * 100    )+((hora3b[3]-48) * 10      )+((hora3b[4] -48)*1      );

            horaC = (hora3c[0] - 48)*1000 +((hora3c[1]-48) * 100    )+((hora3c[3]-48) * 10      )+((hora3c[4] -48)*1      );

            horaD = (hora3d[0] - 48)*1000 +((hora3d[1]-48) * 100    )+((hora3d[3]-48) * 10      )+((hora3d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
      
            if((estado3 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    case 3: 

            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora4a[0] - 48)*1000 +((hora4a[1]-48) * 100    )+((hora4a[3]-48) * 10      )+((hora4a[4] -48)*1      );
            
            horaB = (hora4b[0] - 48)*1000 +((hora4b[1]-48) * 100    )+((hora4b[3]-48) * 10      )+((hora4b[4] -48)*1      );

            horaC = (hora4c[0] - 48)*1000 +((hora4c[1]-48) * 100    )+((hora4c[3]-48) * 10      )+((hora4c[4] -48)*1      );

            horaD = (hora4d[0] - 48)*1000 +((hora4d[1]-48) * 100    )+((hora4d[3]-48) * 10      )+((hora4d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            
            if((estado4 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    case 4: 
            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora5a[0] - 48)*1000 +((hora5a[1]-48) * 100    )+((hora5a[3]-48) * 10      )+((hora5a[4] -48)*1      );
            
            horaB = (hora5b[0] - 48)*1000 +((hora5b[1]-48) * 100    )+((hora5b[3]-48) * 10      )+((hora5b[4] -48)*1      );

            horaC = (hora5c[0] - 48)*1000 +((hora5c[1]-48) * 100    )+((hora5c[3]-48) * 10      )+((hora5c[4] -48)*1      );

            horaD = (hora5d[0] - 48)*1000 +((hora5d[1]-48) * 100    )+((hora5d[3]-48) * 10      )+((hora5d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            
            if((estado5 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    case 5:
            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora6a[0] - 48)*1000 +((hora6a[1]-48) * 100    )+((hora6a[3]-48) * 10      )+((hora6a[4] -48)*1      );
            
            horaB = (hora6b[0] - 48)*1000 +((hora6b[1]-48) * 100    )+((hora6b[3]-48) * 10      )+((hora6b[4] -48)*1      );

            horaC = (hora6c[0] - 48)*1000 +((hora6c[1]-48) * 100    )+((hora6c[3]-48) * 10      )+((hora6c[4] -48)*1      );

            horaD = (hora6d[0] - 48)*1000 +((hora6d[1]-48) * 100    )+((hora6d[3]-48) * 10      )+((hora6d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            
            if((estado6 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    case 6: 
            horaActual = (now.hour())*100;
            horaActual = horaActual + (now.minute());

            horaA = (hora7a[0] - 48)*1000 +((hora7a[1]-48) * 100    )+((hora7a[3]-48) * 10      )+((hora7a[4] -48)*1      );
            
            horaB = (hora7b[0] - 48)*1000 +((hora7b[1]-48) * 100    )+((hora7b[3]-48) * 10      )+((hora7b[4] -48)*1      );

            horaC = (hora7c[0] - 48)*1000 +((hora7c[1]-48) * 100    )+((hora7c[3]-48) * 10      )+((hora7c[4] -48)*1      );

            horaD = (hora7d[0] - 48)*1000 +((hora7d[1]-48) * 100    )+((hora7d[3]-48) * 10      )+((hora7d[4] -48)*1      );
            Serial.println(horaActual);
            Serial.println(horaA);
            Serial.println(horaB);
            Serial.println(horaC);
            Serial.println(horaD);
            
            if((estado7 == 1)and(  (horaA < horaActual and horaB > horaActual)   or   (horaC < horaActual and horaD > horaActual) )){
              return 1;}else{return 0;}
            break;
    default: break;
    

    
    }
  
 
  
  return 0;
  
  }
















void directorios(){


                            root = SD.open("/");

                            printDirectory(root, 0);
                          
                            Serial.println("done!"); 
}






  void printDirectory(File dir, int numTabs) {    // codigo sacado de ejemplo sobre lectura de sd, ni puda idea de como funciona.
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    
    
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    
    entry.close();
  }
}










void compruebaExistencia(){
  
  
  if(SD.exists("index.htm")){Serial.print("index bien");}else{Serial.print("index no encontrado");}
  if(SD.exists("page2.htm")){Serial.print("page2 bien");}else{Serial.print("page2 no encontrado");}
  if(SD.exists("page3.htm")){Serial.print("page3 bien");}else{Serial.print("page3 no encontrado");}
  if(SD.exists("TEMBB.txt")){Serial.print("TEMBB bien");}else{Serial.print("TEMBB no encontrado");}
  if(SD.exists("TEMBC.txt")){Serial.print("TEMBC bien");}else{Serial.print("TEMBC no encontrado");}
  if(SD.exists("DIAVI.txt")){Serial.print("DIAVI bien");}else{Serial.print("DIAVI no encontrado");}
  if(SD.exists("DIASA.txt")){Serial.print("DIASA bien");}else{Serial.print("DIASA no encontrado");}
  if(SD.exists("DIAMI.txt")){Serial.print("DIAMI bien");}else{Serial.print("DIAMI no encontrado");}
  if(SD.exists("DIAMA.txt")){Serial.print("DIAMA bien");}else{Serial.print("DIAMA no encontrado");}
  if(SD.exists("DIALU.txt")){Serial.print("DIALU bien");}else{Serial.print("DIALU no encontrado");}
  if(SD.exists("DIAJU.txt")){Serial.print("DIAJU bien");}else{Serial.print("DIAJU no encontrado");}
  if(SD.exists("DIAES.txt")){Serial.print("DIAES bien");}else{Serial.print("DIAES no encontrado");}
  if(SD.exists("DIADO.txt")){Serial.print("DIADO bien");}else{Serial.print("DIADO no encontrado");}
  if(SD.exists("CUALQ.txt")){Serial.print("CUALQ bien");}else{Serial.print("CUALQ no encontrado");}
  if(SD.exists("CONFI.txt")){Serial.print("CONFI bien");}else{Serial.print("CONFI no encontrado");}
  
  /*int todobien = 777;

  if(SD.exists("index.htm")){
    
    }else{todobien = 666;}
  if(SD.exists("page2.htm")){
    
    }else{todobien = 666;}
  if(SD.exists("page3.htm")){
    
    }else{todobien = 666;}
  if(SD.exists("TEMBB.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("TEMBC.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIAVI.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIASA.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIAMI.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIAMA.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIALU.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIAJU.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIAES.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("DIADO.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("CUALQ.txt")){
    
    }else{todobien = 666;}
  if(SD.exists("CONFI.txt")){
    
    }else{todobien = 666;}



  
  if(todobien == 777){
    Serial.println("b");
    }else{
        Serial.println("mal");
      }*/
  
  
  
  }

















void ejecucionClase(int numClase){
  
  switch(numClase){
    
    
    case 20: 
            //llamar a la clase pasando variables.
            //estadoCalendario invierno(20 , 40,80,1515,6300,5151,52);
            break;
    case 35: 
            //estadoCalendario verano(20 , 40,80,1515,6300,5151,52);
            break;
    case 43: 
            //estadoCalendario defecto(20 , 40,80,1515,6300,5151,52);
            break;
    default: break;
    
    
    
    
    
    
    
    
    }
 
  
  }


//funcion, devuelve si el horario actual esta en
//un horario en que puede se activado (entre 8am a 21pm)
//de ser asi, devuelve true.
//si el horario no esta entre ese horario, retorna false.
boolean diaBonito(){
  
  
  DateTime now = rtc.now();
  if((now.hour()>8) and(now.hour()<21)){
    return true;
    }
  

  return false;
  }




boolean hayLimite(){
  //tomar hora actual
  DateTime now = rtc.now();
  long horaAhora = (now.hour())*10000;
  horaAhora = horaAhora + (now.minute()*100);
  horaAhora = horaAhora + (now.second());

            
  long diferencia = horaAhora - horaCompleta;

  if(diferencia > 60){
        horaCompleta = horaAhora;
        //poner hora actual como variable
        return true;
    }
  

  return false;
  }
  

