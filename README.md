# Steganography-in-C

![steg](https://media.wired.com/photos/594db1717c1bde11fe06f341/master/w_2560%2Cc_limit/hidden_data-01.png)

![GitHub language count](https://img.shields.io/github/languages/count/Priyatham-sai-chand/Steganography-in-C?style=for-the-badge)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/Priyatham-sai-chand/Steganography-in-C?style=for-the-badge)
![GitHub](https://img.shields.io/github/license/Priyatham-sai-chand/Steganography-in-C?style=for-the-badge)
![GitHub last commit](https://img.shields.io/github/last-commit/Priyatham-sai-chand/Steganography-in-C?style=for-the-badge)

Steganography is the practice of concealing messages or information within other non-secret text or data. 
For more info on the process,
[Wikipedia](https://en.wikipedia.org/wiki/Steganography)

This is my ongoing project to hide messages using a C project and in later stages be able to integrate it to provide a GUI for ease of operation. it currently operates on PPM files which will be later updated to JPEG.

Encrytion would require the use of [openssl](https://www.openssl.org/)
## To Compile

```gcc steg.c encode.c -o steg```

with encryption

```gcc -lssl -lcrypto steg.c encode.c encryption.c -o steg```
