#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<math.h>

#define PPM1 'P'
#define PPM2 '3'
#define PPM_FORMAT (PPM1 * 255 + PPM2)
#define PPM_TYPE PPM_FORMAT

#define PPM_MAXVAL 255
#define PPM_MAXMESS 100 //defines max for encoding and decoding
#define BMAX 100 //defines max for buffer

/* Typedef struct holds integer rgb values within type identifier pixel */
typedef struct pixel{
	int r, g, b;
} pixel;

/* text struct holds strings of comments using LLDS */
typedef struct comment {
	char comment[BMAX];
	struct comment * next;
}comment;
struct conv 
{
    int bin[8];
    
};
/* PART A - Struct created to hold PPM Images(Uses a 2D array for rows and cols) */
struct PPM {

	char * type;
	struct comment * comment;
	int cn;
	int width, height, max; //Width, height and max size
	struct pixel ** p;

};


/* Declaration of functions. Implementations made in ppmfun.c */

char * readLine(FILE * fin);

void showPPM(struct PPM * i);

void getText(FILE * fin, struct PPM * i);

void getPixels(FILE * fin, struct PPM * i);

struct PPM * getPPM(FILE * fin);

struct PPM * encoder(struct PPM * img, char * message,unsigned int secret,int n);

struct conv * dec2bind(int num);

int bind2dec(struct conv * obj);

void writePPM(FILE * fin ,struct PPM * i, const char *fileName);

char * decode(struct PPM * img, unsigned int secret,int n,int mSize);

void encodeFile(int argc, char ** argv);

void decodeFile(int argc, char  ** argv);
char * encrypter(char * plaintext);

char * decrypter(char * ciphertext);

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,unsigned char *iv, unsigned char *ciphertext);

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,unsigned char *iv, unsigned char *plaintext);

void handleErrors(void);