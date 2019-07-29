 #include <stdio.h>
 #include <stdlib.h>
 #define STB_IMAGE_IMPLEMENTATION
 #include "stb_image.h"
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "stb_image_write.h"

void removecolor(long** blue,long** red,long** green,int colorno,int height,int width)//this function remove all user selected color shades 
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            switch(colorno)
            {
                case 1:
                {
                    if (red[i][j]>blue[i][j]&&red[i][j]>green[i][j])
                    {
                        red[i][j]=0;
                    }
                    break;
                }
                case 2:
                {
                    if (green[i][j]>blue[i][j]&&green[i][j]>red[i][j])
                    {
                        green[i][j]=0;
                    }
                    break;
                }
                case 3:
                {
                    if (blue[i][j]>red[i][j]&&blue[i][j]>green[i][j])
                    {
                        blue[i][j]=0;
                    }
                    break;
                }
            }
        }
    }
    FILE *blue_outfile = fopen("Q3_op_blue.dat", "w");// creating pointer to write new dat file for blue color
          if (blue_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *red_outfile = fopen("Q3_op_red.dat", "w");// creating pointer to write new dat file for red color
          if (red_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *green_outfile = fopen("Q3_op_green.dat", "w");// creating pointer to write new dat file for green color
          if (green_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fprintf(blue_outfile, "%ld,", blue[i][j]);// writing new data inside the Q3_op_blue.dat file
            fprintf(red_outfile, "%ld,", red[i][j]);// writing new data inside the Q3_op_red.dat file
            fprintf(green_outfile, "%ld,", green[i][j]);// writing new data inside the Q3_op_green.dat file
        }
        fprintf(blue_outfile, "%ld\n", blue[i][width-1]);// writing new data inside the Q3_op_blue.dat file
        fprintf(red_outfile, "%ld\n", red[i][width-1]);// writing new data inside the Q3_op_red.dat file
        fprintf(green_outfile, "%ld\n", green[i][width-1]);// writing new data inside the Q3_op_green.dat file
    }

}

void keepthiscoloronly(long** blue,long** red,long** green,int colorno,int height,int width)//this function keep all user selected color shades and remove all other color shades
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            switch(colorno)
            {
                case 1:
                {
                    if (red[i][j]>blue[i][j]&&red[i][j]>green[i][j])
                    {
                        green[i][j]=0;
                        blue[i][j]=0;
                    }
                    break;
                }
                case 2:
                {
                    if (green[i][j]>blue[i][j]&&green[i][j]>red[i][j])
                    {
                        blue[i][j]=0;
                        red[i][j]=0;
                    }
                    break;
                }
                case 3:
                {
                    if (blue[i][j]>red[i][j]&&blue[i][j]>green[i][j])
                    {
                        green[i][j]=0;
                        red[i][j]=0;
                    }
                    break;
                }
            }
        }
    }
    FILE *blue_outfile = fopen("Q3_op_blue.dat", "w");// creating pointer to write new dat file for blue color
          if (blue_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *red_outfile = fopen("Q3_op_red.dat", "w");// creating pointer to write new dat file for red color
          if (red_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *green_outfile = fopen("Q3_op_green.dat", "w");
          if (green_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fprintf(blue_outfile, "%ld,", blue[i][j]);// writing new data inside the Q3_op_blue.dat file
            fprintf(red_outfile, "%ld,", red[i][j]);// writing new data inside the Q3_op_red.dat file
            fprintf(green_outfile, "%ld,", green[i][j]);// writing new data inside the Q3_op_green.dat file
        }
        fprintf(blue_outfile, "%ld\n", blue[i][width-1]);// writing new data inside the Q3_op_blue.dat file
        fprintf(red_outfile, "%ld\n", red[i][width-1]);// writing new data inside the Q3_op_red.dat file
        fprintf(green_outfile, "%ld\n", green[i][width-1]);// writing new data inside the Q3_op_green.dat file
    }
}


void pixelvalue(long** blue,long** red,long** green,int x,int y)//this function show red green blue(rgb) values at a particular cordinates given by the user
{
    printf("pixelvalues at this cordinate:\n");
    printf("%ld ",red[x-1][y-1]);
    printf("%ld ",green[x-1][y-1]);
    printf("%ld ",blue[x-1][y-1]);
}
int main(int argc, char const *argv[])//main function
{
	int width, height, channels;
    int n;
	stbi_info("Q3_ip.jpg", &width, &height, &channels);// finding the details of the image by using stbi_info function
	int noofpixels=width*height;
    int colorno;
    long *blue[height]; // creating a 2d dynamic array for blue pixel values
    for (int i=0; i<height; i++) 
         blue[i] = (long *)malloc(width * sizeof(long));
    long *red[height]; // creating a 2d dynamic array for red pixel values
    for (int i=0; i<height; i++) 
         red[i] = (long *)malloc(width * sizeof(long));  
    long *green[height]; // creating a 2d dynamic array for green pixel values
    for (int i=0; i<height; i++) 
         green[i] = (long *)malloc(width * sizeof(long)); 
	FILE *blue_infile  = fopen("Q3_ip_Blue.dat", "r");// creating pointer to retrieve pixel values from the Q3_ip_Blue.dat file
          if (blue_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            } 
	FILE *red_infile  = fopen("Q3_ip_Red.dat", "r");// creating pointer to retrieve pixel values from the Q3_ip_Red.dat file
          if (red_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            } 
	FILE *green_infile  = fopen("Q3_ip_Green.dat", "r");// creating pointer to retrieve pixel values from the Q3_ip_Green.dat file
          if (green_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            }            
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fscanf(blue_infile, "%ld,", &blue[i][j]);//retrieving pixel values from the Q3_ip_Blue.dat file
            fscanf(red_infile, "%ld,", &red[i][j]);//retrieving pixel values from the Q3_ip_Red.dat file
            fscanf(green_infile, "%ld,", &green[i][j]);//retrieving pixel values from the Q3_ip_Green.dat file
        }
            fscanf(blue_infile, "%ld", &blue[i][width-1]);//retrieving pixel values from the Q3_ip_Blue.dat file
            fscanf(red_infile, "%ld", &red[i][width-1]);//retrieving pixel values from the Q3_ip_Red.dat file
            fscanf(green_infile, "%ld", &green[i][width-1]);//retrieving pixel values from the Q3_ip_Green.dat file
    }
    while(1){
        printf("press 1 for remove all red shades\n");
        printf("press 2 for remove all green shades\n");
        printf("press 3 for remove all blue shades\n");
        printf("press 4 for preserve only red shades\n");
        printf("press 5 for preserve only green shades\n");
        printf("press 6 for preserve only blue shades\n");
        printf("press 7 for display pexelvalues at x,y cordinate\n");
        printf("press 8 for exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                removecolor(blue,red,green,1,height,width);// calling removecolor function to removing red shades
                printf("\n");
                break;
            }
            case 2:
            {
                removecolor(blue,red,green,2,height,width);// calling removecolor function to removing green shades
                printf("\n");
                break;
            }

            case 3:
            {
                removecolor(blue,red,green,3,height,width);// calling removecolor function to removing blue shades
                printf("\n");
                break;
            }
            case 4:
            {
                keepthiscoloronly(blue,red,green,1,height,width);//calling keepthiscoloronly function to preserving red shades only
                printf("\n");
                break;
            }

            case 5:
            {
                keepthiscoloronly(blue,red,green,2,height,width);//calling keepthiscoloronly function to preserving green shades only
                printf("\n");
                break;
            }
            case 6:
            {
                keepthiscoloronly(blue,red,green,3,height,width);//calling keepthiscoloronly function to preserving blue shades only
                printf("\n");
                break;
            }
            case 7:
            {
                long x,y;
                printf("enter the cordinate values\n");
                printf("value of x:\n");
                scanf("%ld",&x);
                printf("value of y:\n");
                scanf("%ld",&y);
                pixelvalue(blue,red,green,x,y);// calling pixelvalue function pixel values at given cordinate 
                printf("\n");
                break;
            }
            case 8:
            {
                exit(0);
                break;
            }

            default:
            {
                printf("please enter value from the above values\n");
                break;
            }

        }
    }
	return 0;
}