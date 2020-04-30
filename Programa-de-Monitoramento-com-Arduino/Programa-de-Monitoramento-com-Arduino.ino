/*Programa baseado neste link https://www.smtp2go.com/setupguide/arduino/, para um uso específico
*Programa finalizado em 11/2017
*Criadores: Luis Felipe de Sousa Garcia, https://www.linkedin.com/in/luis-felipe-de-sousa-garcia-6922aa170/
*   "     : João Vitor Macedo do Prado, https://www.linkedin.com/in/jo%C3%A3o-vitor-macedo-do-prado-93a6411a7/
*/


#include <SPI.h>
#include <Ethernet.h>

#define pinoreset A4
#define bmanutencao  A0
#define bcompras  A1
#define bferramentas  A2
#define balmoxarifado  A3
#define ledmanutencao A5 
#define ledcompras  6
#define ledferramentas  8
#define ledalmoxarifado  2


#define user "xxxx" // Email códificado em base64
#define senha "xxxx" // Senha códificada em base64

#define ehlo "EHLO 189.120.253.114"


/* A partir daqui os emails teram o seguinte padrão:
 *  To: xxxx(Nome do destinatário) <email(usei um gmail)>
 *  From: xxxx xxxx(Nome do Remetente) <email(usei um bol)>
 *  Fica necessário a pesquisa para saber quais serviços de email
 *  liberam o uso de SMTP.
 *  Usei um email para cada problema pois cada departamento teria um email
 *  diferente
*/
#define mailfromalmoxarifadoresolvido "MAIL From: <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens
#define rcpttoalmoxarifadoresolvido "RCPT To: <xxxx.lfsg@gmail.com>" // Email receptor
#define toalmoxarifadoresolvido "To: xxxx <xxxx.lfsg@gmail.com>"  // Email receptor
#define fromalmoxarifadoresolvido "From: xxxx xxxx <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens

#define mailfromalmoxarifado "MAIL From: <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens
#define rcpttoalmoxarifado "RCPT To: <xxxx.lfsg@gmail.com>" // Email receptor
#define toalmoxarifado "To: xxxx <xxxx.lfsg@gmail.com>" // Email receptor
#define fromalmoxarifado "From: xxxx xxxx <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens

#define mailfrommanutencao "MAIL From: <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens
#define rcpttomanutencao "RCPT To: <xxxx.lfsg@gmail.com>" // Email receptor
#define tomanutencao "To: xxxx <xxxx.lfsg@gmail.com>" // Email receptor
#define frommanutencao "From: xxxx xxxx <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens

#define mailfrommanutencaoresolvido "MAIL From: <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens
#define rcpttomanutencaoresolvido "RCPT To: <xxxx.lfsg@gmail.com>"  // Email receptor
#define tomanutencaoresolvido "To: xxxx <xxxx.lfsg@gmail.com>"  // Email receptor
#define frommanutencaoresolvido "From: xxxx xxxx <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens


#define mailfromferramentas "MAIL From: <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens
#define rcpttoferramentas "RCPT To: <xxxx.lfsg@gmail.com>"  // Email receptor
#define toferramentas "To: xxxx <xxxx.lfsg@gmail.com>"  // Email receptor
#define fromferramentas "From: xxxx xxxx <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens

#define mailfromferramentasresolvido "MAIL From: <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens
#define rcpttoferramentasresolvido "RCPT To: <xxxx.lfsg@gmail.com>" // Email receptor
#define toferramentasresolvido "To: xxxx <xxxx.lfsg@gmail.com>" // Email receptor
#define fromferramentasresolvido "From: xxxx xxxx <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens


#define mailfromcompras "MAIL From: <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens
#define rcpttocompras "RCPT To: <xxxx.lfsg@gmail.com>"  // Email receptor
#define tocompras "To: xxxx <xxxx.lfsg@gmail.com>"  // Email receptor
#define fromcompras "From: xxxx xxxx <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens

#define mailfromcomprasresolvido "MAIL From: <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens
#define rcpttocomprasresolvido "RCPT To: <xxxx.lfsg@gmail.com>" // Email receptor
#define tocomprasresolvido "To: xxxx <xxxx.lfsg@gmail.com>" // Email receptor
#define fromcomprasresolvido "From: xxxx xxxx <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens

#define mailfromrelatorio "MAIL From: <xxxx.lfsg@bol.com.br>" // Email Que enviara as mensagens
#define rcpttorelatorio "RCPT To: <xxxx.lfsg@gmail.com>"  // Email receptor
#define torelatorio "To: xxxx <xxxx.lfsg@gmail.com>"  // Email receptor
#define fromrelatorio "From: xxxx xxxx <xxxx.lfsg@bol.com.br>"  // Email Que enviara as mensagens

// Tem que ser único para esse dispositivo
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x59, 0x67 }; 
// Mude para as suas conexões
IPAddress ip( 192, 168, 0, 104 ); 
IPAddress gateway( 192, 168, 0, 9 );
IPAddress subnet( 255, 255, 255, 0 );
char server[] = "mail.smtp2go.com"; 
int port = 2525; // Pode também testar as Port Number 25, 8025 or 587.
EthernetClient client;
double msmanutencao =0;
long smanutencao=0;
int mmanutencao=0;
int hmanutencao=0;
int dmanutencao=0;
int smmanutencao=0;
double mscompras =0;
long scompras=0;
int mcompras=0;
int hcompras=0;
int dcompras=0;
int smcompras=0;
double msferramentas =0;
long sferramentas=0;
int mferramentas=0;
int hferramentas=0;
int dferramentas=0;
int smferramentas=0;
double msalmoxarifado =0;
long salmoxarifado=0;
int malmoxarifado=0;
int halmoxarifado=0;
int dalmoxarifado=0;
int smalmoxarifado=0;
int tmsmanutencao =0;
int tsmanutencao=0;
int tmmanutencao=0;
int thmanutencao=0;
int tdmanutencao=0;
int tsmmanutencao=0;
int tmscompras =0;
int tscompras=0;
int tmcompras=0;
int thcompras=0;
int tdcompras=0;
int tsmcompras=0;
int tmsferramentas =0;
int tsferramentas=0;
int tmferramentas=0;
int thferramentas=0;
int tdferramentas=0;
int tsmferramentas=0;
int tmsalmoxarifado =0;
int tsalmoxarifado=0;
int tmalmoxarifado=0;
int thalmoxarifado=0;
int tdalmoxarifado=0;
int tsmalmoxarifado=0;
double Tmanutencao = 0;
double Tcompras = 0;
double Tferramentas = 0;
double Talmoxarifado = 0;
double Timanutencao = 0;
double Ticompras = 0;
double Tiferramentas = 0;
double Tialmoxarifado = 0;
double Tfmanutencao = 0;
double Tfcompras = 0;
double Tfferramentas = 0;
double Tfalmoxarifado = 0;
int manutencao = 0;
int compras = 0;
int ferramentas = 0; 
int almoxarifado = 0;
double tempomaximo =0;

void setup()
{
Serial.begin(115200);
Ethernet.begin(mac);
delay(2000);
Serial.println(Ethernet.localIP());
  pinMode(bmanutencao, INPUT_PULLUP);
  pinMode(bcompras, INPUT_PULLUP);
  pinMode(bferramentas, INPUT_PULLUP);
  pinMode(balmoxarifado, INPUT_PULLUP);
  pinMode(ledmanutencao, OUTPUT);
  pinMode(ledcompras, OUTPUT);
  pinMode(ledferramentas, OUTPUT);
  pinMode(ledalmoxarifado, OUTPUT);
  Serial.println(F("pode comecar"));
}

void loop()
{
if((digitalRead(bmanutencao)== HIGH) && (manutencao==0))      //Inicia o Problema do Setor de Manutenção
  {
    manutencao=1;      
    digitalWrite(ledmanutencao, 1);
    Serial.println(F("começando a enviar o e-mail"));
    Serial.println(F("conectando..."));
   //comeco do email
    if(sendEmailManutencao()) Serial.println(F("Email sent"));
    else Serial.println(F("Email failed"));
   //Termino do Email

    Timanutencao = millis();
    delay(1000);
 
  }
  if((digitalRead(bmanutencao)== HIGH) && (manutencao==1))      //Consertado o Problema do Setor de Manutenção
  {
    manutencao=0;
    digitalWrite(ledmanutencao, 0);
    Tmanutencao = millis();
    msmanutencao = (Tmanutencao - Timanutencao); 
    while(msmanutencao>=1000)
    {
      msmanutencao = msmanutencao-1000;
      smanutencao++;
    }
    while(smanutencao>=60)
    {
      smanutencao = smanutencao - 60;
      mmanutencao++;
    }
    while(mmanutencao>=60)
    {
      mmanutencao = mmanutencao - 60;
      hmanutencao++;
    }
    while(hmanutencao>=24)
    {
      hmanutencao = hmanutencao - 24;
      dmanutencao++;
    }
    while(dmanutencao>=7)
    {
      dmanutencao = dmanutencao -7;
      smmanutencao++;
    }
    
    Serial.println(F("problema na manutencao resolvido em:   "));
    Serial.print(smmanutencao);
    Serial.print(F("semanas,"));
    Serial.print(dmanutencao);
    Serial.print(F("dias,"));
    Serial.print(hmanutencao);
    Serial.print(F("horas,"));
    Serial.print(mmanutencao);
    Serial.print(F("minutos,"));
    Serial.print(smanutencao);
    Serial.print(F("segundos"));
    Serial.println(F("agradecemos a preferencia, conte sempre com #Pombo&PatoPRPGRAMAS, agr vamos enviar um e-mail"));
    Serial.println(F("conectando..."));
 //comeco do email
    if(sendEmailManutencaoResolvido()) Serial.println(F("Email sent"));
    else Serial.println(F("Email failed"));
   //Termino do Email




    tmsmanutencao = tmsmanutencao+msmanutencao;
    tsmanutencao=  tsmanutencao+smanutencao;
    tmmanutencao= tmmanutencao+mmanutencao;
    thmanutencao= thmanutencao+hmanutencao;
    tdmanutencao= tdmanutencao+dmanutencao;
    tsmmanutencao= tsmmanutencao+smmanutencao;
    
    delay(1000);  
    smmanutencao=0;
    dmanutencao=0;
    hmanutencao=0;
    smanutencao=0;
    msmanutencao=0;
  

  }
  
if((digitalRead(bcompras)== HIGH) && (compras==0))             //Inicia o Problema do Setor de Compras
  {
    compras=1;      
    digitalWrite(ledcompras, 1);
    Serial.println(F("problema no setor de compras, enviando e-mail"));
    if(sendEmailCompras()) Serial.println(F("Email sent"));
    else Serial.println(F("Email failed"));
    Ticompras = millis();
    delay(1000);
  
  
  }
  if((digitalRead(bcompras)== HIGH) && (compras==1))          //Consertado o Problema do Setor de Compras
  {
    compras=0;
    digitalWrite(ledcompras, 0);
    Tcompras = millis();
    mscompras = (Tcompras - Ticompras);
    while(mscompras>=1000)
    {
      mscompras = mscompras-1000;
      scompras++;
    }
    while(scompras>=60)
    {
      scompras = scompras - 60;
      mcompras++;
    }
    while(mcompras>=60)
    {
      mcompras = mcompras - 60;
      hcompras++;
    }
    while(hcompras>=24)
    {
      hcompras = hcompras - 24;
      dcompras++;
    }
    while(dcompras>=7)
    {
      dcompras = dcompras -7;
      smcompras++;
    }
    
    Serial.println(F("problema no setor de compras resolvido em:   "));
    Serial.print(smcompras);
    Serial.print(F("semanas,"));
    Serial.print(dcompras);
    Serial.print(F("dias,"));
    Serial.print(hcompras);
    Serial.print(F("horas,"));
    Serial.print(mcompras);
    Serial.print(F("minutos,"));
    Serial.print(scompras);
    Serial.print(F("segundos"));
    Serial.println(F("agradecemos a prefer�ncia, conte sempre com #Pombo&PatoPRPGRAMAS, vamos enviar o e-mail..."));

    //comeco do email
  if(sendEmailComprasResolvido()) Serial.println(F("Email sent"));
  else Serial.println(F("Email failed"));
   //Termino do Email


    
    tmscompras = tmscompras +mscompras;
    tscompras= tscompras +scompras;
    tmcompras= tmcompras+ mcompras;
    thcompras= thcompras +hcompras;
    tdcompras= tdcompras +dcompras;
    tsmcompras= tsmcompras +smcompras;
    
    
    delay(1000); 
    
    smcompras=0;
    dcompras=0;
    hcompras=0;
    mcompras=0;
    scompras=0;
    mscompras=0;
    
  }

  if((digitalRead(bferramentas)== HIGH) && (ferramentas==0)) //Inicia o Problema do Setor de Ferramentas
  {
    ferramentas=1;      
    digitalWrite(ledferramentas, 1);
    Serial.println(F("problemas no setor de ferramentas"));
     Tiferramentas = millis();
    delay(1000);
    //Comeco do Email
    
    //comeco do email
    if(sendEmailFerramentas()) Serial.println(F("Email sent"));
    else Serial.println(F("Email failed"));
   //Termino do Email
  
  
  
  }
  if((digitalRead(bferramentas)== HIGH) && (ferramentas==1)) //Consertado o Problema do Setor de Ferramentas
  {
    ferramentas=0;
    digitalWrite(ledferramentas, 0);
    Tferramentas = millis();
    msferramentas = (Tferramentas - Tiferramentas);
    
    while(msferramentas>=1000)
    {
      msferramentas = msferramentas-1000;
      sferramentas++;
    }
    while(sferramentas>=60)
    {
      sferramentas = sferramentas - 60;
      mferramentas++;
    }
    while(mferramentas>=60)
    {
      mferramentas = mferramentas - 60;
      hferramentas++;
    }
    while(hferramentas>=24)
    {
      hferramentas = hferramentas - 24;
      dferramentas++;
    }
    while(dferramentas>=7)
    {
      dferramentas = dferramentas -7;
      smferramentas++;
    }
    
    Serial.println(F("problema no setor de ferramentas resolvido em:   "));
    Serial.print(smferramentas);
    Serial.print(F("semanas,"));
    Serial.print(dferramentas);
    Serial.print(F("dias,"));
    Serial.print(hferramentas);
    Serial.print(F("horas,"));
    Serial.print(mferramentas);
    Serial.print(F("minutos,"));
    Serial.print(sferramentas);
    Serial.print(F("segundos"));
    Serial.println(F("agradecemos a prefer�ncia, conte sempre com #Pombo&PatoPRPGRAMAS"));
    tmsferramentas= tmsferramentas+ msferramentas;
    tsferramentas= tsferramentas +sferramentas;
    tmferramentas= tmferramentas +mferramentas;
    thferramentas= thferramentas + hferramentas;
    tdferramentas= tdferramentas +dferramentas;
    tsmferramentas= tsmferramentas +smferramentas;
    
   //comeco do email
    if(sendEmailFerramentasResolvido()) Serial.println(F("Email sent"));
    else Serial.println(F("Email failed"));
   //Termino do Email

    
    smferramentas=0;
    dferramentas=0;
    hferramentas=0;
    mferramentas=0;
    sferramentas=0;
    msferramentas=0;
    
  
  }

  if((digitalRead(balmoxarifado)== HIGH) && (almoxarifado==0)) //Inicia o Problema do Setor de Almoxarifado
  {
    almoxarifado=1;      
    digitalWrite(ledalmoxarifado, 1);
    Serial.println(F("problemas no setor de almoxarifado"));
    Tialmoxarifado = millis();
    delay(500);
    //comeco do email
  if(sendEmailAlmoxarifado()) Serial.println(F("Email sent"));
  else Serial.println(F("Email failed"));
   //Termino do Email
  
  
  }
  
  if((digitalRead(balmoxarifado)== HIGH) && (almoxarifado==1)) //Consertado o Problema do Setor de Almoxarifado
  {
    almoxarifado=0;
    digitalWrite(ledalmoxarifado, 0);
    Talmoxarifado = millis();
    msalmoxarifado = (Talmoxarifado - Tialmoxarifado);
    
    while(msalmoxarifado>=1000)
    {
      msalmoxarifado = msalmoxarifado-1000;
      salmoxarifado++;
    }
    while(salmoxarifado>=60)
    {
      salmoxarifado = salmoxarifado - 60;
      malmoxarifado++;
    }
    while(malmoxarifado>=60)
    {
      malmoxarifado = malmoxarifado - 60;
      halmoxarifado++;
    }
    while(halmoxarifado>=24)
    {
      halmoxarifado = halmoxarifado - 24;
      dalmoxarifado++;
    }
    while(dalmoxarifado>=7)
    {
      dalmoxarifado = dalmoxarifado -7;
      smalmoxarifado++;
    }
    
    Serial.println(F("problema no setor de almoxarifado resolvido em:   "));
    Serial.print(smalmoxarifado);
    Serial.print(F("semanas,"));
    Serial.print(dalmoxarifado);
    Serial.print(F("dias,"));
    Serial.print(halmoxarifado);
    Serial.print(F("horas,"));
    Serial.print(malmoxarifado);
    Serial.print(F("minutos,"));
    Serial.print(salmoxarifado);
    Serial.print(F("segundos"));
    Serial.println(F("agradecemos a prefer�ncia, conte sempre com #Pombo&PatoPRPGRAMAS"));

       //comeco do email
      if(sendEmailAlmoxarifadoResolvido()) Serial.println(F("Email sent"));
else Serial.println(F("Email failed"));
   //Termino do Email

    
    tmsalmoxarifado = tmsalmoxarifado+ msalmoxarifado;
    tsalmoxarifado= tsalmoxarifado +salmoxarifado;
    tmalmoxarifado= tmalmoxarifado +malmoxarifado;
    thalmoxarifado= thalmoxarifado +halmoxarifado;
    tdalmoxarifado= tdalmoxarifado +dalmoxarifado;
    tsmalmoxarifado= tsmalmoxarifado +smalmoxarifado;
    
    delay(1000);   
    
    smalmoxarifado=0;
    dalmoxarifado=0;
    halmoxarifado=0;
    malmoxarifado=0;
    salmoxarifado=0;
    msalmoxarifado=0;


  }
  tempomaximo = millis();
  if(tempomaximo >= 2592000000)
  {
    byte sendEmailrelatorio();
    Serial.print(F("reset nesessario"));
    digitalWrite(pinoreset,HIGH);
    
  }
    
  }
  


//Email Manutencao
byte sendEmailManutencao()
{
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfrommanutencao));
Serial.println(F("Sending To"));
client.println(F(rcpttomanutencao));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(tomanutencao));
client.println(F(frommanutencao));
client.println(F("Subject: Problema no Setor de Manutencao")); 
client.println(F("Problema no Setor de Manutencao"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}




//Email Manutencao Resolvido
byte sendEmailManutencaoResolvido()
{    
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfrommanutencaoresolvido));
Serial.println(F("Sending To"));
client.println(F(rcpttomanutencaoresolvido));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(tomanutencaoresolvido));
client.println(F("From: xxxx xxxx <xxxx.lfsg@bol.com.br>"));
client.println(F("Subject: Problema resilvido - manitenção")); 
client.println(F("Problema no Setor de Manuntencao resolvido em : "));
client.println(smmanutencao);
client.println(F("semanas,"));
client.println(dmanutencao);
client.println(F("dias,"));
client.println(hmanutencao);
client.println(F("horas,"));
client.println(mmanutencao);
client.println(F("minutos,"));
client.println(smanutencao);
client.println(F("segundos"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}


//Email Compras
byte sendEmailCompras()
{  
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromcompras));
Serial.println(F("Sending To"));
client.println(F(rcpttocompras));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(tocompras));
client.println(F(fromcompras));
client.println(F("Subject: Problema no Setor de Compras")); 
client.println(F("Problema no Setor de Compras"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}


//Email Compras Resolvido
byte sendEmailComprasResolvido()
  {
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(ehlo);
Serial.println(F("Sending auth login"));
client.println("auth login");
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromcomprasresolvido));
Serial.println(F("Sending To"));
client.println(F(rcpttocomprasresolvido));
Serial.println(F("Sending DATA"));
client.println("DATA");
Serial.println(F("Sending email"));
client.println(F(tocomprasresolvido));
client.println(F(fromcomprasresolvido));
client.println("Subject: problema resolvido - compras"); 
client.println("Problema no Setor de Compras resolvido em : ");
client.println(smcompras);
client.println(F("semanas,"));
client.println(dcompras);
client.println(F("dias,"));
client.println(hcompras);
client.println(F("horas,"));
client.println(mcompras);
client.println(F("minutos,"));
client.println(scompras);
client.println(F("segundos"));
client.println(".");
Serial.println(F("Sending QUIT"));
client.println("QUIT");
client.stop();
Serial.println(F("disconnected"));
return 1;
  }


//Email Ferramentas
byte sendEmailFerramentas()
{
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromferramentas));
Serial.println(F("Sending To"));
client.println(F(rcpttoferramentas));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(toferramentas));
client.println(F(fromferramentas));
client.println(F("Subject: Problema no Setor de Ferramentas")); 
client.println(F("Problema no Setor de Ferramentas"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}


//Email Ferramentas Resolvido
byte sendEmailFerramentasResolvido()
{   
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromferramentasresolvido));
Serial.println(F("Sending To"));
client.println(F(rcpttoferramentasresolvido));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(toferramentasresolvido));
client.println(F(fromferramentasresolvido));
client.println(F("Subject: probema resolvido - ferramentas")); 
client.println(F("Problema no Setor de Ferramentas resolvido em : "));
client.println(smferramentas);
client.println(F("semanas,"));
client.println(dferramentas);
client.println(F("dias,"));
client.println(hferramentas);
client.println(F("horas,"));
client.println(mferramentas);
client.println(F("minutos,"));
client.println(sferramentas);
client.println(F("segundos"));
client.println(".");
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}



//Email Almoxarifado
byte sendEmailAlmoxarifado()
{
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromalmoxarifado));
Serial.println(F("Sending To"));
client.println(F(rcpttoalmoxarifado));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(toalmoxarifado));
client.println(F(fromalmoxarifado));
client.println(F("Subject: Problema no Setor de Almoxarifado")); 
client.println(F("Problema no Setor de Almoxarifado"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}




//Email Almoxarifado Resolvido
byte sendEmailAlmoxarifadoResolvido()
      {
byte thisByte = 0;
byte respCode;
if(client.connect(server,port) == 1) {
Serial.println(F("connected"));
} else {
Serial.println(F("connection failed"));
return 0;
}
Serial.println(F("Sending hello"));
client.println(F(ehlo));
Serial.println(F("Sending auth login"));
client.println(F("auth login"));
Serial.println(F("Sending User"));
client.println(F(user)); 
Serial.println(F("Sending Password"));
client.println(F(senha)); 
Serial.println(F("Sending From"));
client.println(F(mailfromalmoxarifadoresolvido));
Serial.println(F("Sending To"));
client.println(F(rcpttoalmoxarifadoresolvido));
Serial.println(F("Sending DATA"));
client.println(F("DATA"));
Serial.println(F("Sending email"));
client.println(F(toalmoxarifadoresolvido));
client.println(F(fromalmoxarifadoresolvido));
client.println(F("Subject: problema resolvido - almoxarifado")); 
client.println(F("Problema no Setor do Almoxarifado resolvido em : "));
client.println(smalmoxarifado);
client.println(F("semanas,"));
client.println(dalmoxarifado);
client.println(F("dias,"));
client.println(halmoxarifado);
client.println(F("horas,"));
client.println(malmoxarifado);
client.println(F("minutos,"));
client.println(salmoxarifado);
client.println(F("segundos"));
client.println(F("."));
Serial.println(F("Sending QUIT"));
client.println(F("QUIT"));
client.stop();
Serial.println(F("disconnected"));
return 1;
}
