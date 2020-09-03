# Steganography-in-C

Steganography is the practice of concealing messages or information within other non-secret text or data. 
For more info on the process,
[Wikipedia](https://en.wikipedia.org/wiki/Steganography)

This is my ongoing project to hide messages using a C project and in later stages be able to integrate it to provide a GUI for ease of operation.

## To Compile

```gcc steg -o steg.c encode.c```

with encryption

```gcc steg -o  steg.c encode.c encryption.c -lssl -lcrypto```
