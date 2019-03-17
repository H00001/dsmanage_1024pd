`     this is a protocl of network control
      the stand is this:

     +--------+----------------+--------+--------------------+--------------+
     | cli id |   message id   |  code  |       option       |   message    |
     +--------+----------------+--------+--------------------+--------------+
     |<- 1B ->|<-     2B     ->|<- 1B ->|<-       4B       ->|<-   1024B  ->|

   client id :client id ,every host has an unique id .             
              it was calculatored by mac address and unix     ===      ===|==|
              time.                                            \\  ==  // |  |
   message id:it was created by server. the server #######      \\//\\//  |==
              send the message id .when the client resonse      1 00  2 44
              the control message ,use the same message id      1 00  2 44
              to response to the server.
   code      :message type
              the message is defined follow:
                +-----+---+---------------+---+------------------+
   message type |  0  | 0 |response       | 1 |request           |
                +-----+---+---------------+---+------------------+
   exec type    |  1  | 0 |               | 1 |shell             |
                +-----+---+---------------+---+------------------+
                |  2  | 0 |               | 1 |is alive          |
                +-----+---+---------------+---+------------------+
                |  3  | 0 |               | 1 |                  |
                +-----+---+---------------+---+------------------+
   result       |  4  | 0 |succeed        | 1 |fail              |
                +-----+---+---------------+---+------------------+
   error type   |  5  | 0 |               | 1 |                  |
                +-----+---+---------------+---+------------------+
                |  6  | 0 |               | 1 |cmd error         |
                +-----+---+---------------+---+------------------+
   alive status |  7  | 0 |i am alive     | 1 |has been shutdown |
                +-----+---+---------------+---+------------------+

   the alive and dead pdu all has no message id.this is the only
   distinction with a,d pdu or other pdu.
    
   option    :

   message   :message if the pdu is a request pdu, it is the shell 
              command or other.if the pdu is the resonse pdu ,it is
              the result string.
    copyright 2015-2017 dosdrtt Co,. Ltd user:albert commuinsm           
  ===================================END======================================
   public key:
   MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDFVJ33T8wAHGgjVa2WILNjHthG5nSZzbP+jC
   PeRlcwauGdjzsGVZgrgOb8+oSzh3d+xX14T9wRagPSYc/lkwdjNz7Qwj1U76AnAUmR5Jzi7Tlr
   80EUS6///Z+AGPMR2s2vQYaQU/yEIKE/otJzyG/+0OgsSv7zmOk4K0xsWuUwvwIDAQAB

   base64:
   d2h5IGRpZCBpIEkgdXNlIDEwMjQ/CkJlY2F1c2UgdGhlIDEwMjQgaXMgbXkgd29yc3QgZGF5LA
   ppbiB0aGlzIGRheSBteSBnaXJsIGZyaWVuZCBtYWtlIG1lIGRpdmlkZSBoYW5kCkJ1dCBJIGxv
   dmUgaGVyIGFuZCBJIGNhbiBub3QgZ2V0IHRvIGxheSBkb3duLgpIb3cgZXZlciAsc2hlIGhhcy
   Bsb3ZlIG1lIGFuZCBnb3JnZXQgbWUgZXZlbiB0aG91Z2guCkFzIHRoZSByZWFzb24gb2Ygd2Ug
   ZGl2aWRlIHRoZSBoYW5kICAsaXQgaXMgY29tcGxleC4KaWYgeW91IGNhbiBtZWV0IGhlciAscG
   xlYXNlIHlvdSB0ZWxsIGhlciBJIGxvdmUgaGVyIHN0aWxsLgp0aW1lOjE1NDM2Njg1MjY=
   http://gunplan.top   
