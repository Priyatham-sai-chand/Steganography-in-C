# Steganography-in-C

Steganography is the practice of concealing messages or information within other non-secret text or data. 
For more info on the process,
[Wikipedia](https://en.wikipedia.org/wiki/Steganography)

This is my ongoing project to hide messages using a C project and in later stages be able to integrate it to provide a GUI for ease of operation.

Encrytion would require the use of [openssl](https://www.openssl.org/)
## To Compile

```gcc steg.c encode.c -o steg```

with encryption

```gcc -lssl -lcrypto steg.c encode.c encryption.c -o steg```
