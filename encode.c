#include "ppm.h"

struct conv * dec2bind(int num)
{    
    int i = 7;
    struct conv * obj = (struct conv *)malloc(sizeof(struct conv));
    for(int j = 0;j < 8; j++)
    obj->bin[j] = 0;
    
    while(num > 0)
    {
        if(num % 2 == 0)
            obj->bin[i] = 0;
        else
            obj->bin[i] = 1;
        i--;
        num = num / 2;
    }
    
    return obj;

}

int bind2dec(struct conv * obj)
{
    
    int n = 0;
    int i;

    for (i = 0; i < 8; ++i) {
        n <<= 1;
        n += obj->bin[i] - 0;
    }

    return n;
}
int bind2dectest(int arr[])
{
    
    int n = 0;
    int i;

    for (i = 0; i < 8; ++i) {
        n <<= 1;
        n += arr[i] - 0;
    }

    return n;
}

struct PPM * encoder(struct PPM * img, char * message,unsigned int secret,int n)
{
     int mSize = strlen(message);
     srand(secret);
    int width,rando,sum = 0,row,column,o = 0,i = 0,k = 0,t = 0;
    int no_of_pixels = (int)ceil(mSize*8/(3*n));
    int msg_bin[8*mSize];
    struct conv * msg_char[mSize];
    for(int k = 0; k < mSize; k++) 
    {
        
        msg_char[k] = dec2bind(message[k]);
        for(int m = 0; m < 8; m++)
        {
            
            msg_bin[o] = msg_char[k]->bin[m]; 
            o++;
            
            
        }
        
    }
    
    while( i <= no_of_pixels)
    {
        rando = rand()%100;
        sum += rando;
        row = sum / (width);
        column = sum - (row * width);
        
        //get pixel
        struct pixel * p = &(img->p[row][column]);
        struct conv * red = dec2bind(p->r);
        struct conv * green = dec2bind(p->g);
        struct conv * blue = dec2bind(p->b);
        i++;
        for(int j = n -1; j >= 0;j--)
        {
            
            if(k > 8*mSize)break;
            else
            {
                red->bin[7-j]  = msg_bin[k];
                k++;
                
            }
            
            
        }
        for(int j = n -1; j >= 0;j--)
        {
            
            if(k > 8*mSize)break;
            else
            {
                green->bin[7-j]  = msg_bin[k];
                k++;
                
            }
            
            
        }
        for(int j = n -1; j >= 0;j--)
        {
            if(k > 8*mSize)break;
            else
            {
                blue->bin[7-j]  = msg_bin[k];
                k++;
                
            }
          
        }
        p->r = bind2dec(red);
        p->g = bind2dec(green);
        p->b = bind2dec(blue);
        //img ->p[row][column] = &p;
        
        
    }
    for(int s = 0; s < 8*mSize; s++)
        {
            printf("%d",msg_bin[s]);
            
            
            
            
        }
       
        
        return img;
    
    
    
    
}
    


char * decode(struct PPM * img, unsigned int secret,int n,int mSize)
{
    srand(secret);
    int width,rando,sum = 0,row,column,i = 0,k = 0,p = 0;
    int no_of_pixels = (int)ceil(mSize*8/(3*n));
    int buffer[8*mSize];
    
    while(i <= no_of_pixels)
    {
        
        rando = rand()%100;
        sum += rando;
        row = sum / (width);
        
        column = sum - (row * width);
        printf("%d %d\n",row,column);
        //get pixel
        struct pixel * p = &(img->p[row][column]);
        struct conv * red = dec2bind(p->r);
        struct conv * green = dec2bind(p->g);
        struct conv * blue = dec2bind(p->b);
        i++;
        for(int j = n -1; j >= 0;j--)
        {
            
            buffer[k] =red->bin[7-j];
            k++;
            
            
        }
        for(int j = n -1; j >= 0;j--)
        {
            
            buffer[k] =green->bin[7-j];
            k++;
            
            
        }
        for(int j = n -1; j >= 0;j--)
        {
            
            buffer[k] =blue->bin[7-j];
            k++;
            
            
        }
        
      
    }
    for(int s = 0; s < 8*mSize; s++)
    {
        
        printf("%d",buffer[s]);
        
    }
    


    struct conv * msg_bin[mSize];
    int msg_no[mSize];
    char * str = (char *)malloc(sizeof(char) * mSize);
    struct conv * test;
    int temp[8],temp1;
    /*for(int r = 0; r < 8; r++)
    {
        temp[r] = buffer[r];
        
        
        
    }
    
    temp1 = bind2dec1(temp);
    printf("%d",temp1);*/

	return "asdf";

}


    
    
    
    
    

    
    
    
    
    
    
    
    
    
