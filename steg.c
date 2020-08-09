#include "ppm.h"
int main(int argc, char ** argv)
{
    
    if(argc < 3)
    {
        printf("wrong number of arguments");
        
    }   

    else
    {
        FILE * fin = fopen(argv[2], "r");
        struct PPM * img = getPPM(fin);
        showPPM(img);
        //if(argv[1][0] == 'e')encodeFile(argc,argv);
        //if(argv[1][0] == 'd')decodeFile(argc,argv);
        
        
    }
    
    
}

void showPPM (struct PPM * img){

        //print type
        printf("%s\n", img->type);

        //print text
        int j;
        struct comment * t = img->comment;
        printf("%s\n", img->comment->comment);
        for(j = 1; j<img->cn; j++){
                t = t->next;
                printf("%s\n", t->comment);
        }

        //print general info
        printf("%d\n", img->width);
        printf("%d\n", img->height);
        printf("%d\n", img->max);

        //print pixels
        int k,l;
        for(k=0; k<img->height; k++){
		for(l=0; l<img->width; l++){
                        struct pixel p = img->p[k][l];
                        printf("%i %i %i\n", p.r, p.g, p.b);
                }
        }
}


/* Utilizes the above readLine function to find the comments */
void getText(FILE * fin, struct PPM * img){
	char ch = fgetc(fin);
	while(ch == '#') //lines beginning with "#" character
	{
        ch = fgetc(fin);
		//ungetc(ch, fin);

/*		//get comment
		//char * line;
        

		//add comment to linked list
		if(img->cn == 0)
		{

			//no previous comments
            struct comment * current = img->comment;
			current = (struct comment * )malloc(sizeof(struct comment));
			fgets(current->comment,100,fin);
			img->cn = 1;
		}
		else
		{
			//previous comments
			int j;
			struct comment * current = img->comment;

			for(j=1;j<img->cn;j++)
            {
                current = current->next;
                current->next = (struct comment *)malloc(sizeof(struct comment));
                fgets(current->next->comment,100,fin);
            }
				
			 
			img->cn = img->cn + 1;
		}

		//move to next line
		ch = fgetc(fin);
	}

	//Restore to starting position
	ungetc(ch, fin);*/
}

void getPixels(FILE * fin, struct PPM * img){

	//allocate rows
	img->p = (struct pixel ** ) malloc(sizeof(struct pixel *) * img->height);

	int j,k;
	for(j=0;j<img->height;j++)
	{
		//allocate columns
		img->p[j] = (struct pixel * ) malloc(sizeof(struct pixel) * img->width);
		for (k=0;k<img->width;k++)
		{
			//get pixels for each
			fscanf (fin, "%d", &(img->p[j][k].r)); //get memory address
			fscanf (fin, "%d", &(img->p[j][k].g));
			fscanf (fin, "%d", &(img->p[j][k].b));
		}
	}
}


/* Return PPM image file from fin */
struct PPM * getPPM(FILE * fin){
        struct PPM * img = malloc(sizeof(struct PPM));
        
        //Type
        img->type = malloc(2*sizeof(char));
        img->type = "P3";

        img->cn = 0;
        getText(fin, img);
        
        //Size
        fscanf (fin, "%d", &img->width);
        fscanf (fin, "%d", &img->height);
        fscanf (fin, "%d", &img->max);

        //Pixels
        getPixels(fin, img);

        return img;
}
void writePPM(FILE * fin, struct PPM * img, const char *fileName){
	FILE *pfile = NULL;
	int x,y;

	pfile = fopen(fileName, "w");
	//fprintf(pfile, "%d\n %s\n %d %d\n %d\n", i->type, i->text, i->w, i->h, i->max);
	fprintf(pfile, "P3\n%s%d %d\n255\n",img->comment,img->width, img->height);

	for(x=0; x<img->height; x++) {
		for(y=0; y<img->width;y++){
			struct pixel p = img->p[x][y];
			fprintf(pfile, "%i %i %i \n", p.r, p.g, p.b);		}
	}
	fclose(pfile);
}
void encodeFile(int argc, char ** argv){
	char txt[PPM_MAXMESS];
	int n;
    FILE * fin = fopen(argv[2], "r");
	if(fin == NULL){
		fprintf(stderr," steg: Error - Unable to open the file '%s' .\n", argv[2]);
		exit(0);
	}

	struct PPM * img = getPPM(fin);

	//get txt
	printf("Message to Encode-> ");
	fgets(txt, PPM_MAXMESS, stdin);
    printf("Enter no. of LSBs ( 3 to 21)");
    scanf("%d",&n);
	
	printf("encoding in progress...\n");
    
	//encode ppm
	 img = encoder(img, txt,1234,n);
    printf("test");
    showPPM(img);
	//output ppm
	//fputc(showPPM, outFin);
	writePPM(fin, img, "modified.ppm");
	
}

void decodeFile(int argc, char ** argv){

	FILE * i1 = fopen(argv[2], "r");
	

	if(i1 == NULL){
		printf("steg: Error - File '%s' could not be opened. \n", argv[2]);
		exit(0);
	}

	//get files
	struct PPM * img = getPPM(i1);
	

	//get encoded txt
	char * str = decode(img,1234,3,9);

	//print txt
	printf("%s\n", str);
}

